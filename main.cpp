#include <iostream>
#include <string>

using namespace std;

// user== User
// password==User




struct Guest {
    string name;
    int roomNumber;
    int numNights;
};
struct login{
    string username;
    string password;
};


void displayMenu();
void checkIn(Guest* guests, int& numGuests, int maxGuests);
void checkOut(Guest* guests, int& numGuests);
void displayGuests(Guest* guests, int numGuests);
int findGuest(Guest* guests, int numGuests, int roomNumber);

int main() {
    const int MAX_GUESTS = 10;
    Guest guests[MAX_GUESTS];
    int numGuests = 0;
      int choice;

      login user;
      b:
      cout<<"Enter User Name: ";
      cin>>user.username;
      cout<<"Enter your password: ";
      cin>>user.password;
      if(user.username == "User" && user.password == "User"){
        cout<<"access granted. Welcome!!";
      }
      else{
        goto b;
      }
    do {
        displayMenu();
        c:
        cout << "Enter your choice: ";
        cin >> choice;
        while (cin.fail()) {
       cout<<"invalid choice.Please try again\n";
       cin.clear();
       cin.ignore();
            goto c;
            }

        switch (choice) {
            case 1:
                checkIn(guests, numGuests, MAX_GUESTS);
                break;
            case 2:
                checkOut(guests, numGuests);
                break;
            case 3:
                displayGuests(guests, numGuests);
                break;
            case 4:
                cout << "--system exited--"<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again."<<endl;
                break;
        }
    } while (choice != 4);

    return 0;
}


void displayMenu() {
        cout << "\n\n----Hotel Management System----\nMade by section N1 students Mikiyas Abebe   id uu88761R and Feleke Belay    id uu88720"<<endl;
        cout << "-----------------------"<<endl;
    cout << "1. Check In"<<endl;
    cout << "2. Check Out"<<endl;
    cout << "3. Display Guest List"<<endl;
    cout << "4. Exit"<<endl;
}


void checkIn(Guest* guests, int& numGuests, int maxGuests) {
  system("cls");
    if (numGuests == maxGuests) {
        cout << "The hotel is full. Cannot check in any more guests."<<endl;
        return;
    }

  Guest newGuest;

    gn:
    cin.ignore();
    cout << "Enter guest name: ";
    getline(cin, newGuest.name);
     while (cin.fail()) {
       cout<<"invalid room no\n";
       cin.clear();
       cin.ignore();
            goto gn;
            }
    rm1:
    rm:
    cout << "Enter room number: ";
    cin >> newGuest.roomNumber;
    while (cin.fail()) {
       cout<<"invalid room number.\n";
       cin.clear();
       cin.ignore();
            goto rm1;
            }

      if (newGuest.roomNumber >10 || newGuest.roomNumber <=0 ){
      cout<<"invalid room number. We got room from 1 to 10\n";
       cin.clear();
       cin.ignore();
            goto rm;
  }
  nn:
    cout << "Enter number of nights:";
    cin >> newGuest.numNights;
    while (cin.fail()) {
       cout<<"invalid value. Please try again\n";
       cin.clear();
       cin.ignore();
            goto nn;
            }

/////// Check if the room is already occupied

    int guestIndex = findGuest(guests, numGuests, newGuest.roomNumber);
    if (guestIndex != -1) {
        cout << "Room " << newGuest.roomNumber << " is already occupied by " << guests[guestIndex].name;
        return;
    }

    guests[numGuests] = newGuest;
    numGuests++;
    cout << newGuest.name << " has been checked in to room " << newGuest.roomNumber <<endl;
}



void checkOut(Guest* guests, int& numGuests) {
  system("cls");
    int roomNumber;
    c:
    cout << "Enter room number of guest to check out: ";
    cin >> roomNumber;

      while (cin.fail()) {
       cout<<"invalid room number\n";
       cin.clear();
       cin.ignore();
            goto c;
            }
    int guestroom = findGuest(guests, numGuests, roomNumber);
    if (guestroom == -1)  {
          cout << "Room " << roomNumber << " is not currently occupied."<<endl;
        return;
    }

    cout << guests[guestroom].name << " has been checked out of room " << guests[guestroom].roomNumber << " after staying " << guests[guestroom].numNights << " nights."<<endl;

    for (int i = guestroom; i < numGuests - 1; i++) {
        guests[i] = guests[i + 1];
    }
    numGuests--;
}


void displayGuests(Guest* guests, int numGuests) {
  system("cls");
    if (numGuests == 0) {
        cout << "There are no guests currently checked in."<<endl;
        return;
    }

    cout << "Guest List:"<<endl;
    cout << "-----------"<<endl;
    for (int i = 0; i < numGuests; i++) {
        cout << guests[i].name << " is in room " << guests[i].roomNumber << " and has stayed " << guests[i].numNights << " nights."<<endl;
    }
}

////// to find guests

int findGuest(Guest* guests, int numGuests, int roomNumber) {
    for (int i = 0; i < numGuests; i++) {
        if (guests[i].roomNumber == roomNumber) {
            return i;
        }
    }
    return -1;
}
