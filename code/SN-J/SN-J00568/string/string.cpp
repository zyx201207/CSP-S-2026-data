#include<bits/stdc++.h.>
using namespace std;

int main()
{
	long long w=0;
	long long t=0;
	long long a;
	cin>>a;
	char b;
	long long c;
	string d;
	long long e=0;
	for(long long i=0;i<a;i++)
	{
		cin>>c>>b;
		w+=c;
		for(long long j=0;j<c;j++)
		{
			d[e]=b;
			e++;
		}
	}
	if(a%2==1)
	{
		for(long long i=0;i<w/2;i++)
		{
			if(d[i]!=d[i+w/2+1])
			{
				t++;
			}
		}
	}
	else
	{
		for(long long i=0;i<w/2;i++)
		{
			if(d[i]!=d[i+w/2])
			{
				t++;
			}
		}
	}
	cout<<t;
	return 0;
}
