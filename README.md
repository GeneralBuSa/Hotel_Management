🏨 Hotel Management System
📌 Project Overview
This project aims to manage the operations of a hotel, including room status updates, saving and loading the hotel’s status, and providing room availability information. The system uses object-oriented principles to simulate room management with different types of rooms and functionalities.

📂 Dataset
This project doesn't use a dataset but instead uses a predefined set of rooms. The hotel contains both Suit Rooms and Standard Rooms. The statuses of these rooms (Available, Occupied, Cleaning) are managed by the system.

🔧 Steps Taken
1-Room Management
Created classes to represent different types of rooms (Suit Rooms and Standard Rooms).
Implemented functionality to update room statuses and display room details.
2-Data Persistence
Implemented saving and loading of hotel status to/from a file to maintain room statuses.
3-User Interface
Built a simple text-based menu system to interact with the hotel management system, including showing room statuses, updating statuses, and saving/loading data.
4-Room Types
Handled two types of rooms:
Suit Rooms (S): Luxurious rooms with more advanced features.
Standard Rooms (R): Basic rooms for regular stays.

🚀Getting Started
To use the system, simply run the program. Once launched, you will be presented with a simple menu to select your desired action:

Show Rooms: View the current status of each room.
Update Room Status: Change the status of a room (e.g., from "Available" to "Occupied").
Save Hotel Status to File: Save the room statuses to a file for later use.
Load Hotel Status from File: Retrieve the saved room statuses from a file.
Exit: Close the program.

📌
 --- Hotel Management System ---
1. Show Rooms
2. Update Room Status
3. Save Hotel Status to File
4. Load Hotel Status from File
0. Exit
Enter your choice: 1
Room Status:
Room S1: Available
Room S2: Available
Room R1: Available
...

Code Structure
Classes
Room: A base class for representing rooms, containing details such as the room number and status.
SuitRoom: A derived class that represents suit rooms, inheriting from the Room class.
StandardRoom: A derived class that represents standard rooms, also inheriting from the Room class.
Hotel: A class responsible for managing the rooms. It provides functions to display room statuses, update them, and save/load to/from a file.
File Operations
The program saves the room statuses to a file named hotel_status.txt and retrieves them when needed. This allows the program to retain room status information even after it is closed.
