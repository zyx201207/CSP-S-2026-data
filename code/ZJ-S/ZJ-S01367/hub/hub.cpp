#include<bits/stdc++.h>
using namespace std;
int kkk,_,c,T,n,k,u,v,has[1010],dep[1010],MIN;
vector<int> e[1010];
int check(int now,int f,int lst)
{
	_=max(_,dep[now]-lst);
	if(has[now])
	{
		kkk=dep[now];
	}
	for(int i=0;i<e[now].size();i++)
	{
		if(e[now][i]==f)
		{
			continue;
		}
		check(e[now][i],now,(has[now]?dep[now]:lst));
		_=max(_,dep[now]-kkk);
	}
	return _;
}
void dfs(int now,int f,int cnt)
{
	if(cnt==k)
	{
		_=0;check(1,0,has[1]);
		MIN=min(MIN,_);
		return;
	}
	for(int i=0;i<e[now].size();i++)
	{
		if(e[now][i]==f)
		{
			continue;
		}
		has[now]=1;
		dfs(e[now][i],now,cnt+1);
		has[now]=0;
		dfs(e[now][i],now,cnt);
	}
}
void dfs11(int now,int f)
{
	dep[now]=dep[f]+1;
	for(int i=0;i<e[now].size();i++)
	{
		if(e[now][i]==f)
		{
			continue;
		}
		dfs11(e[now][i],now);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>T;
	while(T--)
	{
		MIN=0x3f3f3f3f; 
		for(int i=1;i<=n;i++)
		{
			e[i].clear();
		}
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs11(1,0);
		has[1]=0;
		dfs(1,0,0);
		has[1]=1;
		dfs(1,0,1);
		cout<<MIN<<"\n";
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/ 
