#include <iostream>
#include "skipList.h"
#include "hashtable.h"
#include "structure.h"
#include <cstdlib>
#include <time.h>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;


int main(int argc, char* argv[])
{
    char* input_file; 
    int num_hashtable=0;
    for(int i=0; i<argc; i++)
    {
	string a=string(argv[i]);
        if(a == "-l")
        {
            input_file = argv[i+1];
        }
        if(a == "-b")
        {
            num_hashtable = atoi(argv[i+1]);
        }
    }
    srand(time(NULL));
    structure s(5,600000,num_hashtable);
    string line;
    ifstream myfile (input_file);
    if (myfile.is_open())
    {
    	while ( getline (myfile,line) )
    {
        std::stringstream iss;
        iss<<line;
        getline(iss, line, ' ');

	if(line=="i")
	{
		getline(iss, line, ' ');
		int a=atoi(line.c_str());
		getline(iss, line, ' ');
		string b= line;
		getline(iss, line, ' ');
		string c= line;
		getline(iss, line, ' ');
		float d= atof(line.c_str());
		getline(iss, line, ' ');
		int e=atoi(line.c_str());
		getline(iss, line, ' ');
		string f= line;
		getline(iss, line, ' ');
		int g=atoi(line.c_str());
		s.insert_stud(a,b,c,d,e,f,g);
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<endl;
	}
	else if(line=="m")
	{
		getline(iss, line, ' ');
		int a=atoi(line.c_str());
		getline(iss, line, ' ');
		float b= atof(line.c_str());
		getline(iss, line, ' ');
		int c=atoi(line.c_str());
		s.modify(a,b,c);
	}
	else if(line=="d")
	{
		getline(iss, line, ' ');
		int a=atoi(line.c_str());
		s.delete_studid(a);
	}
	else if(line=="q")
	{
		getline(iss, line, ' ');
		int a=atoi(line.c_str());
		s.query(a);
	}
	else if(line=="ra")
	{
		getline(iss, line, ' ');
		int a=atoi(line.c_str());
		getline(iss, line, ' ');
		int b=atoi(line.c_str());
		s.raverage(a,b);
	}
	else if(line=="a")
	{
		getline(iss, line, ' ');
		getline(iss, line, ' ');
		int a=atoi(line.c_str());
		s.average(a);
	}
	else if(line=="ta")
	{
		getline(iss, line, ' ');
		int a=atoi(line.c_str());
		getline(iss, line, ' ');
		int b=atoi(line.c_str());
		s.taverage(a,b);
	}
	else if(line=="b")
	{
		getline(iss, line, ' ');
		int a=atoi(line.c_str());
		s.bottom(a);
	}
	else if(line=="ct")
	{
		getline(iss, line, ' ');
		int a=atoi(line.c_str());
		getline(iss, line, ' ');
		string b=line;
		s.ct(a,b);
	}
	else if(line=="f")
	{
		getline(iss, line, ' ');
		int a=atof(line.c_str());
		s.find_gpa(a);
	}
	else if(line=="p")
	{
		getline(iss, line, ' ');
		int a=atof(line.c_str());
		s.percentile(a);
	}
	else if(line=="pe")
	{
		s.percentiles();
	}
	else if(line=="e")
	{
		cout<<"e"<<endl;
		return -1;
	}
    }
    	myfile.close();
    }
    else cout << "Unable to open file"<<endl;
 
    return 0;
}
