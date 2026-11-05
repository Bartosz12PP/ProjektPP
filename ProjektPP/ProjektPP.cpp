#include <iostream>
#include <cmath>

using namespace std;
int susceptible = 80;
int infected = 10;
int recovered = 10;
int day = 0;
double infectionRate = 0.20;
double recoveryRate = 0.10;
void showPopulation();
void simulateDay();

int main()
{
    
    //showPopulation(day, susceptible, infected, recovered);
    bool work = true;
    int choice;
    while (work == true) {
        cout << "=== Epidemic Simulator ===\n1. Simulate next day\n2. Change model parameters\n3. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                simulateDay();
                continue;
            case 2:
                continue;
            case 3:
                cout << "Simulaton end";
                work = false;
                break;
            default:
                cout << "please choose one of the options" << endl;
                continue;
        }
    }



}

void showPopulation() {
    cout << "Day: " << day << "\nSusceptible: " << susceptible << "\nInfected: " << infected << "\nRecovered: " << recovered <<"\nTotal: " << susceptible+infected+recovered << endl;
}
void simulateDay() {
    int morningInfected = infected;
    int newinfected = floor(morningInfected * infectionRate);
    int newrecovered = floor(morningInfected * recoveryRate);
    
    if (newinfected > susceptible) {
        newinfected = susceptible;
    }
    if (newrecovered > morningInfected) {
        newrecovered = morningInfected;
    }
    if (newrecovered == 0 && morningInfected > 0) {
        newrecovered = 1;
    }
    susceptible = susceptible - newinfected;
    infected = infected + newinfected - newrecovered;
    recovered = recovered + newrecovered;
    day++;
    showPopulation();
}


