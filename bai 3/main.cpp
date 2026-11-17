#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstddef>
#include <algorithm>
using namespace std;
class Vehicle {
private:
    int vehicleID;
    string vehicleType;
    double entryTime, parkingDuration, parkingFee;
public:
    Vehicle(int id = 0, string type = "Car", double time = 0, double duration = 0) {
        vehicleID = id;
        vehicleType = type;
        entryTime = time;
        parkingDuration = duration;
        calculateFee();
    }
    int getVehicleID() const { return vehicleID; }
    string getVehicleType() const { return vehicleType; }
    double getEntryTime() const { return entryTime; }
    double getParkingDuration() const { return parkingDuration; }
    double getParkingFee() const { return parkingFee; }
    void setVehicleID(int id) { vehicleID = id; }
    void setVehicleType(string type) {
        vehicleType = type;
        calculateFee();
    }
    void setEntryTime(double time) { entryTime = time; }
    void setParkingDuration(double duration) {
        parkingDuration = duration;
        calculateFee();
    }
    double calculateFee() {
        double price = 0;
        if (vehicleType == "Car") price = 6000;
        else if (vehicleType == "Motorcycle") price = 4000;
        else if (vehicleType == "Bicycle") price = 2000;
        parkingFee = price * parkingDuration;
        return parkingFee;
    }
    void display() const {
        cout << fixed << setprecision(2)
             << "Ma xe: " << vehicleID
             << " | Loai: " << vehicleType
             << " | Gio vao: " << entryTime
             << " | So gio do: " << parkingDuration
             << " | Phi: " << parkingFee << " VND\n";
    }
};
class ParkingLot {
private:
    int parkID;
    char size;
    int capacity, currentVehicleCount;
    Vehicle** vehicles;
    void clear() {
        for (int i = 0; i < currentVehicleCount; i++) {
            delete vehicles[i];
            vehicles[i] = NULL;
        }
        delete[] vehicles;
        vehicles = NULL;
        currentVehicleCount = 0;
    }
public:
    ParkingLot(int id = 0, char s = 'S') {
        parkID = id;
        size = s;
        capacity = (s == 'S' ? 1 : (s == 'M' ? 2 : 3));
        currentVehicleCount = 0;
        vehicles = new Vehicle*[capacity];
        for (int i = 0; i < capacity; i++)
            vehicles[i] = NULL;
    }
    ~ParkingLot() {
        clear();
    }
    ParkingLot(const ParkingLot& other) {
        parkID = other.parkID;
        size = other.size;
        capacity = other.capacity;
        currentVehicleCount = 0;
        vehicles = new Vehicle*[capacity];
        for (int i = 0; i < capacity; i++)
            vehicles[i] = NULL;
        try {
            for (int i = 0; i < other.currentVehicleCount; i++) {
                vehicles[i] = new Vehicle(*other.vehicles[i]);
                currentVehicleCount++;
            }
        } catch (...) {
            clear();
            throw;
        }
    }
    ParkingLot& operator=(const ParkingLot& other) {
        if (this != &other) {
            ParkingLot temp(other);
            swap(parkID, temp.parkID);
            swap(size, temp.size);
            swap(capacity, temp.capacity);
            swap(currentVehicleCount, temp.currentVehicleCount);
            swap(vehicles, temp.vehicles);
        }
        return *this;
    }
    int getParkID() const { return parkID; }
    int getCount() const { return currentVehicleCount; }
    const Vehicle* findVehicle(int id) const {
        for (int i = 0; i < currentVehicleCount; i++)
            if (vehicles[i]->getVehicleID() == id)
                return vehicles[i];
        return NULL;
    }
    void resize(int newCapacity) {
        if (newCapacity < currentVehicleCount || newCapacity <= 0)
            return;
        Vehicle** temp = new Vehicle*[newCapacity];
        for (int i = 0; i < newCapacity; i++)
            temp[i] = NULL;
        for (int i = 0; i < currentVehicleCount; i++)
            temp[i] = vehicles[i];
        delete[] vehicles;
        vehicles = NULL;
        vehicles = temp;
        temp = NULL;
        capacity = newCapacity;
    }
    bool addVehicle(const Vehicle& v) {
        if (findVehicle(v.getVehicleID()) != NULL)
            return false;
        if (currentVehicleCount == capacity)
            resize(capacity * 2);
        vehicles[currentVehicleCount] = new Vehicle(v);
        currentVehicleCount++;
        return true;
    }
    bool removeVehicle(int id) {
        for (int i = 0; i < currentVehicleCount; i++) {
            if (vehicles[i]->getVehicleID() == id) {
                delete vehicles[i];
                vehicles[i] = NULL;
                for (int j = i; j < currentVehicleCount - 1; j++)
                    vehicles[j] = vehicles[j + 1];
                vehicles[currentVehicleCount - 1] = NULL;
                currentVehicleCount--;
                return true;
            }
        }
        return false;
    }
    void display() const {
        cout << "Ma bai: " << parkID
             << " | Size: " << size
             << " | So xe: " << currentVehicleCount
             << " | Suc chua: " << capacity << '\n';
    }
    void displayVehicles() const {
        display();
        if (currentVehicleCount == 0)
            cout << "Bai chua co xe.\n";
        for (int i = 0; i < currentVehicleCount; i++)
            vehicles[i]->display();
    }
    int displayByType(const string& type) const {
        int count = 0;
        for (int i = 0; i < currentVehicleCount; i++) {
            if (vehicles[i]->getVehicleType() == type) {
                cout << "Bai " << parkID << " | ";
                vehicles[i]->display();
                count++;
            }
        }
        return count;
    }
    double totalFee() const {
        double total = 0;
        for (int i = 0; i < currentVehicleCount; i++)
            total += vehicles[i]->getParkingFee();
        return total;
    }
};
class SystemInterface {
private:
    int lotCapacity, currentLotCount;
    ParkingLot** parkingLots;
    void clear() {
        for (int i = 0; i < currentLotCount; i++) {
            delete parkingLots[i];
            parkingLots[i] = NULL;
        }
        delete[] parkingLots;
        parkingLots = NULL;
        currentLotCount = 0;
    }
    ParkingLot* findLot(int id) {
        for (int i = 0; i < currentLotCount; i++)
            if (parkingLots[i]->getParkID() == id)
                return parkingLots[i];
        return NULL;
    }
    bool hasVehicle(int id) const {
        for (int i = 0; i < currentLotCount; i++)
            if (parkingLots[i]->findVehicle(id) != NULL)
                return true;
        return false;
    }
public:
    SystemInterface() {
        lotCapacity = 5;
        currentLotCount = 0;
        parkingLots = new ParkingLot*[lotCapacity];
        for (int i = 0; i < lotCapacity; i++)
            parkingLots[i] = NULL;
    }
    ~SystemInterface() {
        clear();
    }
    SystemInterface(const SystemInterface& other) {
        lotCapacity = other.lotCapacity;
        currentLotCount = 0;
        parkingLots = new ParkingLot*[lotCapacity];
        for (int i = 0; i < lotCapacity; i++)
            parkingLots[i] = NULL;
        try {
            for (int i = 0; i < other.currentLotCount; i++) {
                parkingLots[i] = new ParkingLot(*other.parkingLots[i]);
                currentLotCount++;
            }
        } catch (...) {
            clear();
            throw;
        }
    }
    SystemInterface& operator=(const SystemInterface& other) {
        if (this != &other) {
            SystemInterface temp(other);
            swap(lotCapacity, temp.lotCapacity);
            swap(currentLotCount, temp.currentLotCount);
            swap(parkingLots, temp.parkingLots);
        }
        return *this;
    }
    void resizeSystem(int newCapacity) {
        if (newCapacity < currentLotCount || newCapacity <= 0)
            return;
        ParkingLot** temp = new ParkingLot*[newCapacity];
        for (int i = 0; i < newCapacity; i++)
            temp[i] = NULL;
        for (int i = 0; i < currentLotCount; i++)
            temp[i] = parkingLots[i];
        delete[] parkingLots;
        parkingLots = NULL;
        parkingLots = temp;
        temp = NULL;
        lotCapacity = newCapacity;
    }
    void runMenu() {
        int choice;
        do {
            cout << "\n===== QUAN LY BAI DO XE =====\n"
                 << "1. Tao bai do moi\n"
                 << "2. Them xe vao bai\n"
                 << "3. Xoa bai do\n"
                 << "4. Lay xe ra\n"
                 << "5. Hien thi tat ca bai do\n"
                 << "6. Hien thi xe theo bai\n"
                 << "7. Liet ke xe theo loai\n"
                 << "8. Phi do xe trung binh\n"
                 << "9. Thoat\n"
                 << "Chon: ";
            if (!(cin >> choice)) return;
            switch (choice) {
            case 1: {
                int id;
                char s;
                cout << "Nhap ma bai va kich thuoc S/M/L: ";
                if (!(cin >> id >> s)) return;
                s = static_cast<char>(toupper(static_cast<unsigned char>(s)));
                if (id <= 0 || (s != 'S' && s != 'M' && s != 'L')) {
                    cout << "Du lieu khong hop le.\n";
                    break;
                }
                if (findLot(id) != NULL) {
                    cout << "Trung ma bai.\n";
                    break;
                }
                if (currentLotCount == lotCapacity)
                    resizeSystem(lotCapacity * 2);
                parkingLots[currentLotCount] = new ParkingLot(id, s);
                currentLotCount++;
                cout << "Da tao bai.\n";
                break;
            }
            case 2: {
                int id, vehicleID, type;
                double time, duration;
                cout << "Nhap ma bai: ";
                if (!(cin >> id)) return;
                ParkingLot* lot = findLot(id);
                if (lot == NULL) {
                    cout << "Khong tim thay bai.\n";
                    break;
                }
                cout << "Nhap ma xe: ";
                if (!(cin >> vehicleID)) return;
                if (vehicleID <= 0 || hasVehicle(vehicleID)) {
                    cout << "Ma xe khong hop le hoac bi trung.\n";
                    break;
                }
                cout << "Loai xe (1.Car 2.Motorcycle 3.Bicycle): ";
                if (!(cin >> type)) return;
                if (type < 1 || type > 3) {
                    cout << "Loai xe khong hop le.\n";
                    break;
                }
                cout << "Nhap gio vao va so gio do: ";
                if (!(cin >> time >> duration)) return;
                if (time < 0 || time >= 24 || duration < 0) {
                    cout << "Thoi gian khong hop le.\n";
                    break;
                }
                string name = type == 1 ? "Car" :
                              (type == 2 ? "Motorcycle" : "Bicycle");
                lot->addVehicle(Vehicle(vehicleID, name, time, duration));
                cout << "Da them xe.\n";
                break;
            }
            case 3: {
                int id, index = -1;
                cout << "Nhap ma bai can xoa: ";
                if (!(cin >> id)) return;
                for (int i = 0; i < currentLotCount; i++) {
                    if (parkingLots[i]->getParkID() == id) {
                        index = i;
                        break;
                    }
                }
                if (index == -1) {
                    cout << "Khong tim thay bai.\n";
                    break;
                }
                delete parkingLots[index];
                parkingLots[index] = NULL;
                for (int i = index; i < currentLotCount - 1; i++)
                    parkingLots[i] = parkingLots[i + 1];
                parkingLots[currentLotCount - 1] = NULL;
                currentLotCount--;
                cout << "Da xoa bai va cac xe trong bai.\n";
                break;
            }
            case 4: {
                int id, vehicleID;
                cout << "Nhap ma bai va ma xe: ";
                if (!(cin >> id >> vehicleID)) return;
                ParkingLot* lot = findLot(id);
                if (lot == NULL) {
                    cout << "Khong tim thay bai.\n";
                    break;
                }
                const Vehicle* v = lot->findVehicle(vehicleID);
                if (v == NULL) {
                    cout << "Khong tim thay xe.\n";
                    break;
                }
                v->display();
                lot->removeVehicle(vehicleID);
                v = NULL;
                cout << "Da lay xe ra.\n";
                break;
            }
            case 5:
                if (currentLotCount == 0)
                    cout << "Chua co bai do.\n";
                for (int i = 0; i < currentLotCount; i++)
                    if (parkingLots[i] != NULL)
                        parkingLots[i]->display();
                break;
            case 6: {
                int id;
                cout << "Nhap ma bai: ";
                if (!(cin >> id)) return;
                ParkingLot* lot = findLot(id);
                if (lot != NULL)
                    lot->displayVehicles();
                else
                    cout << "Khong tim thay bai.\n";
                break;
            }
            case 7: {
                int type, count = 0;
                cout << "Loai xe (1.Car 2.Motorcycle 3.Bicycle): ";
                if (!(cin >> type)) return;
                if (type < 1 || type > 3) {
                    cout << "Loai xe khong hop le.\n";
                    break;
                }
                string name = type == 1 ? "Car" :
                              (type == 2 ? "Motorcycle" : "Bicycle");
                for (int i = 0; i < currentLotCount; i++)
                    count += parkingLots[i]->displayByType(name);
                if (count == 0)
                    cout << "Khong co xe thuoc loai nay.\n";
                break;
            }
            case 8: {
                double total = 0;
                int count = 0;
                for (int i = 0; i < currentLotCount; i++) {
                    total += parkingLots[i]->totalFee();
                    count += parkingLots[i]->getCount();
                }
                if (count == 0)
                    cout << "Chua co xe.\n";
                else
                    cout << fixed << setprecision(2)
                         << "Phi trung binh: "
                         << total / count << " VND\n";
                break;
            }
            case 9:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
            }
        } while (choice != 9);
    }
};
int main() {
    SystemInterface system;
    system.runMenu();
    return 0;
}
