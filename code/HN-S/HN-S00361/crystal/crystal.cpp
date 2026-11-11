#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,maxx=-1e9,maxn=-1e9;
int a[N];
int tong[N];
void dfs(int x)
{
	if(x>m)
	{
		for(int i=1;i<=maxx;i++)
		{
			maxn=max(tong[a[i]],maxn);
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]++;
		tong[a[i]]++;
		dfs(x+1);
		tong[a[i]]--;
		a[i]--;
	}
	return ;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=30;
		maxx=max(a[i],maxx);
	}
	maxx+=m;
	for(int i=1;i<=maxx;i++)
	{
		tong[i]=0;
	} 
	dfs(1);
	cout<<maxn;
	return 0;
}
/*
1

5 5
2 1 2 4 8 9

2

5 8
-3 -1 2 2 7

*/
