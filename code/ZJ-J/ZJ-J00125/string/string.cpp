#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int m[10000];
	string s;
	string sum;
	int num=0;
	for(int i=0;i<n;i++)
	{
		num+=m[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>m[i];
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		sum+=s[i]*m[i];
	}
	s=sum;
	int r=0;
	for(int i=0;i<num;i++)
	{
		if(s[i]==s[num-1-i])
			r++;
	}
	if(r==num/2+1)
		cout<<0;
	
	return 0;	
}
