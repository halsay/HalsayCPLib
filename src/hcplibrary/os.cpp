#include "hcplibrary/os.hpp" 
using namespace std;

namespace hcplibrary {

vector<string> split(const string& str, const string& delim)
{  
    vector<string> res;  
    if("" == str) return res;  
    char * strs = new char[str.length() + 1] ;  
    strcpy(strs, str.c_str());   
  
    char * d = new char[delim.length() + 1];  
    strcpy(d, delim.c_str());  
  
    char *p = strtok(strs, d);  
    while(p) {  
        string s = p;
        res.push_back(s); 
        p = strtok(NULL, d);  
    }  
  
    return res;  
}

string do_strip(const string &str, int striptype, const string&chars)
{
    string::size_type strlen = str.size();
    string::size_type charslen = chars.size();
    string::size_type i, j;

    if (0 == charslen)
    {
        i = 0;
        if (striptype != RIGHTSTRIP)
        {
            while (i < strlen&&::isspace(str[i]))
            {
                i++;
            }
        }
        j = strlen;
        if (striptype != LEFTSTRIP)
        {
            j--;
            while (j >= i&&::isspace(str[j]))
            {
                j--;
            }
            j++;
        }
    }
    else
    {
        const char*sep = chars.c_str();
        i = 0;
        if (striptype != RIGHTSTRIP)
        {
            while (i < strlen&&memchr(sep, str[i], charslen))
            {
                i++;
            }
        }
        j = strlen;
        if (striptype != LEFTSTRIP)
        {
            j--;
            while (j >= i&&memchr(sep, str[j], charslen))
            {
                j--;
            }
            j++;
        }
        if (0 == i&& j == strlen)
        {
            return str;
        }
        else
        {
            return str.substr(i, j - i);
        }
    }
    return str;
}

string strip(const string & str, const string & chars=" ")
{
    return do_strip(str, BOTHSTRIP, chars);
}

string lstrip(const string & str, const string & chars=" ")
{
    return do_strip(str, LEFTSTRIP, chars);
}

string rstrip(const string & str, const string & chars=" ")
{
    return do_strip(str, RIGHTSTRIP, chars);
}

void print_vector(const vector<string> v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

void print_vector(const vector<int> v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

void print_vector(const vector<float> v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
}
