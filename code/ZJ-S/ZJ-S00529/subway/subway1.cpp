#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[500005];
struct subway{
	int k;
	vector<int> a, t;
}mt[505];
struct ST{
	int mt, t;
};
vector<ST> st[500005];
long long dist[500005][25];
struct node{
	int x, mt;
	long long cnt;
	bool operator<(const node& other) const{
		return cnt > other.cnt;
	}
};

long long dij(int s, int e){
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= d; j++) dist[i][j] = LLONG_MAX;
	}
	priority_queue<node> pq;
	for(ST it : st[s]){
		for(int i = 0; i < mt[it.mt].k; i++){
			pq.push({mt[it.mt].a[i], it.mt, it.t + mt[it.mt].t[i]});
			dist[mt[it.mt].a[i]][it.mt] = it.t + mt[it.mt].t[i];
		}
	}
	
	while(pq.size()){
		node hd = pq.top();
		pq.pop();
		
		if(hd.cnt > dist[hd.x][hd.mt]) continue;
		
		for(ST it : st[hd.x]){
			long long ncnt = hd.cnt + it.t;
			if(ncnt >= dist[hd.x][it.mt]) continue;
			
			for(int i = 0; i < mt[it.mt].k; i++){
				pq.push({mt[it.mt].a[i], it.mt, ncnt + mt[it.mt].t[i]});
				dist[mt[it.mt].a[i]][it.mt] = ncnt + mt[it.mt].t[i];
			}
		}
	}
	
	long long ans = LLONG_MAX;
	for(ST it : st[e]){
		ans = min(ans, dist[e][it.mt]);
	}
	ans += w[s] + w[e];
	
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> mt[i].k;
		for(int j = 1; j <= mt[i].k; j++){
			int a, t;
			cin >> a >> t;
			mt[i].a.push_back(a);
			mt[i].t.push_back(t);
			st[a].push_back({i, t});
		}
	}
	
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << dij(x, y) << "\n";
	}
	
	return 0;
}
