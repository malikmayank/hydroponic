# Slack Integration

The Particle Photon has a lot of great tutoritals for its sensor kit [here](https://docs.particle.io/tutorials/hardware-projects/maker-kit). There is a tutorial there with a video for a conference room monitor that uses slack integrating that is pretty similar to this project. 

### Setting up Slack
1. Create the slack channel that you want to post messages in
2. Go to the settings of that channel and choose "add app or integration"
3. Search and select 'incoming webhook'
4. On the next page, choose 'add configuration', and choose the channel you just created
5. Copy your webhook URL, which you will need later. 
6. Name your webhook (I used pH Sensor)
7. Save

### Setting up Particle
1. Go to [Particle Console](http://console.particle.io/) integration tab, and create a new integration
2. Choose webhook
3. Name your webhook something like ph_sensor
4. Paste your slack URL that you copied during step 5 above
5. Go to the advanced settings and select 'custom' under JSON data.
6. Add code to display your message, such as: 
{
    "text": "The pH is {{PARTICLE_EVENT_VALUE}}."
}
7. Click 'create webhook'

After setting up the Slack integration, you can use the [pH sensor code](https://github.com/malikmayank/hydroponic/blob/master/water-ph.ino) to start getting pH readings on Slack!
