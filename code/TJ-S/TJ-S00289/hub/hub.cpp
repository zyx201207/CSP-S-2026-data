#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
int c,T,n,k;
bool vis[N];
vector<int> a[N];
int get(){
	int re = 0;
	for(int i = 1;i<=n;i++){
		if(vis[i]) continue;
		set<int> s;
		queue<pair<int,int>> q;
		q.push(make_pair(i,0));
		int res = 0;
		while(q.size()){
			int u = q.front().first,d = q.front().second;
			q.pop();
			if(s.find(u)!=s.end()||res) continue;
			s.insert(u);
			for(auto j:a[u]){
				if(vis[j]) res = d+1;
				else q.push(make_pair(j,d+1));
			}
		}
		re = max(re,res);
	}
	return re;
}
void solve(){
	cin>>n>>k;
	int ans = INT_MAX;
	for(int i = 1,u,v;i<n;i++){
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i = 1;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k) continue;
		int cnt = 0;
		for(int j = 0;j<n;j++){
			if(!(i&(1<<j))) continue;
			bool f = 1;
			vis[j+1] = 1;
			for(auto i:a[j+1]){
				if(vis[i]) f = 0;
			}
			if(f) cnt++;
		}
		int res = get();
		if(cnt<=2) ans = min(ans,res);
		for(int j = 1;j<=n;j++) vis[j] = 0;
	}
	cout<<ans<<'\n';
	for(int i = 1;i<=n;i++) a[i].clear();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
