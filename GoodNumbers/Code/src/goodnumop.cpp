/*
 * goodnumop.cpp
 *
 * This source code contains all functions to get a good number of a particular length
 *
 * Author: Vishnu Rudrasamudram vishnu.rudrasamudram@gmail.com
 *
 */


#include "functions.h"

/* this function checks for the possibility of getting a good number of length d 
   starting with given string fs*/

gn possible_gn(string fs, int d) //gn is a structure to hold the string and a bool as possibility acknowledgment
{
        int i;
        int cl=0,pl=0;
	gn ret;
        string s=fs;
        for(i=s.length();i<d;i++) // every iteration in the loop checks 
        {			  // and adds a char to string if that is valid

                cl++;

                if(check(s+least(s[i-1])))
                {
                        s=s+least(s[i-1]);
                        pl = s.length()-1;
                }

                else if(check(s+'2'))
                {
                        s = s+'2';
                        pl = s.length()-1;
                }

                else if(check(s+'3'))
                {
                        s = s+'3';
                        pl = s.length()-1;
                }

		if(cl-pl == 1)	// condition where none of three digits can be put
		{		// to make a good number
			ret.str = s;
			ret.psb = 0;
			return ret;	
		}
	}
	ret.str = s;
	ret.psb = 1;
	return ret;
}

string find_good_num(int d)	
{
	string s = "1", ps;	// s is initializing string and ps - previous string
	int mb = 1,i=2;		// mb to pass to modified() to modify the number if it fails
				// to form a good number of given length

	repeat:
	for(i;i<=d;i++)
	{
		ps = possible_gn(s,i-1).str;
		if(!possible_gn(ps,i).psb)
		{
			s = modified(ps,mb);
		}
	}
	string opstr = possible_gn(s,i-1).str; //string after failing condition
	if(opstr.length()!=d)
	{
		mb++;		// changing modification character position and
		i = opstr.length();	//initial string
		goto repeat;	// and going into the loop
	}
	return opstr;
}	
