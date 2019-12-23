const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style>
.card{
    max-width: 400px;
     min-height: 250px;
     background: #02b875;
     padding: 30px;
     box-sizing: border-box;
     color: #FFF;
     margin:20px;
     box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
}
</style>
<body>
<img src="https://lh3.googleusercontent.com/tE9sHWsSeubGOoRDE4QsbRA4Y1AZvvKa3waWXiFvlRMDAbVSSTDmN5gJPbWbmdS1BwNDatoLaMyjyw2WdsM8PftJ22YxUJdfGHAb9M10iz-0xt1IPJtmJOaZLtjHek5fdUMT4uwuQIoGttTJjbbiob551avofwjriynGNTcMRIp46qtE-WaGqi6Y5wzlzqpQFx1XVppQo4Uv_1PYVMh2CsDc6OZurE6w52kyy7ZhIgx82_mzgOpyqxFPeKf__D-f-QicsgR6X-c8qN8kbxFsGSN5WU93FVxJH5cxAjOmq3UtqKPzomNjvmhKYhLK7B_HL1nc21v7QbPpiK618BYWWI2JROVGoeGcUbE463nWfsXVzzQaAYh9fVGmrRb5XxC6t-x-VY98Zvrlv16oE4LGPbGDgvLGbxntEp3hSBqHF1KLqdMghVkXrSWrtbhZuJvaDuWACnMZmQpKP2zmuZFdWNQ0xG-o-7VicHZArxfEIWr4f52-z-qC3E6J3PbUMonqhesw-TgwpTXLtmZ84G-bTCegzsm5FVd1CGkgStqGaMBKZ4OuCpY4olbEQq6rplnye5jz5_uO7Dt_s0VmujpBEuM7_tJXiU7nxNeUqzpjcVgG-ghgplT29t4N05L9X3ZA7Oi5glHTGAvH9jsLWAxB1-LfT3KuvQu5BIoAY7hyVjXx8osH475hqA=w399-h84-no">
<br>
<div class="card">
  <h1>Six-MAP ITB TUNER</h1><br>
  <h4>Cyl #1: <meter id="ADCBar0" min="0" max="1100"
         low="200" high="900"
         optimum="850" value="300"> </meter>   <span id="ADCValue0">0</span></h4> <br>
  <h4>Cyl #2: <meter id="ADCBar1" min="0" max="1100"
         low="200" high="900"
         optimum="850" value="300"> </meter>   <span id="ADCValue1">0</span></h4>  <br>
  <h4>Cyl #3: <meter id="ADCBar2" min="0" max="1100"
         low="200" high="900"
         optimum="850" value="300"> </meter>   <span id="ADCValue2">0</span></h4> <br>
  <h4>Cyl #4: <meter id="ADCBar3" min="0" max="1100"
         low="200" high="900"
         optimum="850" value="300"> </meter>   <span id="ADCValue3">0</span></h4> <br>
  <h4>Cyl #5: <meter id="ADCBar4" min="0" max="1100"
         low="200" high="900"
         optimum="850" value="300"> </meter>   <span id="ADCValue4">0</span></h4> <br>
  <h4>Cyl #6: <meter id="ADCBar5" min="0" max="1100"
         low="200" high="900"
         optimum="850" value="300"> </meter>   <span id="ADCValue5">0</span></h4> <br>
</div>
<script>

setInterval(function() {
  // Call a function repetatively with 0.2 Second interval
  getData();
}, 200); //2000mSeconds update rate

function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var response=this.responseText; // Respuesta del ESP con la info
      var datos=response.split("#");      //Respuesta parseada para separar los datos
      document.getElementById("ADCValue0").innerHTML = datos[0];
      document.getElementById("ADCBar0").value = datos[0];
      document.getElementById("ADCValue1").innerHTML = datos[1];
      document.getElementById("ADCBar1").value = datos[1];
      document.getElementById("ADCValue2").innerHTML = datos[2];
      document.getElementById("ADCBar2").value = datos[2];
      document.getElementById("ADCValue3").innerHTML = datos[3];
      document.getElementById("ADCBar3").value = datos[3];
      document.getElementById("ADCValue4").innerHTML = datos[4];
      document.getElementById("ADCBar4").value = datos[4];
      document.getElementById("ADCValue5").innerHTML = datos[5];
      document.getElementById("ADCBar5").value = datos[5];
    }
  };
  xhttp.open("GET", "readADC", true);
  xhttp.send();
}
</script>
</body>
</html>
)=====";
