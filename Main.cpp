/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: January 30, 2020
Programming Assignment: PA2
Description: Create a program that investiages how much "work" is done by different sorting routines, depending on the input size and order of data. Work done is recorded in output CSV files with various plots for result visuals.
Notes: Main function cpp file
*/
#include "SortingAnalysis.h"
// main function
int main() {
	// seed random generator
	srand(time(0));
	// creating empty vectors
	vector<int> sortedVector500;
	vector<int> sortedVector500Copy;
	vector<int> sortedVectorDescending500;
	vector<int> sortedVectorDescending500Copy;
	vector<int> randomVector500;
	vector<int> randomVector500Copy;
	vector<int> sortedVector1000;
	vector<int> sortedVector1000Copy;
	vector<int> sortedVectorDescending1000;
	vector<int> sortedVectorDescending1000Copy;
	vector<int> randomVector1000;
	vector<int> randomVector1000Copy;
	vector<int> sortedVector5000;
	vector<int> sortedVector5000Copy;
	vector<int> sortedVectorDescending5000;
	vector<int> sortedVectorDescending5000Copy;
	vector<int> randomVector5000;
	vector<int> randomVector5000Copy;
	vector<int> sortedVector10000;
	vector<int> sortedVector10000Copy;
	vector<int> sortedVectorDescending10000;
	vector<int> sortedVectorDescending10000Copy;
	vector<int> randomVector10000;
	vector<int> randomVector10000Copy;
	
	// declaring output file variables
	ofstream selectionSortFile;
	ofstream bubbleSortFile;
	ofstream insertionSortFile;
	
	// vector generator for all three vectors for all 4 different node sizes
	sortedVectorGenerator(sortedVector500, 500);
	sortedVector500Copy = sortedVector500;
	sortedVectorGeneratorDescending(sortedVectorDescending500, 500);
	sortedVectorDescending500Copy = sortedVectorDescending500;
	randomVectorGenerator(randomVector500, 500);
	randomVector500Copy = randomVector500;
	sortedVectorGenerator(sortedVector1000, 1000);
	sortedVector1000Copy = sortedVector1000;
	sortedVectorGeneratorDescending(sortedVectorDescending1000, 1000);
	sortedVectorDescending1000Copy = sortedVectorDescending1000;
	randomVectorGenerator(randomVector1000, 1000);
	randomVector1000Copy = randomVector1000;
	sortedVectorGenerator(sortedVector5000, 5000);
	sortedVector5000Copy = sortedVector5000;
	sortedVectorGeneratorDescending(sortedVectorDescending5000, 5000);
	sortedVectorDescending5000Copy = sortedVectorDescending5000;
	randomVectorGenerator(randomVector5000, 5000);
	randomVector5000Copy = randomVector5000;
	sortedVectorGenerator(sortedVector10000, 10000);
	sortedVector10000Copy = sortedVector10000;
	sortedVectorGeneratorDescending(sortedVectorDescending10000, 10000);
	sortedVectorDescending10000Copy = sortedVectorDescending10000;
	randomVectorGenerator(randomVector10000, 10000);
	randomVector10000Copy = randomVector10000;
	
	// opens file for selection sort results and closes when done
	selectionSortFile.open("selection_sort_results.csv");
	selectionSortFile << "Vector configuration, Seconds, # Data Comparisons, # Loop Comparisons, # Data Assignments, # Loop Assignments, # Other, # Total" << endl;
	// writing out to selection sort .csv file for sorted vector
	selectionSortFile << "Sorted N=500, ";
	selectionSortVector(sortedVector500, selectionSortFile);
	selectionSortFile << "Sorted N=1000, ";
	selectionSortVector(sortedVector1000, selectionSortFile);
	selectionSortFile << "Sorted N=5000, ";
	selectionSortVector(sortedVector5000, selectionSortFile);
	selectionSortFile << "Sorted N=10000, ";
	selectionSortVector(sortedVector10000, selectionSortFile);
	// writing out to selection sort .csv file for sorted descending vector
	selectionSortFile << "Descending sorted N=500, ";
	selectionSortVector(sortedVectorDescending500, selectionSortFile);
	selectionSortFile << "Descending sorted N=1000, ";
	selectionSortVector(sortedVectorDescending1000, selectionSortFile);
	selectionSortFile << "Descending sorted N=5000, ";
	selectionSortVector(sortedVectorDescending5000, selectionSortFile);
	selectionSortFile << "Descending sorted N=10000, ";
	selectionSortVector(sortedVectorDescending10000, selectionSortFile);
	// writing out to selection sort .csv file for random vector
	selectionSortFile << "Random N=500, ";
	selectionSortVector(randomVector500, selectionSortFile);
	selectionSortFile << "Random N=1000, ";
	selectionSortVector(randomVector1000, selectionSortFile);
	selectionSortFile << "Random N=5000, ";
	selectionSortVector(randomVector5000, selectionSortFile);
	selectionSortFile << "Random N=10000, ";
	selectionSortVector(randomVector10000, selectionSortFile);
	selectionSortFile.close();
	
	// reseting the vectors for next sorting routines
	sortedVector500 = sortedVector500Copy;
	sortedVector1000 = sortedVector1000Copy;
	sortedVector5000 = sortedVector5000Copy;
	sortedVector10000 = sortedVector10000Copy;
	sortedVectorDescending500 = sortedVectorDescending500Copy;
	sortedVectorDescending1000 = sortedVectorDescending1000Copy;
	sortedVectorDescending5000 = sortedVectorDescending5000Copy;
	sortedVectorDescending10000 = sortedVectorDescending10000Copy;
	randomVector500 = randomVector500Copy;
	randomVector1000 = randomVector1000Copy;
	randomVector5000 = randomVector5000Copy;
	randomVector10000 = randomVector10000Copy;
	
	// opens file for bubble sort results and closes when done
	bubbleSortFile.open("bubble_sort_results.csv");
	bubbleSortFile << "Vector configuration, Seconds, # Data Comparisons, # Loop Comparisons, # Data Assignments, # Loop Assignments, # Other, # Total" << endl;
	// writing out to bubble sort .csv file for sorted vector
	bubbleSortFile << "Sorted N=500, ";
	bubbleSortVector(sortedVector500, bubbleSortFile);
	bubbleSortFile << "Sorted N=1000, ";
	bubbleSortVector(sortedVector1000, bubbleSortFile);
	bubbleSortFile << "Sorted N=5000, ";
	bubbleSortVector(sortedVector5000, bubbleSortFile);
	bubbleSortFile << "Sorted N=10000, ";
	bubbleSortVector(sortedVector10000, bubbleSortFile);
	// writing out to bubble sort .csv file for sorted descending vector
	bubbleSortFile << "Descending sorted N=500, ";
	bubbleSortVector(sortedVectorDescending500, bubbleSortFile);
	bubbleSortFile << "Descending sorted N=1000, ";
	bubbleSortVector(sortedVectorDescending1000, bubbleSortFile);
	bubbleSortFile << "Descending sorted N=5000, ";
	bubbleSortVector(sortedVectorDescending5000, bubbleSortFile);
	bubbleSortFile << "Descending sorted N=10000, ";
	bubbleSortVector(sortedVectorDescending10000, bubbleSortFile);
	// writing out to bubble sort .csv file for random vector
	bubbleSortFile << "Random N=500, ";
	bubbleSortVector(randomVector500, bubbleSortFile);
	bubbleSortFile << "Random N=1000, ";
	bubbleSortVector(randomVector1000, bubbleSortFile);
	bubbleSortFile << "Random N=5000, ";
	bubbleSortVector(randomVector5000, bubbleSortFile);
	bubbleSortFile << "Random N=10000, ";
	bubbleSortVector(randomVector10000, bubbleSortFile);
	bubbleSortFile.close();
	
	// reseting the vectors for next sorting routines
	sortedVector500 = sortedVector500Copy;
	sortedVector1000 = sortedVector1000Copy;
	sortedVector5000 = sortedVector5000Copy;
	sortedVector10000 = sortedVector10000Copy;
	sortedVectorDescending500 = sortedVectorDescending500Copy;
	sortedVectorDescending1000 = sortedVectorDescending1000Copy;
	sortedVectorDescending5000 = sortedVectorDescending5000Copy;
	sortedVectorDescending10000 = sortedVectorDescending10000Copy;
	randomVector500 = randomVector500Copy;
	randomVector1000 = randomVector1000Copy;
	randomVector5000 = randomVector5000Copy;
	randomVector10000 = randomVector10000Copy;
	
	// opens file for insertion sort results and closes when done
	insertionSortFile.open("insertion_sort_results.csv");
	insertionSortFile << "Vector configuration, Seconds, # Data Comparisons, # Loop Comparisons, # Data Assignments, # Loop Assignments, # Other, # Total" << endl;
	// writing out to insertion sort .csv file for sorted vector
	insertionSortFile << "Sorted N=500, ";
	insertionSortVector(sortedVector500, insertionSortFile);
	insertionSortFile << "Sorted N=1000, ";
	insertionSortVector(sortedVector1000, insertionSortFile);
	insertionSortFile << "Sorted N=5000, ";
	insertionSortVector(sortedVector5000, insertionSortFile);
	insertionSortFile << "Sorted N=10000, ";
	insertionSortVector(sortedVector10000, insertionSortFile);
	// writing out to insertion sort .csv file for sorted descending vector
	insertionSortFile << "Descending sorted N=500, ";
	insertionSortVector(sortedVectorDescending500, insertionSortFile);
	insertionSortFile << "Descending sorted N=1000, ";
	insertionSortVector(sortedVectorDescending1000, insertionSortFile);
	insertionSortFile << "Descending sorted N=5000, ";
	insertionSortVector(sortedVectorDescending5000, insertionSortFile);
	insertionSortFile << "Descending sorted N=10000, ";
	insertionSortVector(sortedVectorDescending10000, insertionSortFile);
	// writing out to insertion sort .csv file for random vector
	insertionSortFile << "Random N=500, ";
	insertionSortVector(randomVector500, insertionSortFile);
	insertionSortFile << "Random N=1000, ";
	insertionSortVector(randomVector1000, insertionSortFile);
	insertionSortFile << "Random N=5000, ";
	insertionSortVector(randomVector5000, insertionSortFile);
	insertionSortFile << "Random N=10000, ";
	insertionSortVector(randomVector10000, insertionSortFile);
	insertionSortFile.close();
	
	return 0;
}
