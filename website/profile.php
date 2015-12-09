<?php
include('session.php');
?>
<!DOCTYPE html>
<html>
  <head>
    <title>Clinic Area</title>
    <link href="assets/css/main.css" rel="stylesheet">
  </head>

<body>
<div id="profile">
<b id="welcome">Welcome : <i><?php echo $login_session; ?></i></b>

<br>

<b id="vaccine"><a href="http://192.168.43.190/arduino/digital/13/1">vaccine</a></b>
<br>
<b id="general appointment"><a href="http://192.168.43.190/arduino/digital/12/1">general appointment</a></b>

<br>

<b id="logout"><a href="logout.php">Logout</a></b>
</div>
</body>
</html>
