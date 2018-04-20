#include "hcplibrary/dir.hpp" 
using namespace std;

namespace hcplibrary{

int create_dir(const string& dir)
{
    string DirName(dir);
	int i = 0, len = 0;
	
	if(*DirName.end() != '/')
		DirName.push_back('/');
	len = DirName.size();
	if(access(DirName.c_str(),0) == 0)
		return 0;
	for(i = 1; i < len; i++)
	{
		if(DirName[i] == '/')
		{	
			DirName[i] = '\0';
			if(access(DirName.c_str(), 0) != 0)
			{
				if(mkdir(DirName.c_str(), 0777) == -1)  //failed to make dir
				{
					std::cout << "mkdir error!"  << std::endl;
					return -1;			
				}

			}
			DirName[i] = '/';
		}

	}
	return 0;
}

}