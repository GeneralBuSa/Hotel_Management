#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <limits>

using namespace std;

// Class representing customer details for room reservation (Rezervasyon yapan musteri bilgilerini tutan sinif)
class Customer {
private:
    string name;
    string phone;

public:
    Customer(const string& name, const string& phone) : name(name), phone(phone) {}
    string getName() const { return name; }
    string getPhone() const { return phone; }
};

// Base Room class representing common room features (Ortak oda ozelliklerini temsil eden temel Oda sinifi)
class Room {
protected:
    string roomNumber;
    string status;
    double price; // Price variable moved to base class (Fiyat degiskeni taban sinifa tasindi)
    unique_ptr<Customer> customer; // Holds customer details if room is engaged (Oda doluysa musteri detaylarini tutar)

public:
    Room(const string& number, const string& status, double price) : roomNumber(number), status(status), price(price), customer(nullptr) {}

    // Virtual destructor for proper polymorphic cleanup (Polimorfik yikim icin sanal yikici)
    virtual ~Room() {}

    void setStatus(const string& newStatus) {
        status = newStatus;
    }

    string getStatus() const {
        return status;
    }

    string getRoomNumber() const {
        return roomNumber;
    }

    void setPrice(double newPrice) {
        price = newPrice; // Update room price dynamically (Oda fiyatini dinamik olarak guncelle)
    }

    void setCustomer(unique_ptr<Customer> newCustomer) {
        customer = move(newCustomer); // Transfer ownership of the customer object (Musteri nesnesinin sahipligini tasi)
    }

    const Customer* getCustomer() const {
        return customer.get();
    }

    // Oda fiyatini doner
    double getPrice() const {
        return price;
    }

    // Pure virtual function to get the type of the room (Oda tipini donecek saf sanal fonksiyon)
    virtual string getType() const = 0;
};

// Class representing premium Suit Rooms (Premium Suit Odalari temsil eden sinif)
class SuitRoom : public Room {
public:
    SuitRoom(const string& number, const string& status) : Room(number, status, 500.0) {}
    string getType() const override {
        return "Suit";
    }
};

// Class representing Standard Rooms (Standart Odalari temsil eden sinif)
class StandardRoom : public Room {
public:
    StandardRoom(const string& number, const string& status) : Room(number, status, 200.0) {}
    string getType() const override {
        return "Standard";
    }
};

// Class representing the hotel and managing all rooms (Oteli temsil eden ve tum odalari yoneten sinif)
class Hotel {
private:
    static const int suitCount = 25;      // Suit oda sayisi
    static const int standardCount = 25;   // Standart oda sayisi
    static const int totalRooms = suitCount + standardCount;
    vector<unique_ptr<Room>> rooms; // Odalara akilli isaretciler tutan dinamik liste

public:
    // Yapici metot otel odalarini ilklendirir
    Hotel() {
        for (int i = 0; i < suitCount; ++i) {
            rooms.push_back(make_unique<SuitRoom>("S" + to_string(i + 1), "Available"));
        }
        for (int i = 0; i < standardCount; ++i) {
            rooms.push_back(make_unique<StandardRoom>("R" + to_string(i + 1), "Available"));
        }
    }

    // Helper function to print details of a single room (Tek bir oda detayini ekrana basan yardimci fonksiyon)
    void displayRoomDetails(const Room& room) const {
        cout << "Room " << room.getRoomNumber() << " (" << room.getType() << " - " << room.getPrice() << " TL): " << room.getStatus();
        if (room.getStatus() == "Engaged" && room.getCustomer() != nullptr) {
            cout << " - Customer: " << room.getCustomer()->getName() << " (" << room.getCustomer()->getPhone() << ")";
        }
        cout << endl;
    }

    // Prints status and details of all rooms (Tum odalarin durumlarini ve detaylarini ekrana basar)
    void displayRooms() const {
        cout << "\nRoom Statuses:" << endl;
        for (const auto& room : rooms) {
            displayRoomDetails(*room);
        }
    }

    // Filters and prints rooms based on status (e.g., Available, Engaged) (Odalari durumuna gore filtreler ve ekrana basar)
    void filterByStatus(const string& targetStatus) const {
        cout << "\n--- Rooms with Status: " << targetStatus << " ---" << endl;
        bool found = false;
        for (const auto& room : rooms) {
            if (room->getStatus() == targetStatus) {
                displayRoomDetails(*room);
                found = true;
            }
        }
        if (!found) cout << "No matching rooms found." << endl;
    }

    // Filters and prints rooms based on room type (Suit or Standard) (Odalari oda tipine gore filtreler ve ekrana basar)
    void filterByType(const string& type) const {
        cout << "\n--- Rooms of Type: " << type << " ---" << endl;
        bool found = false;
        for (const auto& room : rooms) {
            if (room->getType() == type) {
                displayRoomDetails(*room);
                found = true;
            }
        }
        if (!found) cout << "No matching rooms found." << endl;
    }

    // Filters and prints rooms with price below or equal to the limit (Belirlenen fiyat limitinin altindaki odalari filtreler ve basar)
    void filterByPrice(double maxPrice) const {
        cout << "\n--- Rooms with Price " << maxPrice << " TL and Below ---" << endl;
        bool found = false;
        for (const auto& room : rooms) {
            if (room->getPrice() <= maxPrice) {
                displayRoomDetails(*room);
                found = true;
            }
        }
        if (!found) cout << "No matching rooms found." << endl;
    }
   
    // Oda durumunu gunceller ve rezervasyonlar icin musteri verilerini yonetir
    void updateRoomStatus(const string& roomNumber, const string& newStatus) {
        // Gecerli durum kontrolu
        if (newStatus != "Engaged" && newStatus != "Available" && newStatus != "Cleaning") {
            cout << "Invalid status! Use: Engaged, Available, or Cleaning." << endl;
            return;
        }
        for (auto& room : rooms) {
            if (room->getRoomNumber() == roomNumber) {
                if (newStatus == "Engaged") {
                    string name, phone;
                    cout << "Customer Name: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, name);
                    if (name.empty()) {
                        cout << "Customer name cannot be empty!" << endl;
                        return;
                    }
                    cout << "Customer Phone: ";
                    getline(cin, phone);
                    if (phone.empty()) {
                        cout << "Customer phone cannot be empty!" << endl;
                        return;
                    }
                    room->setStatus(newStatus);
                    room->setCustomer(make_unique<Customer>(name, phone));
                } else {
                    room->setStatus(newStatus);
                    room->setCustomer(nullptr);
                }
                cout << "Room " << roomNumber << " status updated to " << newStatus << "." << endl;
                return;
            }
        }
        cout << "Room not found!" << endl;
    }

    // Saves current room statuses, types, prices and customer details to a text file (Mevcut oda durumlarini, tiplerini, fiyatlarini ve musteri detaylarini bir metin dosyasina kaydeder)
    void saveToFile() const {
        ofstream outFile("hotel_status.txt");
        if (outFile.is_open()) {
            for (const auto& room : rooms) {
                outFile << room->getRoomNumber() << " " << room->getType() << " " << room->getPrice() << " " << room->getStatus();
                if (room->getStatus() == "Engaged" && room->getCustomer() != nullptr) {
                    outFile << "\n" << room->getCustomer()->getName() << "\n" << room->getCustomer()->getPhone();
                }
                outFile << endl;
            }
            outFile.close();
            cout << "Hotel status saved to file." << endl;
        } else {
            cout << "Unable to open file!" << endl;
        }
    }

    // Oda durumlarini, tiplerini, fiyatlarini ve musteri detaylarini bir metin dosyasindan yukler
    void retrieveFromFile() {
        ifstream inFile("hotel_status.txt");
        if (inFile.is_open()) {
            string roomNumber, type, status;
            double price;
            while (inFile >> roomNumber >> type >> price >> status) {
                bool found = false;
                for (auto& room : rooms) {
                    if (room->getRoomNumber() == roomNumber) {
                        room->setPrice(price);
                        room->setStatus(status);
                        if (status == "Engaged") {
                            string name, phone;
                            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
                            getline(inFile, name);
                            getline(inFile, phone);
                            room->setCustomer(make_unique<Customer>(name, phone));
                        } else {
                            room->setCustomer(nullptr);
                        }
                        found = true;
                        break;
                    }
                }
                // Eslesmese bile Engaged ise musteri satirlarini atla
                if (!found && status == "Engaged") {
                    string skip;
                    inFile.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(inFile, skip);
                    getline(inFile, skip);
                }
            }
            inFile.close();
            cout << "Hotel status loaded from file." << endl;
        } else {
            cout << "Unable to open file or file not found!" << endl;
        }
    }
};

// Helper function to safely get integer choice input from terminal (Terminalden guvenli bir sekilde secim girdisi alan yardimci fonksiyon)
int getValidatedChoice() {
    int choice;
    while (!(cin >> choice)) {
        cin.clear(); // Clear input error flags (Girdi hata bayraklarini temizle)
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid characters (Gecersiz karakterleri yoksay)
        cout << "Invalid input! Please enter a number: ";
    }
    return choice;
}

// Main execution loop for the Hotel Management System (Otel Yonetim Sistemi icin ana dongu)
int main() {
    Hotel hotel;
    int choice = -1; 

    // Retrieve saved hotel state at the beginning (Baslangicta kaydedilmis otel durumunu yukle)
    hotel.retrieveFromFile();

    while (choice != 0) {
        cout << "\n --- Hotel Management System ---" << endl;
        cout << "1. Show Rooms" << endl;
        cout << "2. Update Room Status" << endl;
        cout << "3. Save Hotel Status to File" << endl;
        cout << "4. Load Hotel Status from File" << endl;
        cout << "5. Search and Filter Rooms" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        choice = getValidatedChoice();

        string roomNumber, newStatus;

        switch (choice) {
        case 1:
            hotel.displayRooms(); 
            break;
        case 2:
            cout << "Enter room number: ";
            cin >> roomNumber;
            cout << "Enter new status (Engaged/Available/Cleaning): ";
            cin >> newStatus;
            hotel.updateRoomStatus(roomNumber, newStatus);  
            break;
        case 3:
            hotel.saveToFile();  
            break;
        case 4:
            hotel.retrieveFromFile();  
            break;
        case 5: {
            int filterChoice = -1;
            cout << "\n--- Filtering Menu ---" << endl;
            cout << "1. Filter by Status" << endl;
            cout << "2. Filter by Room Type" << endl;
            cout << "3. Filter by Price" << endl;
            cout << "0. Return to Main Menu" << endl;
            cout << "Enter your choice: ";
            filterChoice = getValidatedChoice();

            if (filterChoice == 1) {
                string statusFilter;
                cout << "Enter status to filter (Engaged/Available/Cleaning): ";
                cin >> statusFilter;
                hotel.filterByStatus(statusFilter);
            } else if (filterChoice == 2) {
                int typeChoice;
                cout << "1. Suit\n2. Standard\nEnter your choice: ";
                typeChoice = getValidatedChoice();
                if (typeChoice == 1) hotel.filterByType("Suit");
                else if (typeChoice == 2) hotel.filterByType("Standard");
                else cout << "Invalid choice!" << endl;
            } else if (filterChoice == 3) {
                double maxPrice;
                cout << "Enter maximum price (TL): ";
                while (!(cin >> maxPrice)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid price! Enter again: ";
                }
                hotel.filterByPrice(maxPrice);
            }
            break;
        }
        case 0:
            hotel.saveToFile(); // Cikista otomatik kaydet
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;  
        }
    }

    return 0;
}
