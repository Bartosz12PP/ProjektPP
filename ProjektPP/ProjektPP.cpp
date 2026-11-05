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
bool checkPopulation();
void changeParameters();

int main()
{
    showPopulation();
    //showPopulation(day, susceptible, infected, recovered);
    bool work = true;
    int choice;
    while (work == true) {
        cout << "=== Epidemic Simulator ===\n1. Simulate next day\n2. Change model parameters\n3. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                simulateDay();
                if (checkPopulation() == false) {
                    work = false;
                }
                continue;
            case 2:
                changeParameters();
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
bool checkPopulation() {
    if (susceptible < 0 || infected < 0 || recovered < 0 || susceptible + infected + recovered != 100) {
        return false;
    }
    else {
        return true;
    }
}
void changeParameters() {
    double tempnewinfectionRate;
    double tempnewrecoveryRate;
    cout << "Please give new infection rate: ";
    cin >> tempnewinfectionRate;
    cout << "Please give new recovery rate: ";
    cin >> tempnewrecoveryRate;
    if (tempnewinfectionRate > 0 && tempnewrecoveryRate > 0) {
        infectionRate = tempnewinfectionRate;
        recoveryRate = tempnewrecoveryRate;
    }
    else {
        cout << "ERROR! Please give correct parameters" << endl;
        changeParameters();
    }
}


