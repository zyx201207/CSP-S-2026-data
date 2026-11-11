#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,s;
	cin>>a>>s;
	int z[a];
	for(int i=0;i<a;i++)
	{
		cin>>z[i];
	}
	for(int i=0;i<a;i++)
	{
		for(int i=0;i<s;i++)
		{
			z[i]=z[i] and z[i+1];
		}
	}
	int max;
	for(int i=0;i<a;i++)
	{
		if(z[i]>max)
		{
			max=z[i];
		}
	}
	cout<<max;
}
