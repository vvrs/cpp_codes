/* readRoutes.cpp
 *
 *
 * File:
 * 	A class called readRoute is defined in this file whose member functions
 * 	read routes.dat file and generates edges to be put in the graph and maps
 * 	of route number to source and destination, route number to cost, and route
 * 	number to distance. 
 *
 * Author:
 *      Vishnu Rudrasamudram vishnu.rudrasamudram@gmail.com
 *
 */



#include "STS_header.h"

readRoute::readRoute()
{
	
	/*
 	 * Required maps are defined in the class
 	 * as private members whose keys and values
 	 * will be set in this member function.	 	
 	 */
	
	map<string,int> indexMap;
	indexMap = indexCodes();
	ifstream fin(ROUTES);
	string word;
	int lin=FIRST_LINE;
	while(true)
	{
		if(lin!=FIRST_LINE)
		{
			while(fin>>word)
			{
				Edge edg;
				string route_no = word;
				fin>>word; fin>>word;
				string sourc = word;
				fin>>word; fin>>word;
				string dest = word; fin>>word; fin>>word;
				int kms = atoi(word.c_str());
				fin>>word; fin>>word;
				int cost = atoi(word.c_str());
				edg.u = indexMap.find(sourc)->second;
				edg.v = indexMap.find(dest)->second;
				edges.push_back(edg);
				routes[route_no] = edg;    // route number -> edge(source and destination)
				route_cost[route_no] = cost;// route number -> cost
				route_dist[route_no] = kms; // route number -> distance
				lin++;
					
			}
			break;
		}
		else //this is to ommit first line the file
		{
			for(int i=0;i<10;i++)   // 10 is number of words in current line
			{
				fin>>word;
			}
			lin++;
		}
	}
}

/*All of the below functions returns private list and maps*/

list<Edge> readRoute::getEdges()
{
        list<Edge> ret = edges;
        return ret;
}

map<string,Edge> readRoute::getRoutes()
{
        map<string,Edge> ret = routes;
        return ret;
}

map<string,int> readRoute::getCost()
{
        map<string,int> ret = route_cost;
        return ret;
}

map<string,int> readRoute::getDist()
{
        map<string,int> ret = route_dist;
        return ret;
}
