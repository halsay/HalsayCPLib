#include "hcplibrary/hcplibrary.hpp" 
using namespace std;

int main()
{
	string test = "HI.MI.TSU";
	vector<string> vs;
	vs = hcplibrary::split(test,".");
	hcplibrary::print_vector(vs);
	test = hcplibrary::strip(test,"SU");
	cout<< test<< endl;
	hcplibrary::create_dir("/home/halsayh/HalsayCPLib/test");
	return 0;
}