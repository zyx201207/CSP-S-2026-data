#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500007],jl[507];
struct N{
	int y,z;
	bool operator<(const N&tmp)const
	{
		return z>tmp.z;
	}
};
vector<N>f1[500007];
vector<N>f[507];
void dij(int st)
{
	memset(jl,0x3f,sizeof(jl));
	priority_queue<N>q1;
	jl[st]=0;
	q1.push({st,0});
	while(q1.empty()==0)
	{
		int x=q1.top().y,z1=q1.top().z;
		q1.pop();
		if(jl[x]!=z1)
		{
			continue;
		}
		for(int i=0;i<f[x].size();i++)
		{
			int y=f[x][i].y,z=f[x][i].z;
			if(jl[y]>jl[x]+z)
			{
				jl[y]=jl[x]+z;
				q1.push({y,jl[y]});
			}
		}
	}
	return ;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			f1[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<f1[i].size();j++)
		{
			for(int k=j+1;k<f1[i].size();k++)
			{
				int x=f1[i][j].y,y=f1[i][k].y,z=f1[i][j].z+f1[i][k].z;
				f[x].push_back({y,z});
				f[y].push_back({x,z});
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		f[n+1].clear();
		for(int j=0;j<f1[u].size();j++)
		{
			int y=f1[u][j].y,z=f1[u][j].z;
			f[n+1].push_back({y,z});
		}
		dij(n+1);
		int mini=1e18;
		for(int j=0;j<f1[v].size();j++)
		{
			int y=f1[v][j].y,z=f1[v][j].z;
			mini=min(mini,jl[y]+z);
		}
		cout<<mini+w[u]+w[v]<<"\n";
	}
	return 0;
}
