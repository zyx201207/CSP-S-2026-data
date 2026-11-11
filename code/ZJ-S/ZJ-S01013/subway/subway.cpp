#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long ans=0;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >Q;
long long w[500001];
long long k[501];
vector<int> a[501];
int t[501][500005];
bool l[501][500005];
int ways[501][501];
bool way[501][501];
vector<int> station[501];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++)
		{
			int ai,ti;
			cin>>ai>>ti;
			a[i].push_back(ai);
			t[i][ai]=ti;
			station[ai].push_back(i);
			l[i][ai]=true;
		}
	}
	for(int i=1;i<=n;i++)
	{
		Q.push({0,i});
		while(!Q.empty())
		{
			int xl=Q.top().second;
			int yl=Q.top().first;
			Q.pop();
			if(way[i][xl]==true)continue;
			way[i][xl]=true;
			for(int j=0;j<k[xl];j++)
			{
				for(int s=0;s<station[a[xl][j]].size();s++)
				{
					int next=station[a[xl][j]][s];
					if(next==xl||next==i)continue;
					if(way[i][next]==false)
					{
						if(ways[i][next]>ways[i][xl]+t[i][a[xl][j]]+t[next][a[xl][j]]||ways[i][next]==0)
						{
							
							ways[i][next]=ways[i][xl]+t[xl][a[xl][j]]+t[next][a[xl][j]];
							Q.push({ways[i][next],next});
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ways[i][i]=0;
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=0;
		for(int i=0;i<station[x].size();i++)
		{
			for(int j=0;j<station[y].size();j++)
			{
				int r1=station[x][i];
				int r2=station[y][j];
				if(ans==0)
				{
					ans=ways[r1][r2]+t[r1][x]+t[r2][y];
				}
				else ans=min(ways[r1][r2]+t[r1][x]+t[r2][y],ans);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
