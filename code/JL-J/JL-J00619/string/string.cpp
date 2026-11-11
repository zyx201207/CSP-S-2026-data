#include<bits/stdc++.h>
using namespace std;
char c[1000000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,d,e=1;
	char b;
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>d>>b;
		for(int j=1;j<=d;j++)
		{
			c[e]=b;
			e++;
		}
	}
	e-=1;
	int f=0;
	for(int i=1;i<=e/2;i++)
	{
		if(c[i]!=c[e-i+1])
		{
			f++;
		}
	}
	cout<<f;
	
	return 0;
}
