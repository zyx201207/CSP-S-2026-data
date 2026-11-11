#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
int c,n,m,d,q,w[N],de[N][N];
vector<pair<ll,ll> >g[505];
vector<pair<ll,ll> >jing[505];
void dij(ll st) {
	for(int i=1; i<=m; i++)de[st][i]=1e18;
	de[st][st]=0;
	queue<pair<ll,ll>> qe;
	qe.push ({0,st});
	while(!qe.empty()) {
		ll u=qe.front().second;
		qe.pop();
		for(auto xian:jing[u]) {
			ll t=xian.second;
			ll uu=xian.first;
			
			for(auto qqq:g[uu]) {
				ll v1=qqq.first,w1=qqq.second;
				if(v1==u)continue;
				if(de[st][v1]<= t+w1+de[st][u])continue;
			
				de[st][v1]=de[st][u]+t+w1;
				qe.push({de[st][v1],v1});
				
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>w[i];
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			ll a,t;
			cin>>a>>t;

			g[i].push_back({a,t});
			jing[a].push_back({i,t});
		}

	}
	
	for(int i=1; i<=m; i++) {
		dij(i);
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		cout<<w[s]+w[e]+de[s][e]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
