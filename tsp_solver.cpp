/*
	File: tsp_solver.cpp

	Author: Austin Hanus
	Class: CSCE-315
	Assignment: Project 1
	Description: Traveling Salesman Problem
	Date of Submission: 1/30/2015
*/

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>					 //abs()
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <float.h>					//DBL_MAX
#include "point.cpp"
using namespace std;

/*--------------------------------------------------------------------------*/
/* GLOBAL VARIABLES */
/*--------------------------------------------------------------------------*/

vector<Point> v;				//Vector to hold all Points from input
double distanceTraveled;			//Holds total distance traveled

/*--------------------------------------------------------------------------*/
/* HELPER FUNCTIONS */
/*--------------------------------------------------------------------------*/


/* Creates a Point from a string input */
Point stringToPoint(string input) {
	string xPos = "";
	string yPos = "";
	bool concatenateToX = true;   //Concat input into X if T, Y if F
	for (int i = 0; i < input.length(); ++i) {
		if (!isdigit(input[i]))   //Seperates the concatentation at whitespace
			concatenateToX = false;
		else if(isdigit(input[i]) && concatenateToX) 
			xPos += input[i];
		else if(isdigit(input[i]) && !concatenateToX)
			yPos += input[i];
	}
	return Point(stod(xPos), stod(yPos));
}

/* Allows user to input points until ^D is pressed.
   Ignores all comments or lines that dont start with a digit. */
void readFromStandardInput() {
	cout << "Input Points\n";
	string s;
	int id = 0;			    //Start id at 0
	while(!cin.eof()) {
		getline(cin, s);
		if(isdigit(s[0])) {
			Point p = stringToPoint(s);
			p.setID(id);        //Record the ID (order of input)
			++id; 
			v.push_back(p);
		} else { }		    //Do nothing if there isn't a digit at start
	}
}


/* Uses Nearest-Neighbor concept -- Each Point finds closest available Point
   and calculates distance and removes visited Point from vector */
void findPath() {
	distanceTraveled = 0.0;
	Point start = v[0];
	Point current = start;
	v.erase(v.begin());			//Removes the starting Point from vector
	cout << current.getID() << endl;
	while (v.size() != 0) {
		int indexOfMin = 0;
		Point min = Point(DBL_MAX, DBL_MAX);
		for (int j = 0; j < v.size(); ++j) {
			Point temp = min;
			min = current.minPoint(min, v[j]);
			if (temp.getDistanceTo(current) != min.getDistanceTo(current))
				indexOfMin = j;  //Recording index to remove when min changes
		}
		distanceTraveled += current.getDistanceTo(min); //Add up distances
		current = min;
		cout << min.getID() << endl;
		v.erase(v.begin()+indexOfMin);  //Remove visited Point from vector
	}
	distanceTraveled += current.getDistanceTo(start); //Add final distance
	cout << start.getID() << endl;
	cout << distanceTraveled << endl;
}

/*--------------------------------------------------------------------------*/
/* MAIN */
/*--------------------------------------------------------------------------*/

int main() {
	readFromStandardInput();
	findPath();
	return 0;
}
