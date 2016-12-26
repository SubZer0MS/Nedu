#ifndef CSOM_H_
#define CSOM_H_

#include <vector>

using namespace std;

#include "CNode.h"
#include "constants.h"


class CSom
{

private:

	vector<CNode> m_SOM;				//the neurons representing the Self Organizing Map
	CNode* m_pWinningNode;				//this holds the address of the winning node from the current iteration
	double m_dMapRadius;				//this is the topological 'radius' of the feature map
	double m_dTimeConstant;				//used in the calculation of the neighbourhood width of influence
	int m_iNumIterations;				//the number of training iterations
	int m_iIterationCount;				//keeps track of what iteration the epoch method has reached
	double m_dNeighbourhoodRadius;		//the current width of the winning node's area of influence
	double m_dInfluence;				//how much the learning rate is adjusted for nodes within the area of influence
	double m_dLearningRate;				// the learning rate
	bool m_bDone;						//set true when training is finished
	double m_dCellWidth;				//the height and width of the cells that the nodes occupy when rendered into 2D space.
	double m_dCellHeight;				//the height and width of the cells that the nodes occupy when rendered into 2D space.


	CNode* FindBestMatchingNode(const vector<double> &vecInput);

	inline double GetGaussianDistance(const double dist, const double sigma);


public:

	CSom():
		m_dCellWidth(0),
		m_dCellHeight(0),
		m_pWinningNode(NULL),
		m_iIterationCount(1),
		m_iNumIterations(0),
		m_dTimeConstant(0),
		m_dMapRadius(0),
		m_dNeighbourhoodRadius(0),
		m_dInfluence(0),
		m_dLearningRate(constStartLearningRate),
		m_bDone(false)
	{}

	void Create(
		int cxClient,
		int cyClient,
		int CellsUp,
		int CellsAcross,
		int NumIterations
	);

	bool Epoch(const vector<vector<double>> &data);

	bool FinishedTraining() const { return m_bDone; }

};

#endif