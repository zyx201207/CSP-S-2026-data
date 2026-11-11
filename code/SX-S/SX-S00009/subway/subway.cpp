#include<bits/stdc++.h>
using namespace std;
long long w[505],k[505],a[505][25],t[505][25],e[505][505];
map<long long,int>mp[505];
vector<int>v[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
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
			mp[i][a[i][j]]=j;
			v[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			long long minn=INT_MAX;
			for(int x=1;x<=k[i];x++)
			{
				for(int y=1;y<=k[j];y++)
				{
					if(a[i][x]==a[j][y])
					{
						minn=min(minn,t[i][x]+t[j][y]);
					}
				}
			}
			e[i][j]=e[j][i]=minn;
//			cout<<e[i][j]<<' ';
  }
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(e[i][k]==0)continue;
			for(int j=1;j<=n;j++)
			{
				if(e[j][k]==0)continue;
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	while(q--)
	{
		long long x,y;
		cin>>x>>y;
		long long minn=LLONG_MAX;
		for(int i:v[x])
		{
			for(int j:v[y])
			{
				minn=min(t[i][mp[i][x]]+t[j][mp[j][y]]+e[i][j],minn);
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			if(mp[i][x]==0)continue;
//			for(int j=1;j<=n;j++)
//			{
//				if(mp[j][y]==0)continue;
//				minn=min(t[i][mp[i][x]]+t[j][mp[j][y]]+e[i][j],minn);
//			}
//		}
		cout<<minn+w[x]+w[y]<<endl;
	}
    return 0;
}
//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
//0 3 7 20 2 8 3 6 1 7 2 9 3 1 4 2 5 5 100 3 2 6 3 1 7 2 4 3 2 5 100 4 6 6 7 1 6 2 3