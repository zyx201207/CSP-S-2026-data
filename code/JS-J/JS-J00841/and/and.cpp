#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200050], maxnn=0;
int n, m;
void dfs(int x, int cnt, ll sum)
{
	if(cnt==0)
	{
		maxnn=max(maxnn, sum);
		return;
	}
	for(int i=x+1; i<=n-cnt+1; i++)
	{
		dfs(i, cnt-1, sum&a[i]);
	}
	return;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	bool b=1;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		if(a[i]!=i-1)
		{
			b=0;
		}
	}
	if(b)
	{
		cout<<n-m;
		return 0;
	}
	dfs(0, m, LLONG_MAX);
	cout<<maxnn;
	return 0;
}
