#include<bits/stdc++.h>
using namespace std;
void file_init(){
#ifdef LOCAL
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#else
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif
	return;
}
void fast_read(){
#ifndef cin
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#endif
	return;
}
int c,n,m,d,q;
const int M=5e5+10;
int w[M];
vector<pair<int,int>>g[M];
void input(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			g[a].push_back({t,i});
		}
	}
	return;
}
const int N=510;
#define ll long long
ll dis[N][N];
const ll inf=0x3f3f3f3f3f3f3f3f;
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				dis[i][j]=inf;
			}
		}
	}
}
void rebuild(){
	for(int i=1;i<=m;i++){
		for(pair<int,int>j:g[i]){
			for(pair<int,int>k:g[i]){
				dis[j.second][k.second]=min(dis[j.second][k.second],0ll+j.first+k.first);
			}
		}
	}
	return;
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	return;
}
void solve(){
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(pair<int,int>i:g[x]){
			for(pair<int,int>j:g[y]){
				ans=min(ans,dis[i.second][j.second]+i.first+j.first);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return;
}
int main(){
	file_init();
	fast_read();
	input();
	init();
	rebuild();
	floyd();
	solve();
	return 0;
}
