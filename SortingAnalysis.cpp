/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: January 30, 2020
Programming Assignment: PA2
Description: Create a program that investiages how much "work" is done by different sorting routines, depending on the input size and order of data. Work done is recorded in output CSV files with various plots for result visuals.
Notes: Function definition cpp file
*/
#include "SortingAnalysis.h"
// function definitions
/*************************************************************
 * Function: randomVectorGenerator()
 * Date Created: 02/05/20
 * Date Last Modified: 02/05/20          
 * Description: This function generates a random vector.
 * Input parameters: An empty vector must be pass by 
 *				reference and the size of the vector.
 * Returns: nothing
 * Pre: The empty vector must be pass by reference and the
 *				size of the vector had to have been scanned
 *            	in by the user.
 * Post: A vector is filled with elements of a certain size.
*************************************************************/
void randomVectorGenerator(vector<int>& vec, int size) {
	int i;
	// takes empty vector and inserts random numbers until filled
	for (i = 0; i < size; i++) {
		vec.push_back(rand() % size);
	}
}
/*************************************************************
 * Function: sortedVectorGenerator()
 * Date Created: 02/05/20
 * Date Last Modified: 02/05/20          
 * Description: This function generates a sorted vector.
 * Input parameters: An empty vector must be pass by 
 *				reference and the size of the vector.
 * Returns: nothing
 * Pre: The empty vector must be pass by reference and the
 *				size of the vector had to have been scanned
 *            	in by the user.
 * Post: A vector is filled with elements of a certain size.
*************************************************************/
void sortedVectorGenerator(vector<int>& vec, int size) {
	int i;
	// takes empty vector and inserts sequential numbers until filled
	for (i = 0; i < size; i++) {
		vec.push_back(i);
	}
}
/*************************************************************
 * Function: sortedVectorGeneratorDescending()
 * Date Created: 02/05/20
 * Date Last Modified: 02/05/20          
 * Description: This function generates a descending sorted
 *				vector.
 * Input parameters: An empty vector must be pass by 
 *				reference and the size of the vector.
 * Returns: nothing
 * Pre: The empty vector must be pass by reference and the
 *				size of the vector had to have been scanned
 *            	in by the user.
 * Post: A vector is filled with elements of a certain size.
*************************************************************/
void sortedVectorGeneratorDescending(vector<int>& vec, int size) {
	int i;
	// takes empty vector and inserts sequential numbers in descending order until filled
	for (i = size - 1; i >= 0; i--) {
		vec.push_back(i);
	}
}
/*************************************************************
 * Function: selectionSortVector()
 * Date Created: 02/05/20
 * Date Last Modified: 02/05/20          
 * Description: This function accepts a vector as sorts it in
 *				ascending order using selection sort.
 * Input parameters: The vector and ofstream file must be pass 
 *				by reference.
 * Returns: nothing
 * Pre: The vector and ofstream file must be pass by 
 *				reference and scanned in by the user.
 * Post: Takes unsorted and sorted vectors and sorts them
 *				correctly and outputs data to csv file.
*************************************************************/
void selectionSortVector(vector<int>& vec, ofstream& fileName) {
	// variables for different counter operations
	int dataComparison = 0, loopControlComparison = 0, dataAssignmentOperation = 0, loopControlAssignmentOperation = 0, otherOperation = 0, totalOperations = 0;
	// start clock
	auto start = high_resolution_clock::now();
	int startScan, minIndex, minValue;
	otherOperation += 3; // for declaring variables
	loopControlAssignmentOperation++; // for startScan = 0
	for (startScan = 0; startScan < vec.size() - 1; startScan++) {
		loopControlComparison++; // for startScan < vec.size() - 1
		// makes first index the minIndex
		minIndex = startScan;
		dataAssignmentOperation++; // for minIndex = startScan
		// makes first index the smallest value
		minValue = vec.at(startScan);
		dataAssignmentOperation++; // for minValue = vec.at(startScan);
		loopControlAssignmentOperation++; // for index = startScan + 1
		for (int index = startScan + 1; index < vec.size(); index++) {
			loopControlComparison++; // for index < vec.size()
			dataComparison++; // for if
			if (vec.at(index) < minValue) {
				// assigns the index to minValue if it is smaller than index value
				minValue = vec.at(index);
				dataAssignmentOperation++; // for minValue = vec.at(index)
				minIndex = index;
				dataAssignmentOperation++; // for minIndex = index
			}
			loopControlAssignmentOperation++; // for index++
		}
		vec.at(minIndex) = vec.at(startScan);
		dataAssignmentOperation++; // for vec.at(minIndex) = vec.at(startScan)
		vec.at(startScan) = minValue;
		dataAssignmentOperation++; // for vec.at(startScan) = minValue
		loopControlAssignmentOperation++; // for startScan++
	}
	totalOperations = dataComparison + loopControlComparison + dataAssignmentOperation + loopControlAssignmentOperation + otherOperation;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	// output data to correct csv file
	fileName << static_cast<double>(duration.count())/1000000.0 << ", " << dataComparison << ", " << loopControlComparison << ", " << dataAssignmentOperation << ", " << loopControlAssignmentOperation << ", " << otherOperation << ", " << totalOperations << endl;
}
/*************************************************************
 * Function: bubbleSortVector()
 * Date Created: 02/05/20
 * Date Last Modified: 02/05/20          
 * Description: This function accepts a vector as sorts it in
 *				ascending order using bubble sort.
 * Input parameters: The vector and ofstream file must be pass 
 *				by reference.
 * Returns: nothing
 * Pre: The vector and ofstream file must be pass by 
 *				reference and scanned in by the user.
 * Post: Takes unsorted and sorted vectors and sorts them
 *				correctly and outputs data to csv file.
*************************************************************/
void bubbleSortVector(vector<int>& vec, ofstream& fileName) {
	int dataComparison = 0, loopControlComparison = 0, dataAssignmentOperation = 0, loopControlAssignmentOperation = 0, otherOperation = 0, totalOperations = 0;
	// starts clock
	auto start = high_resolution_clock::now();
	bool swap;
	int temp;
	int count;
	otherOperation += 3; // for declaring variables
	// early exit implementation
	do {
		swap = false;
		loopControlAssignmentOperation++; // for assigning false to swap
		loopControlAssignmentOperation++; // for assigning 0 to count
		for (count = 0; count < vec.size() - 1; count++) {
			loopControlComparison++; // for comparing count to vec.size() - 1
			dataComparison++; // for if
			// compares if next element is smaller than current or not
			if (vec.at(count) > vec.at(count + 1)) {
				// swaps values around
				temp = vec.at(count);
				vec.at(count) = vec.at(count + 1);
				vec.at(count + 1) = temp;
				dataAssignmentOperation += 3; // for the swapping assignment commands
				swap = true;
				dataAssignmentOperation++; // for assigning true to swap
			}
			loopControlAssignmentOperation++; // for i++
		}
		loopControlComparison++; // for while (swap)
	} while (swap);
	totalOperations = dataComparison + loopControlComparison + dataAssignmentOperation + loopControlAssignmentOperation + otherOperation;
	auto stop = high_resolution_clock::now();
	// gets duration of sorting function
	auto duration = duration_cast<microseconds>(stop - start);
	// output data to correct csv file
	fileName << static_cast<double>(duration.count())/1000000.0 << ", " << dataComparison << ", " << loopControlComparison << ", " << dataAssignmentOperation << ", " << loopControlAssignmentOperation << ", " << otherOperation << ", " << totalOperations << endl;
}
/*************************************************************
 * Function: insertionSortVector()
 * Date Created: 02/05/20
 * Date Last Modified: 02/05/20          
 * Description: This function accepts a vector as sorts it in
 *				ascending order using insertion sort.
 * Input parameters: The vector and ofstream file must be pass 
 *				by reference.
 * Returns: nothing
 * Pre: The vector and ofstream file must be pass by 
 *				reference and scanned in by the user.
 * Post: Takes unsorted and sorted vectors and sorts them
 *				correctly and outputs data to csv file.
*************************************************************/
void insertionSortVector(vector<int>& vec, ofstream& fileName) {
	int dataComparison = 0, loopControlComparison = 0, dataAssignmentOperation = 0, loopControlAssignmentOperation = 0, otherOperation = 0, totalOperations = 0;
	// starts clock
	auto start = high_resolution_clock::now();
	int i, j, currValue;
	otherOperation += 3; // for declaring variables
	loopControlAssignmentOperation++; // for i = 1
	for (i = 1; i < vec.size(); i++) {
		loopControlComparison++; // for i < vec.size()
		currValue = vec.at(i);
		dataAssignmentOperation++; // for currValue = vec.at(i)
		j = i - 1;
		loopControlAssignmentOperation++; // for j = i - 1
		// checks to see if current value is the smallest before inserting
		while (j >= 0 && currValue < vec.at(j)) {
			loopControlComparison++; // for j >= 0
			loopControlComparison++; // for currValue < vec.at(j)
			// swaps value
			vec.at(j + 1) = vec.at(j);
			dataAssignmentOperation++; // for vec.at(j + 1) = vec.at(j)
			j--;
			loopControlAssignmentOperation++; // for j--
		}
		vec.at(j + 1) = currValue;
		dataAssignmentOperation++; // for vec.at(j + 1) = currValue
		loopControlAssignmentOperation++; // for i++
	}
	totalOperations = dataComparison + loopControlComparison + dataAssignmentOperation + loopControlAssignmentOperation + otherOperation;
	auto stop = high_resolution_clock::now();
	// gets duration of sorting function
	auto duration = duration_cast<microseconds>(stop - start);
	// output data to correct csv file
	fileName << static_cast<double>(duration.count())/1000000.0 << ", " << dataComparison << ", " << loopControlComparison << ", " << dataAssignmentOperation << ", " << loopControlAssignmentOperation << ", " << otherOperation << ", " << totalOperations << endl;
}
