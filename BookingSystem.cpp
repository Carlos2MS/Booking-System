#include<iostream>
#include <iomanip>
#include "BookingSystem.h"

    //Default constructor
    BookingSystem::BookingSystem(){
        //Set up all of the starting values
        name = "Trinity Laptop Bookings";
        totalWindowsLaptops =20;
        totalMacBooks=20;
        //Assumption
        availableWindowsLaptops=totalWindowsLaptops;
        availableMacBooks = totalMacBooks;
    }
    BookingSystem::BookingSystem(string name, int totalWindowsLaptops, int totalMacBooks){
        //Condition for the length of the string max of 64
        if(name.length() <= 64){
            this->name=name;
        }
        //if the name exceeds 64 characters
        if(name.length()>64){
            string totalc;
            for(int i=0; i<64; i++){
                totalc=totalc+name[i];
            }
            this->name= totalc;
        }
        //Given values to the memebers
        if(totalWindowsLaptops>=0){
            this->totalWindowsLaptops=totalWindowsLaptops;
            availableWindowsLaptops=totalWindowsLaptops;
        }
        if(totalWindowsLaptops<0){
            this->totalWindowsLaptops=0;
            availableWindowsLaptops=this->totalWindowsLaptops;
        }
        if(totalMacBooks>=0){
            this->totalMacBooks=totalMacBooks;
            availableMacBooks =totalMacBooks;
        }
        if(totalMacBooks<0){
            this->totalMacBooks=0;
            availableMacBooks =this->totalMacBooks;
        }

    }

    bool BookingSystem::RentWindowsLaptop(){
        //Just if exist laptops available substract 1
        if(availableWindowsLaptops>0){
            availableWindowsLaptops -= 1;
            return true;
        }
        return false;
    }
    bool BookingSystem::RentMacBook(){
        //Just if exist macbooks available substract 1
        if(availableMacBooks>0){
            availableMacBooks -= 1;
            return true;
        }
        return false;
    }
    
    void BookingSystem::ReturnWindowsLaptop(){
        //Check if there are laptops rented
        int checker = totalWindowsLaptops - availableWindowsLaptops;
        if(checker>0){
            availableWindowsLaptops += 1;
        }
    }
    void BookingSystem::ReturnMacBook(){
        //Check if there are macbooks rented
        int checker = totalMacBooks - availableMacBooks;
        if(checker>0){
            availableMacBooks += 1;
        }
    }

    //Get values functions
    string BookingSystem::getName(){
        return name;
    }

    unsigned int BookingSystem::getTotalWindowsLaptops(){
        return totalWindowsLaptops;
    }
    unsigned int BookingSystem::getTotalMacBooks(){
        return totalMacBooks;
    }

    unsigned int BookingSystem::getAvailableWindowsLaptops(){
        return availableWindowsLaptops;
    }
    unsigned int BookingSystem::getAvailableMacBooks(){
        return availableMacBooks;
    }

    unsigned int BookingSystem::getAvailableLaptops(){
        return availableMacBooks + availableWindowsLaptops;
    }
    unsigned int BookingSystem::getRentedWindowsLaptops(){
        return totalWindowsLaptops - availableWindowsLaptops;
    }
    unsigned int BookingSystem::getRentedMacBooks(){
        return totalMacBooks - availableMacBooks;
    }
    unsigned int BookingSystem::getRentedLaptops(){
        return getRentedWindowsLaptops() + getRentedMacBooks();   
    }

    void BookingSystem::addWindowsLaptops(unsigned int additionalWindowsLaptops){
        //Adding the new laptop to total and availables
        totalWindowsLaptops += additionalWindowsLaptops;
        availableWindowsLaptops += additionalWindowsLaptops;
    }
    void BookingSystem::addMacBooks(unsigned int additionalMacBooks){
        //Adding the new macbook to total and availables
        totalMacBooks += additionalMacBooks;
        availableMacBooks += additionalMacBooks;
    }
    void BookingSystem::removeWindowsLaptops(unsigned int removedWindowsLaptops){
        //Check if there are laptops rented
        int checker = availableWindowsLaptops - removedWindowsLaptops;
        //If it is true, substract 1 to total and available
        if(checker >= 0){
            totalWindowsLaptops -= removedWindowsLaptops;
            availableWindowsLaptops -= removedWindowsLaptops;
        }
        //When the removed exceeds
        if(checker<0){
            removedWindowsLaptops = availableWindowsLaptops;
            
            totalWindowsLaptops -= removedWindowsLaptops;
            availableWindowsLaptops -= removedWindowsLaptops;
        }
    }
    void BookingSystem::removeMacBooks(unsigned int removedMacBooks){
        //Check if there are macbooks rented
        int checker = availableMacBooks - removedMacBooks;
        //If it is true, substract 1 to total and available
        if(checker >= 0){
            totalMacBooks -= removedMacBooks;
            availableMacBooks -= removedMacBooks;
        }
        //When the removed exceeds
        if(checker<0){
            removedMacBooks = availableMacBooks;

            totalMacBooks -= removedMacBooks;
            availableMacBooks -= removedMacBooks;
        }
    }
    //Print output
    void BookingSystem::PrintReport(){
        cout<<"---------------------"<<endl;
        cout<<"Laptop Booking System"<<endl;
        cout<<"---------------------"<<endl;
        cout<<setw(26)<<left<<"Name"<<": ";
        cout<<name<<endl;

        cout<<setw(26)<<left<<"Total Windows Laptops"<<": ";
        cout<<totalWindowsLaptops<<endl;

        cout<<setw(26)<<left<<"Total MacBooks"<<": ";
        cout<<totalMacBooks<<endl;

        cout<<setw(26)<<left<<"Rented Windows Laptops"<<": ";
        cout<<getRentedWindowsLaptops()<<endl;

        cout<<setw(26)<<left<<"Rented MacBooks"<<": ";
        cout<<getRentedMacBooks()<<endl;

        cout<<setw(26)<<left<<"Rented Laptops"<<": ";
        cout<<getRentedLaptops()<<endl;

        cout<<setw(26)<<left<<"Available Windows Laptops"<<": ";
        cout<<availableWindowsLaptops<<endl;

        cout<<setw(26)<<left<<"Available MacBooks "<<": ";
        cout<<availableMacBooks<<endl;

        cout<<setw(26)<<left<<"Available Laptops "<<": ";
        cout<<getAvailableLaptops()<<endl;
    }