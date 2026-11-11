#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e4+5;
const ll INF=0x3f;
ll w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	vector<pair<int,int> > edge[N+500];
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		for(int j=1;j<=k;++j){
			int a,t;cin>>a>>t;
			edge[i].push_back({a+500,t});
			edge[a+500].push_back({i,t});
			//cout<<i<<' '<<a+500<<' '<<t<<'\n';
		}
	}
	while(q--){
		int start,end;cin>>start>>end;
		ll ans=0;
		ans+=w[start]+w[end];
		ll dis[N+500];
		memset(dis,INF,sizeof(dis));
		priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >pq;
		pq.push({0,start+500});
		while(!pq.empty()){
			pair<ll,int> top=pq.top();pq.pop();
			ll d=top.first;int u=top.second;
			if(d>dis[u])continue;
			for(int j=0;j<(int)edge[u].size();++j){
				int v=edge[u][j].first,w=edge[u][j].second;
				ll nd=d+w;
				if(nd<dis[v]){
					dis[v]=nd;
					pq.push({nd,v});
				}
			}
		}
		ans+=dis[end+500];
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
