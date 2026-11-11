#include<iostream>
#include<string>
#include<fstream>
#include<iterator>
using namespace std;
int main()
{
	string s;
	ifstream infile("crystal.in",ios::binary);
	string(std::istream_iterator<char>(infile),istream_iterator<char>());
	infile.close();
	
	s="1/n2";
	
	ofstream outFile("crystal.out",ios::binary);
	outFile.write(s.c_str(),s.size());
	outFile.close();
	return 0;
}                       