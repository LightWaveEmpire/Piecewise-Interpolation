#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Core.h"

using namespace std;

void corelist(string filename);

int main (int argc, char* argv[])
{

	if (argc != 2)
	{
		cout << "Insufficent information"<< endl;
		cout << "Usage: " <<argv[0] << " <filename>"<< endl;
		return 1;
	}

	string filename = argv[1];
	corelist(filename);
	return 0;
}

void corelist(string filename)
{
	ifstream ins;
	double v_c1, v_c2, v_c3, v_c4;
	Core c1, c2, c3, c4, temp;
	int i=0;

	ins.open(filename);
	if(!(ins.is_open()))
	{
		cout<< "File unable to open"<<endl;
	}
	while (!ins.eof())
	{
		ins>> v_c1>>v_c2>>v_c3>>v_c4;
		c1.addVal(v_c1);
		c1.addTime(i*30);
		c2.addVal(v_c2);
		c2.addTime(i*30);
		c3.addVal(v_c3);
		c3.addTime(i*30);
		c4.addVal(v_c4);
		c4.addTime(i*30);
		i++;
	}

	ins.close();

	c1.interpolate(filename, "0");
	c1.LinearInterp(filename, "0");
	c2.interpolate(filename, "1");
	c2.LinearInterp(filename, "1");
	c3.interpolate(filename, "2");
	c3.LinearInterp(filename, "2");
	c4.interpolate(filename, "3");
	c4.LinearInterp(filename, "3");
}