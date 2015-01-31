/*
	File: point.cpp

	Author: Austin Hanus
	Class: CSCE-315
	Assignment: Project 1
	Description: Traveling Salesman Problem
	Date of Submission: 1/30/2015
*/

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <stdio.h>
using namespace std;

/*--------------------------------------------------------------------------*/
/* POINT CLASS */
/*--------------------------------------------------------------------------*/

class Point {
private:
	double xPosition;			//X position on cartesian plane
	double yPosition;			//Y position on cartesian plane
	int pointID;			  	//Records order of how points are read in
public:
	Point(double x, double y)
		:xPosition(x), yPosition(y) {}
	Point(double x, double y, int id)
		:xPosition(x), yPosition(y), pointID(id) {}
	double getxPosition() const {return xPosition;}
	double getyPosition() const {return yPosition;}
	int getID() {return pointID;}
	void setID(int id) {pointID = id;}

	/* Calculate distance from THIS Point to given Point */
	double getDistanceTo(Point p) const {
		double xDifference = abs(p.getxPosition() - this->getxPosition());
		double yDifference = abs(p.getyPosition() - this->getyPosition());
		double distance = sqrt(pow(xDifference,2) + pow(yDifference,2));
		return distance;
	}

	/* Compares two given points. Returns the Point closer in distance to 
	   "this" Point */
	Point minPoint(Point p1, Point p2) {
		double p1Length = this->getDistanceTo(p1);
		double p2Length = this->getDistanceTo(p2);
		return (p1Length>p2Length) ? p2 : p1;
	}

};

