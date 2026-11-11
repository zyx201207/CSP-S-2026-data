#include<bits/stdc++.h>
using namespace std;

const int N=5050;
int c,n,m,d,q;
int head[N],nxt[N],to[N],g[N],cnt=0,ans=N;
long long  w[N],t[N][N],f[N][N],p[N];
long long dp[N][N];
bool v[N];

void add(int u,int v,int w1,int w2)
{
	to[++cnt]=v;
	g[cnt]=w1+w2;
	nxt[cnt]=head[u];
	head[u]=cnt;
}

void dfs(int u,int z)
{
	dp[u][u]=0;
	if(v[z]){
		//ans=min(ans,dp[u][z]);
		return;
	}
	
	if(v[u])	{return;}
	v[u]=true;
	
	for(int e=head[u];e!=0;e=nxt[e])
	{
		int  v=to[e];
		
		dfs(v,z);
		
		dp[u][v];
	}
	
	
}


int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0,sizeof f);
	memset(head,0,sizeof head);
	memset(v,false,sizeof v);


	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int j=1;j<=n;j++)
	{
		int a,b;
		scanf("%d",&p[j]);
		for(int i=1;i<=p[j];i++)
		{
			scanf("%d %d",&a,&b);
			f[j][i]=a;
			t[j][i]=b;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=p[i];j++)
		{
			for(int k=1;k<=p[i];k++)
			{
				if(j==k)	continue;
				add(f[i][j],f[i][k],t[i][j],t[i][k]);
				add(f[i][k],f[i][j],t[i][k],t[i][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		dfs(x,y);
		printf("%d\n",ans+w[x]+w[y]);
	}
	
	return 0;
}
