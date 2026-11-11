#include <bits/stdc++.h>
using namespace std;
string a[100];
string s[3];
string n[3];
int main() 
{
	for(int i=1;i<=4;i++)
	{
		cin>>a[i];
	}
	if(a[1]==a[3])
	{
		cout<<1;
	}
	else
	{
		for(int i=1;i<=4;i++)
		{
			cout<<0;
		}
		return 0;
	}
	
	return 0; 
 } 
