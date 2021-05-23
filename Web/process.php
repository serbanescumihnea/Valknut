<?php 

$serverName = "127.0.0.1";
$userName = "root";
$password = "";
$dbName = "computers";

$conn = new mysqli($serverName,$userName,$password,$dbName);

if($conn -> connect_error){
    die("Connection failed!" . $conn -> connect_error);
}

if($_GET["method"]==1){
    $x = $_GET["decID"];
$sql = "UPDATE registry SET status=1 WHERE id='{$x}'";
header("Location: valknut.php");
}else if($_GET["method"]==0){
    $x = $_GET["decID"];

    $sql1 = "SELECT id FROM registry WHERE id='{$x}'";
    $result = $conn->query($sql1);
    $row = $result->fetch_row();

    if(empty($row[0])){
        $sql = "INSERT INTO registry (id, status) VALUES ('{$x}','0')";
    }else{
        
    }




    
    header("Location: valknut.php");
}else if($_GET["method"]==2){
    $x = $_GET["decID"];
    $sql = "SELECT status  FROM registry WHERE id='{$x}'";
    $result = $conn->query($sql);
    $row = $result->fetch_row();
    //echo $row[0];

    if($row[0]==0){
    http_response_code(300);
    }else if($row[0]=1){
        http_response_code(301);
    }
}

if($conn->query($sql)=== TRUE){

}else{
    //echo "An error occured" . $conn->error; 
}

$conn->close();


?>