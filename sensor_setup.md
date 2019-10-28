# Sensor setup
The pH sensor that I used was from DF Robot. It comes with a decent amount of documentation of its own, but it is meant for Arduino. To set it up with Particle Photon is not very different. To set it up, use electrical wires to connect the sensor in to the Photon using this electrical diagram. The download link for the electrical diagam .fzz file is [here](https://github.com/malikmayank/hydroponic/blob/caitlin/phsensor_photon.fzz).

<img src="pHSensorCloseUp.png" width="1000">
<img src="pHSensor.png" width="1000">

Next, to get readings from the sensor, you will need to run a simple program. Go to the [Particle IDE](https://build.particle.io/build). You will be running the code from my file [pHRead.ino](https://github.com/malikmayank/hydroponic/blob/caitlin/pHRead.ino), which will display the data from the sensor every 5 seconds. When runing this code, take off the cap of the pH sensor and place it in a liquid that you want to measure, such as water. 

To callibrate your sensor, you will need to test the readings of multiple different liquids with known pH's, such as water, dish soap, tea, and vinegar. Once you have some data, divide the sensor reading of each liqud by the expected pH for that liquid. Average out these numbers to determine what to divide your sensor reading by. My numbers averaged out to about 350. So, in my final program, I divided the sensor reasings by 350 to get the pH.
