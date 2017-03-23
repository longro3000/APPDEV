<?php
$value = $_POST['value'];
$from = $_POST['from'];
$ip = $_SERVER['REMOTE_ADDR'];
echo "your value = ".$value." from = ".$from.". And your IP address is ".$ip."\n";
$today=date("Y-m-d H:i:a");
$file = "curltest.log";
if (file_exists($file))
	{
		$fp = fopen($file, "a");
	}
else
	{
		$fp=fopen($file,"w");
	}
$record = $today.",".$from.",".$ip.",".$value."\n";
fwrite($fp,$record);
fclose($fp);
?>