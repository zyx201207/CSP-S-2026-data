#include<bits/stdc++.h>
using namespace std;
const long long M=1e18;
long long c,n,m,d,Q;
long long k,v,w,s,t;
long long a[501010],minn;
map<long long,long long> dis[501010];
vector<pair<long long,long long>> f[501010];
priority_queue<pair<long long,long long>, vector<pair<long long,long long>> ,greater<pair<long long,long long>> > q;
void dijst(long long ss)
{
	while(!q.empty())
	{
		q.pop();
	}
	q.push({0,ss});
	dis[ss][ss]=0;
	while(!q.empty())
	{
		pair<long long,long long> tot=q.top();
	//	cout<<tot.first<<' '<<tot.second<<'\n';
		q.pop();
		for(int i=0;i<f[tot.second].size();i++)
		{
			long long vv=f[tot.second][i].first;
			long long ww=f[tot.second][i].second;
			if(!dis[ss].count(vv))
			{
				dis[ss][vv]=ww+tot.first;
				q.push({dis[ss][vv],vv});
			}
			else if(ww+tot.first<dis[ss][vv])
			{
				dis[ss][vv]=ww+tot.first;
				q.push({dis[ss][vv],vv});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>v>>w;
			f[v].push_back({(long long)(m+i),w});
			f[(int)(m+i)].push_back({v,w});
		}
	}
	for(int i=1;i<=n;i++)
	{
		dijst(i+m);
	}
//	cout<<Q<<'\n';
	while(Q--)
	{
		cin>>s>>t;
		minn=M;
		for(int i=0;i<f[s].size();i++)
		{
			minn=min(f[s][i].second+dis[f[s][i].first][t],minn);
		}
		cout<<minn+a[s]+a[t]<<'\n';
	}
	return 0;
}                                        
