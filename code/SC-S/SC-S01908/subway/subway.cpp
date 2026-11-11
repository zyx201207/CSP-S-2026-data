#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
int n,m,d,q,be,en;
ll ans,w[N],dis[505][505];
vector<int> a[505];//tra[i]记录车站i有多少条线路
vector<ll> t[505];
vector<pair<int,ll> > tra[N];
void in(){
	int c,k,x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++) cin>>w[i];
	for(int i = 1;i<=n;i++){
		cin>>k;
		a[i].push_back(k);
		t[i].push_back(k);
		for(int j = 1;j<=k;j++){
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	return;
}
void solve(){//删除原图的车站节点
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=a[i][0];j++){
			tra[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i = 1;i<=n;i++) for(int j = 1;j<=n;j++) dis[i][j] = 1e18;
	for(int i = 1;i<=n;i++) dis[i][i] = 0;
	for(int i = 1;i<=m;i++){
		for(int j = 0;j<tra[i].size();j++){
			for(int k = 0;k<tra[i].size();k++){
				int u = tra[i][j].first,v = tra[i][k].first;
				ll uw = tra[i][j].second,vw = tra[i][k].second;
				dis[u][v] = min(dis[u][v],uw+vw);
			}
		}
	}
	return;
}
void solve2(){
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++) dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	in();
	solve();
	solve2();
	while(q--){
		cin>>be>>en;
		ans = 1e18;
		for(auto i:tra[be]){
			for(auto j:tra[en]){
				ans = min(ans,w[be]+i.second+dis[i.first][j.first]+j.second+w[en]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
hack:
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
*/