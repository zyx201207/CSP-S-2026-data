#include<bits/stdc++.h>
using namespace std;
set<int> a;
struct ZH{
	int p,k_ti,ti_t[25];
}zh[100005];
int hao[100005][25];
int vis[100005];
vector<int> g[100005];
int ans=100005;
int c,n,m,d,q;
void dfs(int x,int y,int step,int h)
{
	//if(x==y) cout<<step+zh[y].ti_t[h]+zh[y].k_ti<<" ";
	//cout<<x<<" ";
	vis[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int nex=g[x][i];
		if(vis[nex]==1) continue; 
		cout<<nex<<" ";
		if(hao[nex][h]==0) 
		{
			for(int j=1;j<=n;j++)
			{
				if(hao[nex][j]==1)
				{
					if(nex==y && step+zh[y].ti_t[h]+zh[y].k_ti<ans)
					{
						ans=step+zh[nex].ti_t[j]+zh[nex].k_ti+zh[x].ti_t[h]+zh[x].ti_t[j];
						return ;
						//cout<<1;
					} 
					//cout<<nex<<" "<<j;
					else dfs(nex,y,zh[x].ti_t[h]+zh[x].ti_t[j],j);
				}
					
			}
		}
		else 
		{
			if(nex==y && step+zh[y].ti_t[h]+zh[y].k_ti<ans)
			{
				ans=step+zh[y].ti_t[h]+zh[y].k_ti;
				return ;
				//cout<<1;
			} 
			else dfs(nex,y,step,h);
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&zh[i].k_ti);
	for(int i=1;i<=n;i++)
	{
		int w;
		scanf("%d",&w);
		int s=0;
		for(int j=1;j<=w;j++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			hao[a][i]=1;
			zh[a].ti_t[i]=b;
			if(j==1) s=a;
			else
			{
				g[a].push_back(s);
				g[s].push_back(a);
			} 
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ans=100005;
		for(int j=1;j<=n;j++)
		{
			if(hao[x][j]==1)
			{
				//cout<<x<<" "<<j; 
				dfs(x,y,zh[x].k_ti+zh[x].ti_t[j],j);
			}
				
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++) vis[i]=0;
	}
	return 0;
} 
/*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2*/
 /* 0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
 3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
 1 6
 2 3*/