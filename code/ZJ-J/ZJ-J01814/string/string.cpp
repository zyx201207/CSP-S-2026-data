#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char c[N];
long long g[N];
long long n,s,t;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>g[i]>>c[i];
		s+=g[i];
	}
	long long l=1,r=n;
	while(l<r)
	{
		long long x=min(g[l],g[r]);
		if(c[l]!=c[r])
		{
			t+=x;
		}
		g[l]-=x;
		g[r]-=x;
		if(g[l]==0)
		{
			l++;
		}
		if(g[r]==0)
		{
			r--;
		}
	}
	cout<<t;
	return 0;
} 
