# Coding Challenge 1: Truck Robot

## My Solution

For this challenge, I chose to implement the core robot logic in C++ using Object-Oriented Programming principles. The main entities are:

- **Table class:** Represents the playing field with boundaries and validation logic to check if the robot's position is on the table.
- **Truck class:** Models the robot truck, encapsulating its position, facing direction, and behavior (move, turn left/right, report).

Commands are processed in a structured manner, ensuring invalid moves or placements are ignored to prevent the robot from falling off the table. Exception handling is used to enforce valid initial placements.

The program accepts command sequences as arguments and executes them in order, updating the robot's state accordingly.

## API Implementation

To meet the stretch goal of providing a REST API interface, I implemented a Flask server in Python that acts as a bridge between users and the C++ robot logic. This server exposes a `/run` endpoint which accepts POST requests with commands in JSON format.

The Flask server:

- Receives commands from clients,
- Invokes the C++ executable with those commands as arguments,
- Captures and returns the output as JSON.

Additionally, I developed a small Python CLI client script that:

- Prompts the user for commands,
- Sends these commands to the Flask server via REST API calls,
- Displays the robot’s response to the user similar to the example output.

## How to Run

1. **Start the Flask API server**

   Run the Flask app (`app.py`):

   ```bash
   python app.py

2. **Run the Python CLI client**

   In a new terminal, from the restApi folder, run:
   
   ```bash
   python apiClient.py
   ```
   You will be prompted to enter commands like:
   ```bash
   ->: PLACE 1,2,EAST MOVE MOVE LEFT MOVE REPORT
   ```

3. **See the Results**
   
   The client sends commands to the REST API, which runs the pre-built C++ executable located in the build folder, then returns the output for display.
