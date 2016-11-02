<?php
//Tell PHP that we're using UTF-8 strings
mb_internal_encoding('UTF-8');

//Tell PHP that we're outputting UTF-8 to the browser
mb_http_output('UTF-8');

//Our UTF-8 test string
$string = 'Êl síla erin lû e-govaned vîn.';

//Transform the string in some way with a multibyte func
//Note string is cut at non-ASCII char
$string = mb_substr($string, 0, 15);

//Connect to db to store new string
//Note 'charset=utf8mb4' in the Data Storage Name (DSN)
$link = new PDO(
	'mysql:host=hostess-mostest;dbname=da-bomb-diggity;charset=utf8mb4',
	'username',
	'password',
	array(
		PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
		PDO::ATTR_PERSISTENT => false
	)
);

//Store transformed string in db as utf-8
//ensure tables and db encoded as utf8mb4
$handle = $link->prepare('insert into QuenyaSentences (Id, Body) values (?, ?)');
$handle->bindValue(1, 1, PDO::PARAM_INT);
$handle->bindValue(2, $string);
$handle->execute();

//Retrieve Quenya string to ensure correctly stored
$handle = $link->prepare('select * from QuenyaSentences where Id = ?');
$handle->bindValue(1, 1, PDO::PARAM_INT);
$handle->execute();

$result = $handle->fetchAll(\PDO::FETCH_OBJ);

header('Content-Type: text/html; charset=UTF-8');
?><!doctype html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>UTF-8 test page</title>
	</head>
	<body>
		<?php
		foreach($result as $row){
			print($row->Body); //outputting our utf8 string to browser
		}
		?>
	</body>
</html>
