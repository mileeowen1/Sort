#ifndef SORTING_ANALYSIS_H
#define SORTING_ANALYSIS_H
/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: January 30, 2020
Programming Assignment: PA2
Description: Create a program that investiages how much "work" is done by different sorting routines, depending on the input size and order of data. Work done is recorded in output CSV files with various plots for result visuals.
Notes: Function prototypes and header file
*/
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;
// function prototypes
void randomVectorGenerator(vector<int>&, int);
void sortedVectorGenerator(vector<int>&, int);
void sortedVectorGeneratorDescending(vector<int>&, int);
void selectionSortVector(vector<int>&, ofstream&);
void bubbleSortVector(vector<int>&, ofstream&);
void insertionSortVector(vector<int>&, ofstream&);
#endif
