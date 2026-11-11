#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,q,d,a,k[520],x,y;
vector<pair<ll,ll>> Node[524500];
ll f[520][520],w[524500],t;
//ll sos[524500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			Node[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=10000000000000000;
		}
	}
	for(int i=1;i<=m;i++){
		for(pair<int,ll> j:Node[i]){
			for(pair<int,ll> h:Node[i]){
				int v=j.first,u=h.first;
				if(v!=u) f[v][u]=min(f[v][u],j.second+h.second);
			}
		}
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int h=1;h<=n;h++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f[i][j]=min(f[i][h]+f[h][j],f[i][j]);
				f[j][i]=f[i][j];
			}
		}
	}
//	int cnt=0;
	while(q--){
		cin>>x>>y;
		ll ans=10000000000000000;
		for(pair<int,ll> j:Node[x]){
			for(pair<int,ll> h:Node[y]){
				int v=j.first,u=h.first; 
				ll num=w[x]+w[y]+f[u][v]+j.second+h.second;
				ans=min(num,ans);
			}
		}
		cout<<ans<<'\n';
//		sos[++cnt]=ans;
	}
//	freopen("subway7.ans","r",stdin);
//	for(int i=1;i<=cnt;i++){
//		ll wlans;
//		cin>>wlans;
//		if(sos[i]!=wlans) cout<<"wa";
//	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
