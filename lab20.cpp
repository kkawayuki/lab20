#include <iostream>
#include <iomanip>
#include <cstdlib> //for rand
#include <time.h> //to seed

using namespace std;
const int SIZE = 3, MIN = 10000, MAX = 99999; //declare global consts

class Chair
{
private:
    int legs;
    double *prices; // because prices represents array

public:
   
    Chair() // default constructor
    { 
        prices = new double[SIZE];
        legs = (rand()%2)+SIZE; //random int variable from 3-4
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand()%(MAX-MIN+1) + MIN)/100.00; //random double value from 100.00 to 999.99
    }

    Chair(int l, double *ptrArr) //take in legs, pointer to array of 3 doubles
    { 
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = *(ptrArr+i); //iterate through passed array dereferencing each to copy values. 
    }

    // setters
    void setLegs(int l) { legs = l; }

    void setPrices(double p1, double p2, double p3)
    {
        prices[0] = p1;
        prices[1] = p2;
        prices[2] = p3;
    }

    // getters
    int getLegs() { return legs; }

    double getAveragePrices()
    {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    // print function for each price in array
    void print()
    {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl
             << "Historical avg price: " << getAveragePrices();
        cout << endl
             << endl;
    }
};

int main()
{
    srand(time(0)); //seed random variable
    cout << fixed << setprecision(2);

    Chair *test1 = new Chair; //create first chair obj + its pointer using default (random) constructor
    test1->print(); // print randomly generated prices and legs

    Chair *test2 = new Chair; //create+print second to show differences in rand values
    test2->print(); 

    //creating a 


    // // creating pointer to first chair object
    // Chair *chairPtr = new Chair;
    // chairPtr->setLegs(4);
    // chairPtr->setPrices(121.21, 232.32, 414.14);
    // chairPtr->print();

    // // creating dynamic chair object with constructor
    // Chair *livingChair = new Chair();
    // livingChair->setPrices(525.25, 434.34, 252.52);
    // livingChair->print();
    // delete livingChair;
    // livingChair = nullptr;

    // // creating dynamic array of chair objects
    // Chair *collection = new Chair[SIZE];
    // collection[0].setLegs(4);
    // collection[0].setPrices(441.41, 552.52, 663.63);
    // collection[1].setLegs(4);
    // collection[1].setPrices(484.84, 959.59, 868.68);
    // collection[2].setLegs(4);
    // collection[2].setPrices(626.26, 515.15, 757.57);
    // for (int i = 0; i < SIZE; i++)
    //     collection[i].print();

    return 0;
}