// COMSC-210 | lab 20 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <iomanip>
#include <cstdlib> //for rand
#include <time.h>  //to seed

using namespace std;
const int SIZE = 3, MIN = 10000, MAX = 99999; // declare global consts

class Chair
{
private:
    int legs;
    double *prices; // because prices represents array

public:
    Chair() // default constructor
    {
        prices = new double[SIZE];
        legs = (rand() % 2) + SIZE; // random int variable from 3-4
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.00; // random double value from 100.00 to 999.99
    }

    Chair(int l, double arr[]) // take in legs, array of 3 doubles
    {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = arr[i]; // iterate through passed array copying values.
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
    int getLegs() const { return legs; } 

    /************************************************
     * Function: calculates the average value that a
     * chair object contains, does not have an associated
     * variable for the value to avoid "stale data",
     * instead calculating and returning the average
     * whenever needed.
     * 
     * Parameters: NONE
     * 
     * Return: calculated average value (double)
     ************************************************/
    double getAveragePrices() const 
    {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    /************************************************
     * Function: prints all relevant fields of a 
     * specific Chair object. Uses public getter
     * functions to avoid risking data manipulation
     * 
     * Parameters: NONE
     * Return: NONE
     ************************************************/
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

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    srand(time(0)); // seed random variable
    cout << fixed << setprecision(2);

    // manual creation of chair object using setters
    cout << "Printing data for manual object-------------------\n";
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    // creating dynamic chair object with partial help from constructor (gen random leg amt)
    cout << "Printing data for dynamic object------------------\n";
    Chair *livingChair = new Chair();
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    // creating a chair both parameters in constructor
    cout << "Printing data for user-passed value object-------\n";
    double arr1[3] = {192.29, 203.26, 991.00}; // creation of array
    Chair *test3 = new Chair(4, arr1);         // passing array to parameter constructor
    test3->print();


    // creating dynamic array of chair objects
    cout << "Printing data for dynamic array of Chairs----------\n";
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++) // note that default constructor is implcitly called for each field, generating random leg/price data.
        collection[i].print();

    
    return 0;
}