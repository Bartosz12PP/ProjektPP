#include <iostream>
using namespace std;
void showPopulation(int day, int susceptible, int infected, int recovered);

int main()
{
    int susceptible = 80;
    int infected = 10;
    int recovered = 10;
    int day = 0;
    double infectionRate = 0.20;
    double recoveryRate = 0.10;
    showPopulation(day, susceptible, infected, recovered);

}

void showPopulation(int day, int susceptible, int infected, int recovered) {
    cout << "Day: " << day << "\nSusceptible: " << susceptible << "\nInfected: " << infected << "\nRecovered: " << recovered <<"\nTotal: " << susceptible+infected+recovered << endl;
}

