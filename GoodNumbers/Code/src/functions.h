/*
 * functions.h
 *
 * Author: Vishnu Rudrasamudram vishnu.rudrasamudram@gmail.com
 * 
 */


#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

typedef struct gn
{
	string str;
	bool   psb;
}gn;

string convert(int);

bool check(string);

char least(char);

string modified(string,int);

gn possible_gn(string,int);

string find_good_num(int);
