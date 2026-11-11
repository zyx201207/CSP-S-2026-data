#include <bits/stdc++.h>
using namespace std;
vector<int> e[1000005];
bool v[1000005];
struct node
{
	int d,st;	
};
queue<node> q; 
int n,k;
int s[1000005];
int ans;
int dist(int x,int y)
{
	memset(v,0,sizeof(v));
	while(!q.empty())q.pop();
	q.push({x,0});
	v[x]=1;
	while(!q.empty())
	{
		node fr=q.front();
		q.pop();
		int d=fr.d,st=fr.st;
		if(d==y) return st;
		for(int i=0;i<e[d].size();i++)
		{
			int t=e[d][i];
			if(!v[t]) 
			{
				v[t]=1;
				q.push({t,st+1});
			}
		}
	}
	return 0;
}
int fa[1000005];
int get(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void hebing(int x,int y)
{
	int fx=get(x),fy=get(y);
	fa[fy]=fx;
}
void f()
{
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<e[s[i]].size();j++)
		{
			int t=e[s[i]][j];
			bool f=0;
			for(int iii=1;iii<=k;iii++)
			{
				if(t==s[iii]) f=1;
			}
			if(f&&get(t)!=get(s[i])) hebing(s[i],t);
		}
	}
	int cnt=0;
	for(int i=1;i<=k;i++)
	{
		if(get(s[i])==s[i]) cnt++;
	}
	if(cnt<=2)
	{
		int ssum=0;
		int tt=1;
		for(int i=1;i<=n;i++)
		{
			if(i==s[tt]) tt++;
			else
			{
				int sum=INT_MAX;
				for(int j=1;j<=k;j++)
				{				
					int tmp=dist(i,s[j]);
					sum=min(sum,tmp);
				}
				ssum=max(sum,ssum);
			}
		}
		ans=min(ans,ssum);
	}
}
void dfs(int p,int num)
{
	if(p==k)
	{
		for(int i=1;i<=n;i++) fa[i]=i;
		f();
		return ;
	}
	for(int i=num+1;i<=n;i++)
	{
		s[p+1]=i;
		dfs(p+1,i);
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
		ans=INT_MAX;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=n-1;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(0,0);
		printf("%d\n",ans);
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
