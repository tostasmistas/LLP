<?php
include('login.php'); // Includes Login Script

if(isset($_SESSION['login_user'])){
header("location: profile.php");
}
?>
<!DOCTYPE html>
<html>
  <head>
    <title>Watchdog : Login</title>
    <meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
    <link href="assets/css/main.css" rel="stylesheet">
  </head>
  <body>

    <!-- Header -->
      <header id="header" class="alt">
        <h1><a href="index.html">Watchdog</a></h1>
        <nav id="nav">
          <ul>
            <li class="special">
              <a href="#menu" class="menuToggle"><span>Menu</span></a>
              <div id="menu">
                <ul>
                  <li><a href="index.html">Home</a></li>
                    <!--<li><a href="generic.html">Generic</a></li>
                  <li><a href="elements.html">Elements</a></li>
                  <li><a href="#">Sign Up</a></li>-->
                  <li><a href="index_login.php">Log In</a></li>
                </ul>
              </div>
            </li>
          </ul>
        </nav>
      </header>

    <div id="main">
    <div id="login">
    <h2>Login Form</h2>
    <form action="" method="post">
      <input id="name" name="username" placeholder="Clinic Name" type="text">
      <br>
      <input id="password" name="password" placeholder="Password" type="password">
      <br>
      <input name="submit" type="submit" value=" Login ">
      <span><?php echo $error; ?></span>
    </form>
    </div>
    </div>

    <!-- Scripts -->
      <script src="assets/js/jquery.min.js"></script>
      <script src="assets/js/jquery.scrollex.min.js"></script>
      <script src="assets/js/jquery.scrolly.min.js"></script>
      <script src="assets/js/skel.min.js"></script>
      <script src="assets/js/util.js"></script>
      <!--[if lte IE 8]><script src="assets/js/ie/respond.min.js"></script><![endif]-->
      <script src="assets/js/main.js"></script>

  </body>
</html>
