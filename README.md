# ECSE3038_lab4
Controlling LEDs using Arduino and HTTP

# Lab 4

## Controlling LEDs using Arduino and HTTP

In this assignment, you will use an ESP32 board to control the state of three LEDs by making a GET request to a server and using the response to set the LED states.

### Set up the circuit

Connect three LEDs to digital output pins on the ESP32 board. Use a resistor for each LED to limit the current and prevent damage to the LEDs.

The API has already been built for you and can be accessed at the following URL:

```
https://ecse-three-led-api.onrender.com
```

### User Input

You’ll be allowed to change the desired state of each of the three LEDs by using this [tester site](https://ecse-three-led.netlify.app/). The site should determine the behaviour of your circuit by toggling each of the three light switches. 

Note the assigned username in the top left corner of the webpage. This is a unique identifier and should be included in your GET requests to the API as an API key.

This ensures that each person is able to control their own circuit.

The API expects a GET request to include an API key in the request headers:

```
GET /api/state HTTP/1.1
Host: https://ecse-three-led-api.onrender.com
X-API-Key: {username}
```

### Write the Arduino sketch

Use the relevant libraries to connect to the API and send a GET request to the `/api/state` route. 

Parse the JSON response to extract the LED states, and use the `digitalWrite()` function to set the LED states in the circuit.

### Test the system

Verify that the ESP32 sketch can successfully communicate with the server and control the LED states.

THE ABOVE PROCEDURE WAS CAREFULLY FOLLOWED AND EXCECUTED. 

***JOKE OF DAY***

How did a good lecturer such as Mr Phillip Logan know how to teach IoT to the inpatient students? He taught them bit by bit!
