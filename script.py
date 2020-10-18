import time
import os
import requests
import json

URL = "api.openweathermap.org/data/2.5/weather"
URL = "http://" + URL

# location given here
id1 = '1261481'

key1 = "62a10c0944a1c19ac7611b8f58d24083"
# defining a params dict for the parameters to be sent to the API
PARAMS = {'id' : id1 , 'appid' : key1 }

# sending get request and saving the response as response object
r = requests.get(url = URL,params= PARAMS)

# extracting data in json format
data = r.json()
print(data)


# extracting latitude, longitude and formatted address
# of the first matching location
'''latitude = data['results'][0]['geometry']['location']['lat']
longitude = data['results'][0]['geometry']['location']['lng']
formatted_address = data['results'][0]['formatted_address']


# printing the output
print("Latitude:%s\nLongitude:%s\nFormatted Address:%s"
      %(latitude, longitude,formatted_address))

os.system("g++ -o output.txt main.cpp")'''

Temperature = data['main']['temp']
print(Temperature)
Humidity = data['main']['humidity']
print(Humidity)
Wind = data['main']['pressure']
print(Wind)

os.system("g++ main.cpp -o o.exe")

Temperature = Temperature - 273

num_seconds = 3
for countdown in reversed(range(num_seconds + 1)):
    if countdown > 0:
        print(countdown, end='...')
        time.sleep(1)
    else:
        print('Go!')
os.system("o.exe " + str(Temperature) + " " + str(Humidity) + " " +  str(Wind) + ">>temp.txt")
#print("o.exe " + str(Temperature) + " " + str(Humidity) + ">>temp.txt")
f1 = open("temp.txt", "r")
text1 = f1.read()
#print(text1)
