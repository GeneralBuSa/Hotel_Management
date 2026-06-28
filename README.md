# 🏨 Hotel Management System
## 📌 Project Overview
This project aims to manage the operations of a hotel, including room status updates, saving and loading the hotel's status, and providing room availability information. The system uses object-oriented principles to simulate room management with different types of rooms and functionalities.

## 📂 Dataset
This project doesn't use a dataset but instead uses a predefined set of rooms. The hotel contains both Suit Rooms and Standard Rooms. The statuses of these rooms (Available, Engaged, Cleaning) are managed by the system.

## 🔧 Steps Taken
1-Room Management
Created classes to represent different types of rooms (Suit Rooms and Standard Rooms).
Implemented functionality to update room statuses and display room details.
2-Data Persistence
Implemented saving and loading of hotel status to/from a file to maintain room statuses.
3-User Interface
Built a simple text-based menu system to interact with the hotel management system, including showing room statuses, updating statuses, searching/filtering rooms, and saving/loading data.
4-Room Types
Handled two types of rooms:
Suit Rooms (S): Luxurious rooms with more advanced features.
Standard Rooms (R): Basic rooms for regular stays.

## 🚀Getting Started
To use the system, simply compile and run the program. Once launched, you will be presented with a simple menu to select your desired action:

Show Rooms: View the current status of each room.
Update Room Status: Change the status of a room (e.g., from "Available" to "Engaged").
Save Hotel Status to File: Save the room statuses to a file for later use.
Load Hotel Status from File: Retrieve the saved room statuses from a file.
Search and Filter Rooms: Filter rooms by status, type, or price.
Exit: Close the program.

## 📌 How to Compile & Run
```bash
# Compile
g++ -o hotel hotel.cpp

# Run
./hotel
```

```
 --- Hotel Management System ---
1. Show Rooms
2. Update Room Status
3. Save Hotel Status to File
4. Load Hotel Status from File
5. Search and Filter Rooms
0. Exit
Enter your choice: 1

Room Statuses:
Room S1 (Suit - 500 TL): Available
Room S2 (Suit - 500 TL): Available
Room R1 (Standard - 200 TL): Available
... 
```
---
## File Operations
The program saves the room statuses to a file named hotel_status.txt and retrieves them when needed. This allows the program to retain room status information even after it is closed. The program also automatically saves hotel status when exiting.
