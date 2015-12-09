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
String data_object;

Process process;
Servo servo; 

char buffer[80];

void setup(){
  // Bridge communication
  Bridge.begin();
  Console.begin();  
  while( !Console ) {;} 
}

void loop(){

  request_count();
  wait();
  counter = response_count();
  Console.print("count: ");
  Console.print(counter);

  if(counter == 1) {
    // query object
    request_object();
    wait(); 
    int gramas = response_gramas(); 
    Console.print("\t"); 
    Console.print("gramas: ");
    Console.print(gramas);

    // rotate servo
    servo.attach(9);  // attach the servo on pin 9 to the servo object
    servo.write(80);   
    delay(2000);
    servo.detach();
    delay(2000);

    Console.print("\t");
    Console.print("servo!");

    // delete object
    String objid = response_objid();
    Console.print("\t"); 
    Console.print("obj_id: ");
    Console.println(objid);
    delete_object(objid);
    
    counter = 0;
    data_object = "";
  }

  Console.println();
  
 /* for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
*/
  /*for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }*/
}

 // Curl request per Parse.com documentation
  /*
  curl -X POST \
  -H "X-Parse-Application-Id: APPLICATION_ID" \
  -H "X-Parse-REST-API-Key: REST_API_KEY" \
  -H "Content-Type: application/json" \
  -d '{"reading":123}' \
  https://api.parse.com/1/classes/Temperature  
  */ 

void request_count(){
  /*
  curl -X GET \
  -H "X-Parse-Application-Id: sUy0cU3xcYRqJ7CTeaOsvdvbMUaIHx4fWHmlxJVc" \
  -H "X-Parse-REST-API-Key: 1uEpZbxJWB7SNhCykj3U3lPXvzcCYnGJWwneSE7D" \
  -G \
  --data-urlencode 'where={"playerName":"Jonathan Walsh"}' \
  --data-urlencode 'count=1' \
  --data-urlencode 'limit=0' \
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
  sprintf( buffer, "count=1" );
  process.addParameter( buffer );
  process.addParameter( "--data-urlencode" );
  sprintf( buffer, "limit=0" );
  process.addParameter( buffer );
 
  // URI
  sprintf( buffer, "https://%s/%s/classes/%s", PARSE_API, PARSE_VERSION, PARSE_CLASS );
  process.addParameter( buffer );  

  // Run the command 
  // Synchronous
  process.run();
}


void request_object(){
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

void delete_object(String obj_id){
  /*
  curl -X DELETE \
  -H "X-Parse-Application-Id: sUy0cU3xcYRqJ7CTeaOsvdvbMUaIHx4fWHmlxJVc" \
  -H "X-Parse-REST-API-Key: 1uEpZbxJWB7SNhCykj3U3lPXvzcCYnGJWwneSE7D" \
  https://api.parse.com/1/classes/GameScore/Ed1nuqPvcm
  */

  // Build curl command line
  // Includes HTTPS support
  // POST
  // JSON
  process.begin( "curl" );
  process.addParameter( "-k" );
  process.addParameter( "-X" );
  process.addParameter( "DELETE" );
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
  
  // URI
  sprintf( buffer, "https://%s/%s/classes/%s/", PARSE_API, PARSE_VERSION, PARSE_CLASS);
  String id = buffer + obj_id;
  process.addParameter( id );  

  // Run the command 
  // Synchronous
  process.run();
}

int response_count(){
  char c;
  String data_count;
  
  // While there is data to read
  while( process.available( )){
    // Get character
    c = process.read();
    data_count += c;
  }
  
  int first_index = data_count.indexOf('}');
  String s_count = data_count.substring(first_index-1, first_index);
  int count = s_count.toInt();

  return count;
}

int response_gramas(){
  bool print = true;
  char c;
  
  // While there is data to read
  while( process.available( )){
    // Get character
    c = process.read();
    data_object += c;
  }
  
  int first_index = data_object.indexOf('g');
  int last_index = data_object.indexOf('o');
  String s_gramas = data_object.substring(first_index+8, last_index-2);
  int gramas = s_gramas.toInt();

  return gramas;
}

String response_objid(){
  bool print = true;
  char c;
  
  int first_index = data_object.indexOf('o');
  int last_index = data_object.lastIndexOf('u');
  String s_objid = data_object.substring(first_index+11, last_index-3);

  return s_objid;
}

// wait for a response from Parse.com
void wait(){
  // Periodically check curl process
  while( !process.available() ){
    delay(100);
  }
}

