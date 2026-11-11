#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e5+10;
const ll inf=1e18+10;
ll c,n,m,d,q;
ll w[maxn];
ll dd[maxn];
ll s[maxn],t[maxn];
vector<pair<ll,ll>>G[maxn];
ll dist[maxn];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>qu;
void dij(ll x){
	for(ll i=0;i<=2*m+d*m;i++){
		dist[i]=inf;
	}
	dist[x]=0;
	qu.push({0,x});
	while(!qu.empty()){
		auto now=qu.top();
		qu.pop();
//		cout<<now.first<<" "<<now.second<<"\n";
		if(now.first>dist[now.second]){
			continue;
		}
		for(auto &it:G[now.second]){
			if(dist[it.second]>dist[now.second]+it.first){
				dist[it.second]=dist[now.second]+it.first;
				qu.push({dist[it.second],it.second});
//				cout<<it.second<<" "<<now.second<<" "<<it.first<<" "<<dist[it.second]<<" "<<dist[now.second]<<" "<<it.first<<"\n";
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
////////////////////////////////////////////////////////////////////
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
		G[i].push_back({w[i],m+i});
		G[i+m].push_back({w[i],i});
//		cout<<"1111  "<<i<<" "<<i+m<<"\n";
		
//	cout<<"\n\n\n\n";
//	for(ll i=1;i<=2*m+d*m;i++){
//		for(auto &it:G[i]){
//			cout<<it.first<<" "<<it.second<<"----";
//		}
//		cout<<"\n";
//	}
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			cin>>s[j]>>t[j];
			dd[s[j]]++;
			G[s[j]+m].push_back({t[j],2*m+d*(s[j]-1)+dd[s[j]]});
			G[2*m+d*(s[j]-1)+dd[s[j]]].push_back({t[j],s[j]+m});
//			cout<<"2222  "<<s[j]+m<<" "<<2*m+d*(s[j]-1)+dd[s[j]]<<"\n";
		}
		for(ll j=1;j<=k;j++){
			for(ll p=j+1;p<=k;p++){
				G[2*m+d*(s[j]-1)+dd[s[j]]].push_back({0,2*m+d*(s[p]-1)+dd[s[p]]});
				G[2*m+d*(s[p]-1)+dd[s[p]]].push_back({0,2*m+d*(s[j]-1)+dd[s[j]]});
//				cout<<"3333  "<<2*m+d*(s[j]-1)+dd[s[p]]<<" "<<2*m+d*(s[j]-1)+dd[s[j]]<<"\n";
			}
		}
//		cout<<"\n";
	}
//	cout<<"\n\n\n\n";
//	for(ll i=1;i<=2*m+d*m;i++){
//		for(auto &it:G[i]){
//			cout<<it.first<<" "<<it.second<<"----";
//		}
//		cout<<"\n";
//	}
	for(ll i=1;i<=q;i++){
		ll u,v;
		cin>>u>>v;
		dij(u);
		cout<<dist[v]<<"\n";
	}
/////////////////////////////////////////////////////////////////////
//cin>>n>>m>>q;
//for(ll i=1;i<=m;i++){
//	ll u,v,w;
//	cin>>u>>v>>w;
//	G[u].push_back({w,v});
//	G[v].push_back({w,u});
//}
////cout<<G[1][1].second<<"\n\n";
//	for(ll i=1;i<=q;i++){
//		ll u,v;
//		cin>>u>>v;
//		dij(u);
//		cout<<dist[v]<<"???????????????????????????\n";
//	}
	return 0;
}
/*
5 6 3
1 2 1
1 3 10
1 4 3
2 4 1
3 5 1
4 5 1
1 5
2 5
5 2
*/
