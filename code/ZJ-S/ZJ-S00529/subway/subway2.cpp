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
long long ans[505][505];
int se[505][505][2];
bool vis[500005];
struct node{
	int mt;
	long long cnt;
	bool operator<(const node& other) const{
		return cnt > other.cnt;
	}
};

void dij(int dmt){
	for(int i = 1; i <= n; i++) ans[dmt][i] = LLONG_MAX;
	for(int i = 1; i <= m; i++) vis[i] = 0;
	priority_queue<node> pq;
	pq.push({dmt, 0});
	ans[dmt][dmt] = 0;
	
	while(pq.size()){
		node hd = pq.top();
		int id = hd.mt;
		pq.pop();
		
		if(hd.cnt > ans[dmt][id]) continue;
		for(int i = 0; i < mt[id].k; i++){
			if(vis[mt[id].a[i]]) continue;
			vis[mt[id].a[i]] = 1;
			for(ST it : st[mt[id].a[i]]){
				if(it.mt <= id) continue;
				long long ncnt = hd.cnt + mt[id].t[i] + it.t;
				if(ncnt >= ans[dmt][it.mt]) continue;
				pq.push({it.mt, ncnt});
				ans[dmt][it.mt] = ncnt;
				if(id == dmt) se[dmt][it.mt][0] = mt[id].a[i];
				else se[dmt][it.mt][0] = se[dmt][id][0];
				se[dmt][it.mt][1] = mt[id].a[i];
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway6.in", "r", stdin);
	//freopen("subway.out", "w", stdout);
	
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
	
	for(int i = 1; i <= n; i++) dij(i);
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++) ans[j][i] = ans[i][j];
	}
	
	while(q--){
		int x, y;
		cin >> x >> y;
		long long res = INT_MAX;
		for(ST it1 : st[x]){
//			bool flag = 1;
			for(ST it2 : st[y]){
//				if(it1.mt == it2.mt){
//					flag = 0;
//					break;
//				}
				long long cnt = ans[it1.mt][it2.mt];
				if(se[it1.mt][it2.mt][0] != x) cnt += it1.t;
				if(se[it1.mt][it2.mt][1] != y)
				res = min(res,  + it1.t + it2.t);
			}
//			if(flag) break;
		}
		res += w[x] + w[y];
		cout << res << "\n";
	}
	
	return 0;
}
