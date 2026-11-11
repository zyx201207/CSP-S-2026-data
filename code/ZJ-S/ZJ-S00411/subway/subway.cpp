#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N=512,M=5e5+100;

struct node { int v; ll w; } t[M][21];
int idx[M];

int c,n,m,d,q;
ll w[M];
ll g[N][N];

void init()
{
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++)
	{	
		int k=0;
		cin>>k;
		
		for(int j=1;j<=k;j++)
		{
			int aij=0,tij=0;
			cin>>aij>>tij;
			
			idx[aij]++;
			t[aij][idx[aij]].v=i;
			t[aij][idx[aij]].w=tij;
		}
	}
	
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			g[i][j]=g[j][i]=-1;
	
	for(int i=1;i<=m;i++)
	{
		for(int x=1;x<=idx[i];x++)
		{
			for(int y=1;y<=idx[i];y++)
			{
				int X=t[i][x].v, Y=t[i][y].v;
				ll w1=t[i][x].w,w2=t[i][y].w;
				if(g[X][Y]==-1 || g[X][Y]>w1+w2) g[X][Y]=w1+w2;
			}
		}
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(g[i][k]==-1) continue;
			
			for(int j=1;j<=n;j++)
			{
				if(g[k][j]==-1) continue;
				
				if(g[i][j]==-1 || g[i][j]>g[i][k]+g[k][j])
					g[i][j]=g[i][k]+g[k][j];
			}	
		}
	}
}

void solve()
{
	int l=0,r=0;
	cin>>l>>r;
	
	ll ans=1e12;
	
	for(int i=1;i<=idx[l];i++)
	{
		for(int j=1;j<=idx[r];j++)
		{
			int I=t[l][i].v, J=t[r][j].v;
			ll w1=t[l][i].w,w2=t[r][j].w;
			ll sum=w[l]+w1+g[I][J]+w2+w[r];
			
			if(ans>sum) ans=sum;
		}
	}
	
	cout<<ans<<"\n";
}

signed main()
{
	freopen("subway.in" ,"r",stdin );
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	init();
	while(q--) solve();

	return 0;
}
