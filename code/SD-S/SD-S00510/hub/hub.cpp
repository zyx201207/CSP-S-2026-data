#include<bits/stdc++.h>
using namespace std;//二分 + ？ 看不出来所以骗分 
int n,k,x,y,s1,s2,d[2000050],maxx;
vector<int> e[2000050];
void dfs(int x,int _last)
{
	d[x] = d[_last] + 1;
	for(auto i : e[x])
	{
		if(i == _last)continue;
		dfs(i,x);
	}
	return;
}
void init()
{
	for(int i = 1;i <= n;i++)
	{
		e[i].clear();
		d[i] = 0;
	}
	s1 = s2 = 0;
	maxx = 0;
	return;
}
void solve()
{
	init();
	cin >> n >> k;
	for(int i = 1;i <= n - 1;i++)
	{
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	d[0] = -1;
	dfs(1,0);
	for(int i = 1;i <= n;i++)
	{
		if(maxx < d[i])
		{
			s1 = i;
			maxx = d[i];
		}
	}
	dfs(s1,0);
	maxx = 0;
	for(int i = 1;i <= n;i++)
	{
		if(maxx < d[i])
		{
			s2 = i;
			maxx = d[i];
		}
	}
	cout << (maxx - k + 3) / 4 << "\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)solve(); 
	return 0;
}
