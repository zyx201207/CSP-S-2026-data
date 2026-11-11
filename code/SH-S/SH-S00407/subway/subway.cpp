#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll w[50010];
ll k[510];
ll a[510][50010];
ll t[510][50010];
ll dis[50010];

vector<pair<ll,ll>> ma[500010];

void dd(int s,int end){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
	dis[s]=0;
	q.push({dis[s],s});
	while (!q.empty()){
		pair<ll,ll> ni= q.top();
		q.pop();
		ll d=ni.first;
		ll u=ni.second;
		if (d>dis[u]) continue;
		for (pair<ll,ll> k:ma[u]){
			ll v=k.second;
			ll ww=k.first;
			if (v!=s or v!=end) ww-=w[v];
			if (dis[v]>dis[u]+ww){
				dis[v]=dis[u]+ww;
				q.push({dis[v],v});
			}
		}
		
		
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=2;j<=k[i];j++){
			ll u=a[i][j-1];
			ll v=a[i][j];
			ma[u].push_back({2*t[i][j-1]+w[u],v});
			ma[v].push_back({2*t[i][j]+w[v],u});
		}
	}
	for (int i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		dd(x,y);
		cout<<dis[y]<<endl;
	}
	
	
	return 0;
	
}
