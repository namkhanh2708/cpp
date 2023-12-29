#include <iostream>
using namespace std;
class Animal {
public:
    Animal(const string& name) : name(name), hunger(100), happiness(0) {}

    void feed() {
        hunger -= 10; 
        if (hunger <0) hunger = 0;
        happiness += 10; 
        if (happiness > 100) happiness = 100;
        
    }

    void pet(){
        happiness += 10;
        if (happiness > 100) happiness = 100;
        hunger += 5;
        if (hunger > 100) hunger = 100;
    }

    void displayStatus() const { //shows the animals status
        std::cout << name << "\nHunger: " << hunger << "\nHappiness: " << happiness << endl;
    }

    virtual void makeSound() const = 0;

public:
    string name; 
    int hunger;
    int happiness;
};

class Lion : public Animal 
{
public:
    Lion(const string& name) : Animal(name) {}

    void makeSound() const override {
        cout << name << " the lion roars." << endl;
    }
};

class Bird : public Animal 
{
public:
    Bird(const string& name) : Animal(name) {}

    void makeSound() const override {
        cout << name << " the bird chirps." << endl;
    }
};

class Bear : public Animal 
{
public:
    Bear(const string& name) : Animal(name) {}

    void makeSound() const override {
        cout << name << " the bear growls." << endl;
    }
};

class Horse : public Animal 
{
public:
    Horse(const string& name) : Animal(name) {}

    void makeSound() const override 
    {
        cout << name << " the horse neighs." << endl;
    }
};

int main() 
{
    Lion lion("Simba");
    Bird bird("Tweety");
    Bear bear("Baloo");
    Horse horse("Sven");
  
    while (true) {
        cout << "Welcome to the Zoo! \nChoose an animal to interact with \n1 - Lion \n2 - Bird \n3 - Bear \n4 - Horse \n0 - Exit \n";
        int choice;
        cin >> choice;

        if (choice == 0) {
            break;
        }

        Animal* selectedAnimal = nullptr;

        switch (choice) {
            case 1:
                selectedAnimal = &lion;
                break;
            case 2:
                selectedAnimal = &bird;
                break;
            case 3:
                selectedAnimal = &bear;
                break;
            case 4:
                selectedAnimal = &horse;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                continue;
        }

        cout << "You chose to interact with " <<selectedAnimal ->name << endl;
        selectedAnimal->displayStatus();
        selectedAnimal->makeSound();

        cout << "What would you like to do? (1 - Feed, 2 - Pet): ";
        int action;
        cin >> action;

        if (action == 1) {
            selectedAnimal->feed();
        } else if (action == 2) {
            selectedAnimal->pet();
        } else {
            cout << "Invalid action. Try again." << endl;
        }

        selectedAnimal->displayStatus();
    }

    return 0;
}
