#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[510];
long long f[510][510],w[500010];
vector<int> z[500010];
map<int,long long> ti[500];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			cin>>x>>y;
			ti[i][x]=y;
			z[x].push_back(i);
		}
	}
	for(int i=1;i<=501;i++)
		for(int j=1;j<=501;j++)
			f[i][j]=1e15;
	for(int i=1;i<=501;i++)
		f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int x:z[i])
		{
			for(int y:z[i])
			{
				if(x==y)
					continue;
				f[x][y]=min(f[x][y],ti[x][i]+ti[y][i]);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long s=1e15;
		for(int i:z[x])
			for(int j:z[y])
				s=min(s,f[i][j]+ti[i][x]+ti[j][y]);
		cout<<s+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/