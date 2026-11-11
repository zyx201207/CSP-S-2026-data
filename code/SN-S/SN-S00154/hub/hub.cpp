#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>a[1000005];
vector<int>b;
int n,k,d[1000005],mi=2e9;
bool vis[1000005],v[1000005];
queue<int>que;
bool bfs1()
{
	memset(v,0,sizeof(v));
	que.push(b[0]);
	while(!que.empty())
	{
		int h=que.front();
		que.pop();
		if(v[h])
			continue;
		v[h]=true;
		for(int i:a[h])
			if(vis[i]||!v[i])
				que.push(i);
	}
	int flag=-1;
	for(int i=0;i<k;i++)
		if(!v[b[i]])
		{
			flag=i;
			break;
		}
	if(flag==-1)
		return true;
	que.push(b[flag]);
	while(!que.empty())
	{
		int h=que.front();
		que.pop();
		if(v[h])
			continue;
		v[h]=true;
		for(int i:a[h])
			if(vis[i]||!v[i])
				que.push(i);
	}
	flag=1;
	for(int i=0;i<k;i++)
		if(!v[b[i]])
		{
			flag=0;
			break;
		}
	return flag;
}
int bfs2(int x)
{
//	if(vis[x])
//		return 0;
	memset(v,0,sizeof(v));
	memset(d,0x3f,sizeof(d));
	d[x]=0;
	v[x]=true;
	que.push(x);
	while(!que.empty())
	{
		int h=que.front();
		que.pop();
		if(v[h]||vis[h])
			continue;
		v[h]=true;
		for(int i:a[h])
			if(d[i]>d[h]+1)
				d[i]=d[h]+1,que.push(i);
	}
	int mii=2e9;
	for(int i=0;i<k;i++)
		mii=min(mii,d[b[i]]);
	return mii;
}
void dfs(int x)
{
	if(x==k)
	{
		if(!bfs1())
			return;
		int ma=-2e9;
		for(int i=0;i<n;i++)
			ma=max(ma,bfs2(i));
		mi=min(mi,ma);
		return;
	}
	for(int i=0;i<n;i++)
		if(!vis[i])
		{
			vis[i]=true;
			b.push_back(i);
			dfs(x+1);
			b.pop_back();
			vis[i]=false;
		}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		int x,y;
		scanf("%d%d",&n,&k);
		b.clear();
		for(int i=0;i<n;i++)
			a[i].clear();
		for(int i=0;i<n-1;i++)
			scanf("%d%d",&x,&y),a[x].push_back(y),a[y].push_back(x);
		dfs(0);
		printf("%d\n",mi);
	}
	return 0;
}

