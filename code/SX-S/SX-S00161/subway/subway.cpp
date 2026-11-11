#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int w[500005],t[505][500005],floyd[5005][5005],cnt[500005];
vector<int>vv[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(t,0x3f,sizeof(t));
	memset(floyd,0x3f,sizeof(floyd));
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
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
			int u,v;
			cin>>u>>v;
			t[i][u]=v;
			vv[u].push_back(i);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==j) continue;
			for(int k=0;k<vv[i].size();k++)
			{
				int x=vv[i][k];
				if(t[x][j]<=1e9)
				{
					floyd[i][j]=min(floyd[i][j],t[x][i]+t[x][j]);
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==j) continue;
			for(int k=1;k<=m;k++)
			{
				floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<floyd[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}