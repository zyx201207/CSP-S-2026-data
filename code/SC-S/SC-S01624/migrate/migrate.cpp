#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int t,id;
int n;
const int N = 2e6 + 5;
int a[N],d;
vector<int>edge[N];
int vis[N],dist[N];
pair<int,int> q[N];
int hd,tl;
void bfs(int s){
	hd = 1,tl = 0;
	q[++tl] = make_pair(0,s),dist[s] = 0;
	while(hd <= tl){
		int w = q[hd].first,u = q[hd++].second;
//		cout << w << " " << u <<endl;
		if(w > dist[u]) continue;
		if(w == dist[u]) vis[u]++;
		if(w < dist[u]){
			vis[u] = 1;
			dist[u] = w;
		}
		for(auto i : edge[u]){
			if(w + 1 <= dist[i]){
				if(w + 1 == dist[i] && vis[i] > 3) continue;
//				cout <<"get" << endl;
//				cout << i << " " <<w + 1 <<endl;
				q[++tl] = make_pair(w + 1,i);
			}
		}
	}
} 
void solve(){
	cin >> n >> d;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		edge[i].clear();
	}
	if(id > 6){
		cout << 0 << endl;
		return;
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;a[j] - a[i] <= d && j <= n;j++){
			edge[i].push_back(j);
			edge[j].push_back(i);
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		fill(vis + 1,vis + n + 1,0);
		fill(dist + 1,dist + n + 1,1e18);
		bfs(i);
		for(int j = 1;j <= n;j++){
			if(vis[j] == 2) ans++;
		}
	}
	cout << ans / 2 << endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> id >> t;
	while(t--){
		solve();
	}
	return 0;
}
//最后的最后我想说说1.100+68+32+0=200希望不要挂,T2希望可以放点过去,2.我旁边的小帅哥考试的时候一直在叫不是这有事就是那有事吵的我头疼。CW的最后一次csp,希望初中能7勾吧，但是@flying_without_wings，我这个分肯定去不了WC了，后会有期。 