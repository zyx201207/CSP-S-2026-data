#include<bits/stdc++.h>
using namespace std;

#define int long long
int c,n,m,d,Q,w[500005],cnt[500005];
vector<pair<int,int>>edge[505],st[505];
vector<pair<pair<int,int>,int>>q;
bool cmp1(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b)
{
	if(a.first.first!=b.first.first)
	{
		return a.first.first<b.first.first;
	}
	return a.first.second<b.first.second;
}
bool cmp2(pair<int,int>a,pair<int,int>b)
{
	return a.first<b.first;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1; i<=m; i++)
	{
		cin>>w[i];
	}
	for(int i=1; i<=n; i++)
	{
		int k;
		cin>>k;
		for(int j=1; j<=k; j++)
		{
			int a,t;
			cin>>a>>t;
			edge[a].push_back(make_pair(m+i,t));
			edge[m+i].push_back(make_pair(a,t));
		}
	}
	for(int i=1; i<=Q; i++)
	{
		int x,y;
		cin>>x>>y;
		q.push_back(make_pair(make_pair(x,y),i));
	}
	sort(q.begin(),q.end(),cmp1);
	for(int i=0; i<q.size(); i++)
	{
		if(q[i].first.first>q[i].first.second)
		{
			int t=q[i].first.first;
			q[i].first.first=q[i].first.second;
			q[i].first.second=t;
		}
		st[q[i].first.first].push_back(make_pair(q[i].second,q[i].first.second));
	}
	for(int i=1; i<=m; i++)
	{
		if(st[i].size())
		{
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>qp;
			qp.push(make_pair(0,i));
			for(int i=1; i<=m+n; i++)
			{
				cnt[i]=0x3f3f3f3f3f;
			}
			cnt[i]=-1;
			while(!qp.empty())
			{
				int u=qp.top().second,sum=qp.top().first;
				qp.pop();
				for(int i=0; i<edge[u].size(); i++)
				{
					int v=edge[u][i].first,w=edge[u][i].second;
					if(cnt[v]>sum+w)
					{
//						cout<<u<<' '<<v<<' '<<sum<<' '<<w<<'\n';
						cnt[v]=sum+w;
						qp.push(make_pair(cnt[v],v));
					}
				}
			}
			for(int j=0; j<st[i].size(); j++)
			{
				st[i][j].second=cnt[st[i][j].second]+w[i]+w[st[i][j].second];
			}
		}
	}

	vector<pair<int,int>>tmp;
	for(int i=1; i<=m; i++)
	{
		for(int j=0; j<st[i].size(); j++)
		{
			tmp.push_back(st[i][j]);
		}
	}
	sort(tmp.begin(),tmp.end(),cmp2);

	for(int i=0; i<tmp.size(); i++)
	{
		cout<<tmp[i].second<<'\n';
	}
	return 0;
}

