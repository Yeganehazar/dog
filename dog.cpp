#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Dog {
public:
    
    string name;
    int birthYear;


    Dog(string n, int by) : name(n), birthYear(by), score(0) {}

    
    int getAge() const {
        time_t t = time(0);
        tm* now = localtime(&t);
        int currentYear = now->tm_year + 1900;
        return currentYear - birthYear;
    }

    
    void bark() const {
        cout << name << " is barking: Woof! Woof!" << endl;
    }

    
    void learn() {
        score++;
        cout << name << " learned something new! Score: " << score << endl;
    }

    
    void showInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << getAge() << " years" << endl;
        cout << "Learning Score: " << score << endl;
    }

private:
    
    int score;
};

int main() {
    string dogName;
    int birthYear;

    
    cout << "Enter the dog's name: ";
    getline(cin, dogName);
    cout << "Enter the dog's birth year: ";
    cin >> birthYear;

    
    Dog myDog(dogName, birthYear);

    int choice;
    do {
        cout << "\nEnter 1 for bark, 2 for learning, 3 to continue, 0 to exit and show info: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myDog.bark();
                break;
            case 2:
                myDog.learn();
                break;
            case 3:
                
                break;
            case 0:
                myDog.showInfo();
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
