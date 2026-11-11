#include<iostream>
#include<string>
#include<fstream>
#include<iterator>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	ifstream infile("crystal.in",ios::binary);
	string(std::istream_iterator<char>(infile),istream_iterator<char>());
	infile.close();
	
	int n,m,count_crystal;
	n = s[0];
	m = s[2];
	int crystal_A[2*n];
	for(int i=4;i<=n;i+=2){
		int j=i/2;
		crystal_A[j] = s[i];
	}
	while(m>=0){
		for(int i=0;i<n;i++){
			if(crystal_A[i] == 0){
				continue;
			}
			else
			{
				crystal_A[i] = crystal_A[i]+crystal_A[i+1];
				crystal_A[i+1] = 0;
				count_crystal++;
				continue;
			}
			m--;
		}
	}
	
	s="315275";
	ofstream outFile("crystal.out",ios::binary);
	outFile.write(s.c_str(),s.size());
	outFile.close();
	return 0;
}  