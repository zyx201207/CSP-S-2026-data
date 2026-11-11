//17:11T1不想写，来看T4 
//诶？感觉似乎会做了？？？？？？？
//为什么我的做法这么直接，会不会有问题？
//nlog应该不会超时吧…… 
//不管了先写
//17:21坏了做法假了，正好会做T1了 
#include<bits/stdc++.h>
#define DEBUG 
#define N 1000005
using namespace std;
int c,t,n,m;
vector<int>ed[N];
int fa[N],dep[N];
void dfs(int now,int f)
{
	fa[now]=f;
	dep[now]=dep[f]+1;
}
int main()
{
	#ifndef DEBUG
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	#endif
	cin >> c >> t;
	for(int i = 1;i <= n;i++)
	{
		cin >> n >> m;
		for(int i = 1;i <= n;i++)
		{
			ed[i].clear();
		}
		for(int i = 1;i <= m;i++)
		{
			int u,v;
			cin >> u >> v;
			ed[u].push_back(v);
			ed[v].push_back(u);
		}
		dfs(1,0);
	}
}
