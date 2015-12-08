// Libraries
#include <Process.h>
#include <Servo.h>

// Constants
const char *PARSE_API = "api.parse.com";
const char *PARSE_APP = "sUy0cU3xcYRqJ7CTeaOsvdvbMUaIHx4fWHmlxJVc";
const char *PARSE_CLASS = "calorieLog";
const char *PARSE_KEY = "1uEpZbxJWB7SNhCykj3U3lPXvzcCYnGJWwneSE7D";
const char *PARSE_VERSION = "1";

// Variables
int counter = 0;
int pos = 0;    // variable to store the servo position

Process process;
Servo servo; 

char buffer[80];

// Setup
void setup(){
  // Bridge communication
  Bridge.begin();
  Console.begin();  
  while( !Console ) {;} 
}

// Loop
void loop(){

  request();
  wait();
  int gramas = response(); 
  Console.print("gramas: ");
  Console.println(gramas); 
  
  servo.attach(9);  // attach the servo on pin 9 to the servo object
  servo.write(80);   
  delay(2000);
  servo.detach();
  delay(2000);
    
 /* for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
*/
  //servo.detach();
  
  /*for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }*/
}

// Send the data to Parse.com
void request(){
  // Curl request per Parse.com documentation
  /*
  curl -X POST \
  -H "X-Parse-Application-Id: APPLICATION_ID" \
  -H "X-Parse-REST-API-Key: REST_API_KEY" \
  -H "Content-Type: application/json" \
  -d '{"reading":123}' \
  https://api.parse.com/1/classes/Temperature  
  */  

  /*
  curl -X GET \
  -H "X-Parse-Application-Id: ${APPLICATION_ID}" \
  -H "X-Parse-REST-API-Key: ${REST_API_KEY}" \
  -G \
  --data-urlencode 'keys=score,playerName' \
  https://api.parse.com/1/classes/GameScore
  */

  // Build curl command line
  // Includes HTTPS support
  // POST
  // JSON
  process.begin( "curl" );
  process.addParameter( "-k" );
  process.addParameter( "-X" );
  process.addParameter( "GET" );
  //process.addParameter( "-H" );
  //process.addParameter( "Content-Type:application/json" );
 
  // Parse.com application
  process.addParameter( "-H" );
  sprintf( buffer, "X-Parse-Application-Id: %s", PARSE_APP );
  process.addParameter( buffer );
  
  // Parse.com key
  process.addParameter( "-H" );
  sprintf( buffer, "X-Parse-REST-API-Key: %s", PARSE_KEY );
  process.addParameter( buffer );  

  process.addParameter( "-G" );
 
  // JSON body
  process.addParameter( "--data-urlencode" );
  sprintf( buffer, "keys=%s", "gramms" );
  process.addParameter( buffer );
 
  // URI
  sprintf( buffer, "https://%s/%s/classes/%s", PARSE_API, PARSE_VERSION, PARSE_CLASS );
  process.addParameter( buffer );  

  // Run the command 
  // Synchronous
  process.run();
}

// Response from Parse.com
int response(){
  bool print = true;
  char c;
  String data;
  
  // While there is data to read
  while( process.available( )){
    // Get character
    c = process.read();
    data += c;

    /*
    // Print until newline
    if( c == '\n' ){
      print = false;
    }      
  
    // Not newline yet
    // Print to console
    if( print ){
      Console.print( c );
    }
    */
  }

  //Console.print(data);
  
  int first_index = data.indexOf('g');
  int last_index = data.indexOf('o');
  String s_gramas = data.substring(first_index+8, last_index-2);
  int gramas = s_gramas.toInt();

  return gramas;
}

// Wait for a response from Parse.com
void wait(){
  // Periodically check curl process
  while( !process.available() ){
    delay(100);
  }
}

