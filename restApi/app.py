from flask import Flask, jsonify, request

import subprocess


app = Flask(__name__)

# runs compiled C++ program with given commands
def runCpp(*args):
    
    result = subprocess.run(["build\myrobot.exe"] + list(args), text=True, capture_output=True)
    return result.stdout.strip()

# API endpoint for executing C++ commands
@app.route("/run", methods=["POST"])
def run():
    
    data = request.get_json()
    cmdArgs = data.get("commands")
    
    cmdList = cmdArgs.split()
    
    output = runCpp(*cmdList)
    return jsonify({"output" : output})
    
if __name__ == "__main__":

    app.run() 