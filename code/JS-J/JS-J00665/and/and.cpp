#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long a[N],maxn=-1;
int n,k;
void dfs(int vv,int last,long long sum)
{
	if(vv>k)
	{
		maxn=max(sum,maxn);
		return;
	}
	for(int i=last+1;i<=n;i++)
	{
		if(vv==1)
			dfs(vv+1,i,a[i]);
		else
			dfs(vv+1,i,sum&a[i]);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
	}
	else if(n==k)
	{
		maxn=a[1];
		for(int i=2;i<=n;i++)
		{
			maxn=maxn&a[i];
		}
	}
	else
	{
		dfs(1,0,0);
	}
	cout<<maxn;
	return 0;
}
//rp++
