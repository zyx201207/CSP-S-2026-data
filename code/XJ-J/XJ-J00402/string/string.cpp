#include <bits/stdc++.h>
using namespace std;
string S;
int zs(string a,long long i)
{
	if(a[i]!=a[a.size()-i])return 0;
	return 1;
}
int main()
{
	long long cnt=0,n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long x;
		string y;
		cin>>x>>y;
		for(int j=0;j<x;j++)
		{
			S+=y;
		}
	}
	for(int i=0;i<(S.size())/2;i++)
	{
		if(zs(S,i)==0)
		{
			cnt++;
		}
	}
	cout<<cnt;
	
	
	return 0;
}
