#include<bits/stdc++.h>
using namespace std;
const int AR=2e6+710;
const int M=2e4+555;
int c,n,m,d,q,ans=0x3fff;
int x,y;
int w[M],t[600][M];
int sub[M][600],tmp[M];	//站点对应的线路 个数 
int a[600][M],k[M];		//线路对应的站点 个数 
int mk[M]={};

void dfs(int p,int x,int v,int g)//当前节点 已走过节点 花费 
{
	if(x==g)
	{
		ans=min(ans,v);
		return;
	}
	if(mk[p]) return;
	if(v>=ans) return;
	for(int i=1;i<=tmp[p];i++)	//枚举p的所有线路 
	{

		int u=sub[p][i];
		v+=t[u][p];
		for(int j=1;j<=k[u];j++)	//枚举线路u的所有站 
		{
			
			mk[p]=1;
			dfs(a[u][j],x+1,v+t[u][j],g);
			mk[p]=0;
			
		}
		v-=t[u][p];
	}
} 
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			sub[a[i][j]][++tmp[a[i][j]]]=i;
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		//-----------------------
		ans=0x3fff;
		memset(mk,0,sizeof(mk));
		dfs(x,0,0,y);	
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
 } 
