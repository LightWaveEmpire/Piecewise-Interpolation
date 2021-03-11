#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

#include "Core.h"

using namespace std;

Core::Core()
{

}

Core::Core(const Core &src)
{
	for(auto it=src.begin(); it!=src.end(); ++it)
		val.push_back(*it);
	for(auto it=src.tBegin(); it !=src.tEnd(); ++it)
		time.push_back(*it);
}

Core::~Core() //Deconstructor 
{

}

void Core::addTime(int t)
{
	time.push_back(t);
}

void Core::addVal(double v)
{
	val.push_back(v);
}

Core::const_iterator Core::begin() const
{
	return val.begin();
}

Core::iterator Core::begin()
{
	return val.begin();
}

Core::const_iterator Core::end() const
{
	return val.end();
}

Core::t_const_iterator Core::tBegin() const
{
	return time.begin();
}

Core::iterator Core::end()
{
	return val.end();
}

Core::t_const_iterator Core::tEnd() const
{
	return time.end();
}

double& Core::operator[] (int i)
{
	return val[i];
}

const double& Core::operator[] (int i) const
{
	return val[i];
}

void Core::display(std::ostream& outs) const
{
	for(int i=0; i< val.size(); i++)
		outs<< val[i]<<" ";
}

void Core::interpolate(string filename, string i)
{
	vector<double>::const_iterator c1 =begin();
	vector<int>::const_iterator c2 =tBegin();
	float m,b;
	ofstream outs;

	outs.open(filename+"-core-"+i+".txt");

	for(; c1!= end()-2 && c2 != tEnd()-2; ++c1, ++c2)
	{
		if (*(c2+1) != 0 && *(c1+1) != 0)
		{
			m=(*(c1+1)-(*c1))/(*(c2+1)-(*c2));
			b=(*c1)-(m*(*c2));

			outs << (*c2)<<" <= x <= "<< *(c2+1) << ";" << " y_" << (*c2)/30
			     << " = " << std::fixed << std::setprecision(4) << b << " + "<< m << "x; " << "interpolation" << endl;
		}
 	}
 	outs.close();
 }

 void Core::LinearInterp(string filename, string i)
 {
 	//x = time;
 	//y = val;

 	int t2,vt,vsum,tsum,vtsum,t2sum;
 	float m,b;

 	vector<double>::const_iterator c1 = begin();
	vector<int>::const_iterator c2 = tBegin();
 	
 	for(; c1!= end()-2 && c2 != tEnd()-2; ++c1, ++c2) //sum all values
 	{
 		tsum=tsum+(*c2);
 		vsum=vsum+(*c1);
 		vt=(*c1)*(*c2);
 		vtsum=vtsum+vt;
 		t2=(*c2)*(*c2);
 		t2sum=t2sum+t2;
 	}

 	m = (val.size()*(vtsum))-((tsum)*(val.size()*(vsum))*(t2sum))-((tsum)*(tsum)); //calculate slope
 	b = vsum - ( m * (tsum * val.size()) ); // calculate b intercept

 	ofstream outs;
	outs.open(filename+"-core-"+i+".txt", std::ios_base::app);

	outs << "\n" << "y = " << m <<"x + " << b << "; least-squares" << endl;
 	outs.close();
 }
