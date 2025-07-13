import requests

# sends commands to the Flask API and prints the response output
def sendCommands(commands):
    
    url = "http://localhost:5000/run"
    payload = {"commands": commands}
    response = requests.post(url, json=payload)

    if response.status_code == 200:
        print(response.json()["output"])  
    else:
        print("Error:", response.status_code, response.text)

# entry point of commands
if __name__ == "__main__":
    commands = input("->: ").upper()
    sendCommands(commands)
