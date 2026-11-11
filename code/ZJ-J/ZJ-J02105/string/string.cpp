#include <bits/stdc++.h>
using namespace std;
vector<char> a;
long long n;
int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		char y;
		cin>>y;
		for(long long j=0;j<x;j++)
		{
			a.push_back(y);
		}
	}
	long long ans=0;
	for(long long i=0;i<=(a.size()-1)/2;i++)
	{
		if(a[i]!=a[a.size()-1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}