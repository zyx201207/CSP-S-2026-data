#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	long long c=0,maxn=0,a,s,d[100000000];
	cin>>a>>s;
	for(int i=1;i<=a;i++)
	{
		cin>>d[i];
	}
	for(int i=1;i<=a-s;i++)
	{
		for(int j=1;j<=s;j++)
		{
			c=d[i] and d[i+1] and d[i+2];
		}
		maxn=max(maxn,c);
	}
	cout<<maxn;
	return 0;
 }
