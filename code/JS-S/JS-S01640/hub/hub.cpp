#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int u,v,ans;
vector<int> to[15];
bool vis[15];
bool df[15];
void dfs(int r)
{
	df[r]=false;
	for(auto&&i:to[r])
		if(df[i])
			dfs(i);
}
struct node
{
	int first,second;
	const bool operator<(node a)
	{
		return first<a.first;
	}
};
priority_queue<node> q;
void check()
{
	for(int i=1;i<=n;i++)
		df[i]=vis[i];
	int has=0;
	for(int i=1;i<=n;i++)
	{
		if(df[i])
			has++,dfs(i);
	}
	if(has>2)
		return;
	int ansss=0;
	for(int i=1;i<=n;i++)
		if(vis[i])
		{
			q.push({0,i});
			vis[i]=false;
		}
	while(q.size())
	{
		node t=q.top();
		q.pop();
		if(vis[t.second])
			continue;
		ansss=max(ansss,t.first);
		vis[t.first]=true;
		for(auto&&i:to[t.second])
			if(vis[i]==false)
				q.push({t.first+1,i});
	}
	ans=min(ansss,ans);
}
void find(int i,int use)
{
	if(use>k)
		return;
	if(i==n+1)
	{
		if(use==k)
			check();
		return;
	}
	find(i+1,use);
	vis[i]=true;
	find(i+1,use+1);
	vis[i]=false;
}
int main()
{
	freopen("hub1.in","r",stdin);
	//freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			to[u].push_back(v);
			to[v].push_back(u);
		}
		ans=0x3f3f3f3f;
		find(1,0);
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			to[i].clear();
	}
	return 0;
}
