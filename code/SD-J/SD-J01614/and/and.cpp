#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
long long n,m,a[N+5],maxn=-2;
void f(int cs,int la,long long las)
{
	if(cs>m)
	{
		maxn=max(maxn,las);
	}
	if(las==-1)
	{
		for(int i=1;i<=n;i++)
		{
			f(cs+1,i,a[i]);
		}
	}
	else
	{
		for(int i=la+1;i<=n;i++)
		{
			f(cs+1,i,las&a[i]);
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f(1,1,-1);
	cout<<maxn;
	return 0;
}
