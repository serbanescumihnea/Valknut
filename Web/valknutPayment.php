
<script>

var $_GET = {};
if(document.location.toString().indexOf('?') !== -1) {
    var query = document.location
                   .toString()
                   .replace(/^.*?\?/, '')   
                   .replace(/#.*$/, '')
                   .split('&');

    for(var i=0, l=query.length; i<l; i++) {
       var aux = decodeURIComponent(query[i]).split('=');
       $_GET[aux[0]] = aux[1];
    }
}

</script>
<html>

    



    <head>
        <link rel="stylesheet" href="valknutPayment.css">
    </head>

    <body>
        <img  class="logo" src="logo.png">
        <p class="title">Payment</p>
        
        <div class="instructions">
        <p style="margin-left: 27%;">Send 0.013BTC ( 500 EUR ) </p>
        <p>bc1q 2slt z587 ntkm edf5 xdc5 zlfg p6ql mnwh 3r0f e3</p>
    </div>
    <button type="button" onclick="location.href='process.php?decID='+$_GET['decID']+'&&method=1'">Paid</button>
        <img class="qr" src="btcQR.jpg">
        
    </body>

</html>