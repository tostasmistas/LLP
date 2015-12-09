<?php
include('login.php'); // Includes Login Script

if(isset($_SESSION['login_user'])){
  header("location: profile.php");
}
?>
<!DOCTYPE html>
<html>
  <head>
    <title>GeniePet : Login</title>
    <meta charset="utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
    <link href="assets/css/main.css" rel="stylesheet">
  </head>
  <body class="landing" style="background-color: #2E3842">
    <!-- Page Wrapper -->
      <div id="page-wrapper">

    <!-- Header -->
      <header id="header" class="">
        <h1><a href="index.html">GeniePet</a></h1>
        <nav id="nav">
          <ul>
            <li class="special">
                <a href="index_login_pt.php" style="padding: 0 0">PT</a>
            </li>
            <li class="special">
                <a href="" style="padding: 0 0; cursor: default">/</a>
            </li>
            <li class="special">
                <a href="index_login.php" style="padding: 0 0">ENG</a>
            </li>
            <li class="special">
              <a href="#menu" class="menuToggle"><span>Menu</span></a>
              <div id="menu">
                <ul>
                  <li><a href="index.html">Home</a></li>
                    <!--<li><a href="generic.html">Generic</a></li>
                  <li><a href="elements.html">Elements</a></li>
                  <li><a href="#">Sign Up</a></li>-->
                  <li><a href="index_login.php">Login</a></li>
                </ul>
              </div>
            </li>
          </ul>
        </nav>
      </header>

    <p class = "noselect">you can't see me</p>

    <!-- One -->
    <section class="wrapper style2 special" style="background-color:#2E3842">
      <div id="main">
        <div id="login">
        <form action="" method="post">
          <input style="margin:auto; width:50%" name="username" placeholder="Clinic Name" type="text">
          <br>
          <input style="margin:auto; width:50%" name="password" placeholder="Password" type="password">
          <br>
          <input name="submit" type="submit" value="Login">
          <span><?php echo $error; ?></span>
        </form>
        </div>
      </div>
    </section>
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
