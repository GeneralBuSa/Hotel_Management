# Hotel_Management
Hotel Management System
Welcome to the Hotel Management System! This program helps hotel administrators manage room statuses efficiently, allowing them to view, update, and save room information to files. The program supports different room types and provides functionality to track room availability, engagement status, and more.

Features
Display Rooms: View the current status of all rooms in the hotel.
Update Room Status: Update the status of rooms (Available, Engaged, Cleaning).
Save Hotel Status to File: Save the current room status to a text file.
Load Hotel Status from File: Load the previously saved room statuses from a text file.
Room Types
This system supports two types of rooms:

Suit Rooms (S): Premium rooms with luxurious amenities.
Standard Rooms (R): Regular rooms with essential amenities.
There are 50 rooms in total:

The first 25 rooms are Suit Rooms (S1, S2, ..., S25).
The next 25 rooms are Standard Rooms (R1, R2, ..., R25).
Getting Started
To use the system, simply run the program. Once launched, you will be presented with a simple menu to select your desired action:

Show Rooms: View the current status of each room.
Update Room Status: Change the status of a room (e.g., from "Available" to "Occupied").
Save Hotel Status to File: Save the room statuses to a file for later use.
Load Hotel Status from File: Retrieve the saved room statuses from a file.
Exit: Close the program.
Example Usage:
bash
Kopyala
Düzenle
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

Requirements
A C++ compiler (e.g., g++, Visual Studio).
Standard C++ libraries (<iostream>, <fstream>, <string>).
License
This project is open source and free to use. Feel free to modify and improve it according to your needs!

Feel free to explore and enjoy managing your hotel with this system!
This README provides clear instructions for using the system and describes its features in a polished and professional manner!
