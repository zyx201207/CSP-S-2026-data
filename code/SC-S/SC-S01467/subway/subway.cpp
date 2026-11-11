#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,m,d,q;
const int N=505,M=5e5+5;
int k[N];
int is[N+M];
vector<vector<int>> dis;
vector<vector<int>> ve;//用于判断每个站点与路线相连
vector<vector<pii>> G;
struct Node
{
	int first,second,num;
}Q[100005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin>>c>>n>>m>>d>>q;
	vector<vector<int>> t(n+1);
	vector<int> w(m+1);
	ve.resize(m+1);
	G.resize(n+m+1);
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		t[i].resize(m+1);
		for(int j=1;j<=k[i];j++)
		{
			int x;
			cin>>x;
			ve[x].push_back(i);
			cin>>t[i][x];
		}
	}
	//线路为i+m
	for(int i=1;i<=m;i++)
	{
		if(!ve[i].empty()&&ve[i].size()>1)
		{
			for(int u:ve[i])
			{
				G[i].push_back({u+m,t[u][i]});
				G[u+m].push_back({i,t[u][i]});
			}
		}
	}
	vector<int> cnt(n+m+1);
	vector<long long> ans(q+1,0);
	for(int i=1;i<=q;i++)
	{
		cin>>Q[i].first>>Q[i].second;
		Q[i].num=i;
		int &x=Q[i].first,&y=Q[i].second;
		ans[i]+=w[x]+w[y];
		if(ve[x].size()==1)
		{
			cnt[ve[x][0]+m]+=1;
			ans[i]+=t[ve[x][0]][x];
			x=ve[x][0]+m;
		}
		else
			cnt[x]+=1;
		if(ve[y].size()==1)
		{
			cnt[ve[y][0]+m]+=1;
			ans[i]+=t[ve[y][0]][y];
			y=ve[y][0]+m;
		}
		else
			cnt[y]+=1;
	}
//	cout<<"x";
	vector<long long> d(n+m+1,LONG_LONG_MAX);
	priority_queue<pii,vector<pii>,greater<pii>> qu;
	for(int i=1;i<=q;i++)
	{
		if(cnt[Q[i].first]<cnt[Q[i].second])
			swap(Q[i].first,Q[i].second);
	}
	sort(Q+1,Q+1+q,[](Node &X,Node &Y){return X.first<Y.first;});
	int x=-1,y;
	for(int i=1;i<=q;i++)
	{
		y=Q[i].second;
		if(x!=Q[i].first)
		{
			x=Q[i].first;
			//最短路;
			for(int i=0;i<=n+m;i++)
				d[i]=LONG_LONG_MAX;
			d[x]=0;
			qu.push({d[x],x});
			while(!qu.empty())
			{
				int u=qu.top().second;
				qu.pop();
				for(auto [v,w]:G[u])
				{
					if(d[v]>d[u]+w)
					{
						d[v]=d[u]+w;
						qu.push({d[v],v});
					}
				}
			}
		}
		ans[Q[i].num]+=d[y];
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
}