#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll,int> 
using namespace std;
/*====================*/
const int N = 5e5+10;
const int MOD =998244353;
const ll INF = 0x3F3F3F3F3F3F3F3F;
/*====================*/
int n,m,d,q;
vector<pair<int,ll> >li[N];
//线路：站，时间 
vector<pair<int,ll> >st[N];
//可达的，时间 
ll D(int s,int e){
	priority_queue<pi,vector<pi>,greater<pi> >qq;
	qq.push({0,s});
	vector<ll>dis(m+1,INF);dis[s]=0;
	while(!qq.empty()){
		ll t=qq.top().first,mt=INF;
		int idx=-1,u=qq.top().second;
		qq.pop();
		if(t>dis[u])continue;
		if(u==e)break; 
		for(auto it:st[u]){
			int v=it.first;ll tt=it.second;
			//cout<<"UUU"<<v<<'\n';
			if(dis[v]>dis[u]+tt){
				dis[v]=dis[u]+tt;
				qq.push({dis[v],v}); 
				//cout<<u<<' '<<v<<' '<<dis[v]<<'\n';
			}
		}
		//cout<<u<<'\n'; 
	}return dis[e];
}
/*====================*/
void Solve(void){
	int c;cin>>c>>n>>m>>d>>q;
	vector<ll>w(m+1);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x;ll t;cin>>x>>t;
			li[i].push_back({x,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int l=0;l<li[i].size();l++){
			for(int r=l+1;r<li[i].size();r++){
				int u=li[i][l].first,v=li[i][r].first;
				//cout<<u<<' '<<v<<'\n';
				ll t=li[i][l].second+li[i][r].second;
				st[u].push_back({v,t});
				st[v].push_back({u,t}); 
			}
		}
	}
	while(q--){
		int s,e;cin>>s>>e;
		cout<<w[s]+w[e]+D(s,e)<<'\n'; 
	}
}
/*====================*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}
//万一塔子姐不是区呢 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
