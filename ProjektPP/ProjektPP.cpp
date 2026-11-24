#include <iostream>
#include <cmath>

using namespace std;
const int MAX_DAYS= 100;
int populationHistory[MAX_DAYS + 1][3] = {};
int susceptible = 80;
int infected = 10;
int recovered = 10;
int day = 0;
int dailyNewInfections[MAX_DAYS] = {};
int dailyRecoveries[MAX_DAYS] = {};
double infectionRate = 0.20;
double recoveryRate = 0.10;
void showPopulation();
void simulateDay();
bool checkPopulation();
void changeParameters();
void showSimulationHistory();

int main()
{
    showPopulation();
    bool work = true;
    int choice;
    populationHistory[0][0] = susceptible;
    populationHistory[0][1] = infected;
    populationHistory[0][2] = recovered;
    while (work == true) {
        cout << "=== Epidemic Simulator ===\n1. Simulate next day\n2. Change model parameters\n3. Exit\n4. Show history" << endl;
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
            case 4:
                showSimulationHistory();
                continue;
            default:
                cout << "please choose one of the options" << endl;
                continue;
        }
    }



}

void showPopulation() {
    cout << "Day: " << day << "\nSusceptible: " << susceptible << "\nInfected: " << infected << "\nRecovered: " << recovered <<"\nTotal: " << susceptible+infected+recovered << endl;
    /*for (int i = 0; i <= day; i++) {
        cout << "Day: " <<day << ": " << "S = " << populationHistory[i][0] << ", "
            << "I = " << populationHistory[i][1] << ", "
            << "R = " << populationHistory[i][2] << endl;
    }*/
}
void simulateDay() {
    if (day >= MAX_DAYS) {
        cout << "Osiagnieto maksymalna liczbe dni!" << endl;
        return;
    }
    if (day >= 0 && day <= MAX_DAYS)
    {
        cout << "Dzień jest niepoprawny";
        return;
    }
    if (day - 1 >= 0 && day - 1 < MAX_DAYS) {
        cout << "Dzień jest niepoprawny";
        return;
    }
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
    if (day >= 0 && day <= MAX_DAYS) {
        populationHistory[day][0] = susceptible;
        populationHistory[day][1] = infected;
        populationHistory[day][2] = recovered;
    }

    if (day - 1 >= 0 && day - 1 < MAX_DAYS) {
        dailyNewInfections[day - 1] = newinfected;
        dailyRecoveries[day - 1] = newrecovered;
    }
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
void showSimulationHistory() {
    cout << "\n=== Simulation History & Daily Changes ===" << endl;

    cout << "Day 0: "
        << "S = " << populationHistory[0][0] << ", "
        << "I = " << populationHistory[0][1] << ", "
        << "R = " << populationHistory[0][2]
        << " | New infections: -"
        << ", New recoveries: -" << endl;

    for (int i = 1; i <= day; i++) {
        cout << "Day " << i << ": "
            << "S = " << populationHistory[i][0] << ", "
            << "I = " << populationHistory[i][1] << ", "
            << "R = " << populationHistory[i][2]
            << " | New infections: +" << dailyNewInfections[i - 1]
            << ", New recoveries: +" << dailyRecoveries[i - 1] << endl;
    }
}


