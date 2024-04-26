#include "pch.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class Vehicle
{
private:
    std::string brand;
    std::string color;
    std::string model;

public:
    // Constructor
    Vehicle(std::string b, std::string c, std::string m)
    {
        brand = b;
        color = c;
        model = m;
    }

    // Getters
    std::string getBrand()
    {
        return brand;
    }

    std::string getColor()
    {
        return color;
    }

    std::string getModel()
    {
        return model;
    }
};

class ParkingStorage
{
private:
    std::string location;
    int capacity;
    int occupiedSpaces;
    std::vector<Vehicle*> parkedVehicles;

public:
    // Constructor
    ParkingStorage(std::string loc, int cap)
    {
        location = loc;
        capacity = cap;
        occupiedSpaces = 0;
    }

    // Destructor
    ~ParkingStorage()
    {
        for (Vehicle* vehicle : parkedVehicles)
        {
            delete vehicle;
        }
    }

    // Method to park a vehicle
    void parkVehicle(std::string brand, std::string color, std::string model)
    {
        if (occupiedSpaces < capacity)
        {
            Vehicle* newVehicle = new Vehicle(brand, color, model);
            parkedVehicles.push_back(newVehicle);
            occupiedSpaces++;
            std::cout << "Vehicle parked successfully.\n";
            displayStatus();
        }
        else
        {
            std::cout << "Parking is full. Cannot park vehicle.\n";
        }
    }

    // Method to remove a parked vehicle
    void removeVehicle()
    {
        if (occupiedSpaces > 0)
        {
            std::cout << "Existing vehicles:\n";
            for (int i = 0; i < parkedVehicles.size(); i++)
            {
                std::cout << i + 1 << ". " << parkedVehicles[i]->getBrand() << " " << parkedVehicles[i]->getModel() << std::endl;
            }

            int choice;
            std::cout << "Enter the index number of the vehicle to remove: ";
            std::cin >> choice;

            if (choice >= 1 && choice <= parkedVehicles.size())
            {
                delete parkedVehicles[choice - 1];
                parkedVehicles.erase(parkedVehicles.begin() + choice - 1);
                occupiedSpaces--;
                std::cout << "Vehicle removed successfully.\n";
                displayStatus(); // Display status of the current parking lot only
            }
            else
            {
                std::cout << "Invalid choice. Cannot remove vehicle.\n";
            }
        }
    }


    // Method to display parking status
    void displayStatus()
    {
        std::cout << "Location: " << location << std::endl;
        std::cout << "Capacity: " << occupiedSpaces << "/" << capacity << std::endl;

        if (!parkedVehicles.empty())
        {
            std::cout << "Parked Vehicles:" << std::endl;
            for (int i = 0; i < parkedVehicles.size(); i++)
            {
                std::cout << i + 1 << ". " << parkedVehicles[i]->getBrand() << " " << parkedVehicles[i]->getModel() << std::endl;
            }
        }

        std::cout << std::endl;
        std::cout << "=============================== " << std::endl;
    }
};

int main()
{
    // Create parking storage objects
    ParkingStorage parking1("Parking Lot 1", 3);
    ParkingStorage parking2("Parking Lot 2", 4);
    ParkingStorage parking3("Parking Lot 3", 5);

    int choice;
    std::string brand, color, model;

    do
    {
        // Display the status of parking storage objects
        std::system("cls");
        parking1.displayStatus();
        parking2.displayStatus();
        parking3.displayStatus();

        // Ask if the user wants to add or remove a vehicle
        char addOrRemoveChoice;
        std::cout << "Do you want to add or remove a vehicle? (A/R): ";
        std::cin >> addOrRemoveChoice;

        if (addOrRemoveChoice == 'A' || addOrRemoveChoice == 'a')
        {
            // Prompt user for parking choice and vehicle details
            std::cout << "Choose a parking lot (1, 2, or 3): ";
            std::cin >> choice;

            std::cout << "Enter vehicle brand: ";
            std::cin >> brand;

            std::cout << "Enter vehicle color: ";
            std::cin >> color;

            std::cout << "Enter vehicle model: ";
            std::cin >> model;

            // Park the vehicle in the chosen parking lot
            switch (choice)
            {
            case 1:
                parking1.parkVehicle(brand, color, model);
                break;
            case 2:
                parking2.parkVehicle(brand, color, model);
                break;
            case 3:
                parking3.parkVehicle(brand, color, model);
                break;
            default:
                std::cout << "Invalid choice. Cannot park vehicle.\n";
                break;
            }
        }
        else if (addOrRemoveChoice == 'R' || addOrRemoveChoice == 'r')
        {
            // Prompt user for parking choice to remove vehicle
            std::cout << "Choose a parking lot to remove vehicle (1, 2, or 3): ";
            std::cin >> choice;

            // Remove the vehicle from the chosen parking lot
            switch (choice)
            {
            case 1:
                parking1.removeVehicle();
                break;
            case 2:
                parking2.removeVehicle();
                break;
            case 3:
                parking3.removeVehicle();
                break;
            default:
                std::cout << "Invalid choice. Cannot remove vehicle.\n";
                break;
            }
        }

        // Ask if the user wants to add or remove another vehicle
        char continueChoice;
        std::cout << "Do you want to make any more changes? (Y/N): ";
        std::cin >> continueChoice;

        if (continueChoice == 'N' || continueChoice == 'n')
        {
            break;
        }

    } while (true);

    return 0;
}

