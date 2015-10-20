<?php
// Establishing Connection with Server by passing server_name, user_id and password as a parameter
$connection = mysql_connect("db.ist.utl.pt", "ist173527", "yhyt5133");
// Selecting Database
$db = mysql_select_db("ist173527", $connection);
session_start();// Starting Session
// Storing Session
$user_check=$_SESSION['login_user'];
// SQL Query To Fetch Complete Information Of User
$ses_sql=mysql_query("SELECT clinic_name FROM Customer WHERE clinic_name='$user_check'", $connection);
$row = mysql_fetch_assoc($ses_sql);
$login_session =$row['clinic_name'];
if(!isset($login_session)){
mysql_close($connection); // Closing Connection
header('Location: index_login.php'); // Redirecting To Home Page
}
?>
