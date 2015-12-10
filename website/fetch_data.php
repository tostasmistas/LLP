<html>
  <head>
    <title>Transfer Devices</title>
  </head>
  <body>
<?php
  require 'autoload.php';
  ParseClient::initialize( sUy0cU3xcYRqJ7CTeaOsvdvbMUaIHx4fWHmlxJVc, 1uEpZbxJWB7SNhCykj3U3lPXvzcCYnGJWwneSE7D, wdEcnZGIN6cZtAYUFv3oniWdfWhYvQrZAD2tdc81 );

  use Parse\ParseObject;
  use Parse\ParseQuery;
  use Parse\ParseACL;
  use Parse\ParsePush;
  use Parse\ParseUser;
  use Parse\ParseInstallation;
  use Parse\ParseException;
  use Parse\ParseAnalytics;
  use Parse\ParseFile;
  use Parse\ParseCloud;
  use Parse\ParseClient;

  $query = new ParseQuery("calorieLog");
  $query->equalTo("gramms", "25");
  $results = $query->find();
  echo("Successfully retrieved " . count($results) . " calories.");
  // Do something with the returned ParseObject values
  for ($i = 0; $i < count($results); $i++) {
    $object = $results[$i];
    echo $object->getObjectId() . ' - ' . $object->get('calories');
  }
?>
  </body>
</html>
