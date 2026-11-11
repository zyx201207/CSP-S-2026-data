#include<bits/stdc++.h>
using namespace std;

#define int long long

// zazhemenanwww

int dis[5005][5005];
bool inq[40005];
int w[40005], minn[5005][5005], a[505][5005], t[505][5005];
vector<pair<int, int>> e[5005];
int c, n, m, d, q;

void dij(int s)
{
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		inq[u]=false;
		for(auto v:e[u])
		{
			//cerr<<"dis["<<i<<"]: "<<dis[u]+minn[u][i]<<'\n';
			if(dis[s][v.first]<=dis[s][u]+v.second)continue;
			//if(i==t)cout<<"awa"<<endl;
			dis[s][v.first]=dis[s][u]+v.second;
			//cerr<<"dis["<<i<<"]: "<<dis[i]<<'\n';
			if(!inq[v.first])q.push(v.first);
			//cout<<i<<'\n';
			inq[v.first]=true;
		}
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//freopen("subway.err","w",stderr);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(minn, 0x3a, sizeof minn);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)
	{
		cin>>w[i];
		if(d!=2)minn[i][i]=0;
	}
	for(int i=1; i<=n; i++)
	{
		int k;
		cin>>k;
		for(int j=1; j<=k; j++)
		{
			cin>>a[i][j]>>t[i][j];
			for(int l=1; l<j; l++)
			{
				minn[a[i][l]][a[i][j]]=min(minn[a[i][l]][a[i][j]], t[i][l]+t[i][j]);
				minn[a[i][j]][a[i][l]]=min(minn[a[i][j]][a[i][l]], t[i][j]+t[i][l]);
				//cerr<<"from: "<<a[i][l]<<" to: "<<a[i][j]<<" il: "<<t[i][l]<<" ij: "<<t[i][j]<<endl;
			}
		}
	}
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=m; j++)
		{
			dis[i][j]=1e18;
			if(minn[i][j]<2e9)e[i].push_back(make_pair(j, minn[i][j]));
		} 
	}
	while(q--)
	{
		int x, y;
		cin>>x>>y;
		bool flag=false;
		for(int i=1; i<=m; i++)
		{
			inq[i]=false;
			//cout<<"dis[x][i]: "<<dis[x][i]<<" ";
			if(dis[x][i]<=1e10)flag=true;
		}
		dis[x][x]=0;
		if(flag==false)
		{
			dij(x);
		}
		//cout<<"dis: "<<dis[x][y];
		cout<<w[x]+dis[x][y]+w[y]<<"\n";
	}
	return 0;
}
