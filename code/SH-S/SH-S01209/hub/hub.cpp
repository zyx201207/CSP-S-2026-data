#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,f[55][55],a[55],ANS;
bool flag[35];
vector<int> g[35];
void Dfs(int x)
{
	flag[x]=1;
	for(auto y:g[x])
	{
		if(flag[y]==0) Dfs(y);
	}
}
int kuai(int cnt)
{
	memset(flag,0,sizeof(flag));
	int ans=0;
	for(int i=1;i<=cnt;i++)
	{
		if(flag[i]==0)
		{
			ans++;
			Dfs(i);
		}
	}
	return ans;
}
void dfs(int step,int cnt)
{
	if(cnt>k) return;
	if(step==n+1)
	{
		if(cnt!=k) return;
		if(kuai(cnt)>2) return;
		cout<<a[1]<<" "<<a[2]<<endl;
		int R=0;
		for(int i=1;i<=n;i++)
		{
			int D_i=1e9;
			bool ff=0;
			for(int j=1;j<=cnt;j++)
			{
				if(i==a[j])
				{
					ff=1;
					break;
				}
			}
			if(ff==1) continue;
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				D_i=min(D_i,f[i][j]);
			}
			R=max(R,D_i);
		}
		ANS=min(ANS,R);
	}
	dfs(step+1,cnt);
	a[cnt+1]=step;
	dfs(step+1,cnt+1);
}
int main()
{
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=n;i++) g[i].clear();
		
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			f[u][v]=1;
			f[v][u]=1;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
		{
			f[i][i]=0;
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(f[i][k]+f[k][j]<f[i][j])
					{
						f[i][j]=f[i][k]+f[k][j];
					}
				}
			}
		}
		ANS=1e9;
		dfs(1,0);
		cout<<ANS<<endl;
	}
	return 0;
}
//see you again
