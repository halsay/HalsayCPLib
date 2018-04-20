#include <iostream>  
#include <vector> 
#include <stdio.h>
#include <string.h>

#define LEFTSTRIP 0
#define RIGHTSTRIP 1
#define BOTHSTRIP 2
using namespace std;


namespace hcplibrary {
	
	vector<string> split(const string& str, const string& delim);

	string strip(const string & str, const string & chars);
	string lstrip(const string & str, const string & chars);
	string rstrip(const string & str, const string & chars);

	void print_vector(const vector<string> v);
	void print_vector(const vector<int> v);
	void print_vector(const vector<float> v);
}
