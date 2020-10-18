import time
import os
import requests

URL = "api.openweathermap.org/data/2.5/weather"

# location given here
location = "delhi"

key1 = "62a10c0944a1c19ac7611b8f58d24083"
# defining a params dict for the parameters to be sent to the API
PARAMS = {:location, 'appid':key1}

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

num_seconds = 3
for countdown in reversed(range(num_seconds + 1)):
    if countdown > 0:
        print(countdown, end='...')
        time.sleep(1)
    else:
        print('Go!')
