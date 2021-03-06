/* optimalRoutes.cpp
 *
 * File:
 *	Given a list of all possible routes, functions in this file
 *	find the optimal routes based on either of distance and cost.
 *
 *
 * Author:
 *      Vishnu Rudrasamudram vishnu.rudrasamudram@gmail.com
 *
 */


#include "STS_header.h"
bool operator ==(Edge a,Edge b)   // comparison of edges is used in functions
{
	if(a.u==b.u && a.v==b.v)
		return true;
	else return false;
}

list<string> getPossibleRouteNums(list<int> lis)  // gives a list of route numbers corresponding to the given path
{
        map<string,Edge> edges;
        list<string> pathNum;
        readRoute rrt;
        edges = rrt.getRoutes();
        list<int>::iterator lit = lis.begin();
        map<string,Edge>::iterator mit;
        for(int i=0;i<lis.size()-1;i++)
        {
                Edge cPath;
                cPath.u = *lit; ++lit;
                cPath.v = *lit;
                for(mit=edges.begin();mit!=edges.end();++mit)
                {
                        if(mit->second == cPath)
                        {
                                pathNum.push_back(mit->first);
                        }
                }
        }

	return pathNum;
}

int getFare(list<int> lis)
{
	int cord = readConf();  // cost or distance? read from configuration file
	readRoute rrt;
	map<string,int> pathCost = ((cord==COSTnCODES||cord==COSTnROUTES)?rrt.getCost():rrt.getDist()); // setting up cost or distance
	list<string> pathNum = getPossibleRouteNums(lis);
	list<string>::iterator sit;
        int sum = 0;
        for(sit=pathNum.begin();sit!=pathNum.end();++sit)
        {
                string ss = *sit;
		sum += pathCost.find(ss)->second;
        }
	return sum;
}

map<int,list<int> > getAllFares(list<list<int> > app) // this gives a map of path and its cost (value - path, key - its cost)
{	list<list<int> > capp = app;			// map stores entries in sorted order... no need of further sorting
	map<int,list<int> > ret;
	list<list<int> >::iterator llit;
	for(llit=capp.begin();llit!=capp.end();++llit)
	{
		ret[getFare(*llit)] = (*llit);
	}	
	return ret;
}

