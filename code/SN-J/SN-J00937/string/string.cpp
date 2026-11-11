#include <bits/stdc++.h>
using namespace std;
int main()
{
	preopen("string.in","r",stdin)
    preopen("string.out","w",stdout)
	int n,a,x=0,z;
	string b,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		x+=a;
		for(int j=1;j<=a;j++)
		{
			m=m+b;
		}
	}
	for(int i=0;i<x/2;i++)
	{
		if(m[i]!=m[x-i])
		{
			z++;
		}
	}
	cout<<z;
}
