#include <bits/stdc++.h>
using namespace std;

int main(){
	int c1;
	int c2;
	string s1;
	string s2;
	cin>>c1;
	cin>>c2;
	cin>>s1;
	cin>>s2;
	if (c1==c2)
	{
		cout<<'1';
	}
	else{
		cout<<'0000';
		return 0;
	}
	if (s1[0]==s2[0] && s1[1]==s2[1])
	{
		cout<<'1';
	}
	else{
		cout<<'000';
		return 0;
	}
	if(s1[2]=='C' && s2[2]=='D')
		cout<<'00';
		return 0;
 	if(s1[2]=='D' && s2[2]=='C')
	{
		cout<<'00';
		return 0;
	}
	else 
	{
		cout<<'1';
	}
	return 0;
}
