#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll test_number;//有什么用？ 
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >pq;
ll n,m,d,q,w[1010],k[1010],x,y,vis[1010];
vector<ll>a[510],t[510],veca[1010],vect[1010];
int main()
{
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>test_number;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1,u,v;j<=k[i];j++)
		{
			cin>>u>>v;
			a[i].push_back(u);
			veca[u].push_back(i);
			vect[u].push_back(v);
			t[i].push_back(v);
//			cout<<u<<' '<<vect[u][vect[u].size()-1]<<'\n';
		}
	}
	while(q--)
	{
		cin>>x>>y;
		while(!pq.empty())pq.pop();
		memset(vis,0x3f3f,sizeof vis);
		for(int i=0;i<veca[x].size();++i)
		{
			pq.push({vect[x][i],veca[x][i]});
//			cout<<vect[x][i]<<' '<<veca[x][i]<<'\n';
		}
//		cout<<'\n';
//		pq.push({0,x});
		while(!pq.empty())
		{
			pair<ll,ll>tmp=pq.top();
			pq.pop();
//			cout<<tmp.first<<' '<<tmp.second<<'\n';
//			if(tmp.second==y)
//			{
//				cout<<w[x]+w[y]+tmp.first<<'\n';
//				break;
//			}
			if(vis[tmp.second]>tmp.first)vis[tmp.second]=tmp.first;
			else continue;
			bool f=0;
			for(int i=0;i<k[tmp.second];++i)
			{
				if(a[tmp.second][i]==y)
				{
					cout<<w[x]+w[y]+tmp.first+t[tmp.second][i]<<'\n';
					f=1; 
					break;
				}
				for(int j=0;j<veca[a[tmp.second][i]].size();++j)
				{
					if(vis[veca[a[tmp.second][i]][j]]<=tmp.first+t[tmp.second][i]+vect[a[tmp.second][i]][j])continue;
//					else vis[veca[a[tmp.second][i]][j]]=tmp.first+t[tmp.second][i]+vect[a[tmp.second][i]][j];
					pq.push({tmp.first+t[tmp.second][i]+vect[a[tmp.second][i]][j],veca[a[tmp.second][i]][j]});
				}
			}
			if(f)break;
		}
	}
	return 0;
}