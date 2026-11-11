#include<bits/stdc++.h>
#define inf 1145141919817LL
using namespace std;
long long c,n,m,d,q,w[514514],s[514][514];
vector<pair<long long,long long>>st[514514];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j) s[i][j]=s[j][i]=inf;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(long long j=1,a,t;j<=k;j++)
		{
			cin>>a>>t;
			st[a].push_back({i,t});
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=0;i<st[k].size()-1;i++)
		{
			for(int j=i+1;j<st[k].size();j++)
			{
				s[st[k][i].first][st[k][j].first]=s[st[k][j].first][st[k][i].first]=min(s[st[k][i].first][st[k][j].first],st[k][i].second+st[k][j].second);
			}
		}
	}
	//floyd
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
			}
		}
	}
	while(q--)
	{
		long long x,y,ans=inf;
		cin>>x>>y;
		for(int i=0;i<st[x].size();i++)
		{
			for(int j=0;j<st[y].size();j++)
			{
				ans=min(ans,s[st[x][i].first][st[y][j].first]+st[x][i].second+st[y][j].second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
cd ..
cd subway
g++ -O2 -std=c++14 -static subway.cpp -o subway
time ./subway

*/