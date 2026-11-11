#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[999];
	char a1[999];
	string b;
	freopen(string.in,"r",stdin);
	freopen(string.out,"w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>a1[i];
		for(int j=0;j<a[i];j++)
		{
			b+=a1[i];
		}
	}
	bool c=1;
	int sum=0;
	for(int i=0;i<b.length();i++)
	{
		if(b[i]!=b[b.length()-1-i])
		{
			c=0;
			sum++;
		}
	}
	if(c)
	{
		cout<<0;
	}
	else
	{
		cout<<sum/2;
	}
	return 0; 
} 
