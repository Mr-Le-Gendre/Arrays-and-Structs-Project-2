// Arrays and Structs Project 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

// Define a struct to store information about each runner
struct Runner {
    string name;
    int miles[NUM_DAYS];
    int totalMiles;
    double avgMiles;
};

// Function Prototypes
void readDataFromFile(const string& filename, Runner runners[], int numRunners);
void calculateTotalAndAverageMiles(Runner runners[], int numRunners);
void outputResults(const Runner runners[], int numRunners);
void printTableHeader();
void printRunnerData(const Runner& runner);

int main() {
    Runner runners[NUM_RUNNERS]; // Array to store information about each runner
    readDataFromFile("Runners.txt", runners, NUM_RUNNERS); // Read data from file
    calculateTotalAndAverageMiles(runners, NUM_RUNNERS); // Calculate total and average miles
    outputResults(runners, NUM_RUNNERS); // Output results
    return 0;
}

// Function to read and store data from file
void readDataFromFile(const string& filename, Runner runners[], int numRunners) {
    ifstream file(filename); // Open the file for reading
    if (!file.is_open()) { // Check if the file is opened successfully
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1); // Exit the program with error status
    }

    // Loop through each runner and read their data from the file
    for (int i = 0; i < numRunners; ++i) {
        file >> runners[i].name; // Read runner's name
        runners[i].totalMiles = 0; // Initialize total miles for the runner
        // Loop through each day and read miles run by the runner
        for (int j = 0; j < NUM_DAYS; ++j) {
            file >> runners[i].miles[j];
            runners[i].totalMiles += runners[i].miles[j]; // Calculate total miles for the runner
        }
        // Calculate average miles for the runner
        runners[i].avgMiles = static_cast<double>(runners[i].totalMiles) / NUM_DAYS;
    }

    file.close(); // Close the file
}

// Function to calculate total and average miles
void calculateTotalAndAverageMiles(Runner runners[], int numRunners) {
    // Loop through each runner
    for (int i = 0; i < numRunners; ++i) {
        runners[i].totalMiles = 0; // Initialize total miles for the runner
        // Loop through each day and calculate total miles for the runner
        for (int j = 0; j < NUM_DAYS; ++j) {
            runners[i].totalMiles += runners[i].miles[j];
        }
        // Calculate average miles for the runner
        runners[i].avgMiles = static_cast<double>(runners[i].totalMiles) / NUM_DAYS;
    }
}

// Function to output results
void outputResults(const Runner runners[], int numRunners) {
    printTableHeader(); // Print table headers
    // Print data for each runner
    for (int i = 0; i < numRunners; ++i) {
        printRunnerData(runners[i]);
    }
}

// Function to print table headers
void printTableHeader() {
    cout << setw(15) << "Runner Name";
    for (int i = 1; i <= NUM_DAYS; ++i) {
        cout << setw(10) << "Day " << i;
    }
    cout << setw(15) << "Total Miles" << setw(15) << "Avg Miles" << endl;
}

// Function to print data for a single runner
void printRunnerData(const Runner& runner) {
    cout << setw(15) << runner.name; // Print runner's name
    // Print miles run by the runner each day
    for (int j = 0; j < NUM_DAYS; ++j) {
        cout << setw(10) << runner.miles[j];
    }
    // Print total miles and average miles for the runner
    cout << setw(15) << runner.totalMiles << setw(15) << fixed << setprecision(2) << runner.avgMiles << endl;
}

