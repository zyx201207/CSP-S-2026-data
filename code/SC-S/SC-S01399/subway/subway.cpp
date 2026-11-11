#include <bits/stdc++.h>
using namespace std;
const long long inf = LLONG_MAX;
struct tpe{
	long long d; int n,o;
	operator<(const tpe & other) const{
		return d > other.d;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k; cin >> c >> n >> m >> d >> q;
	vector<long long> w(m+1,-1); 
	vector<pair<int,long long>> b[m+1];
	unordered_map<long long,long long> ump[m+1];
	vector<int> a[n+1]; 
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	} 
	long long ta,tt;
	for (int i = 1; i <= n; i++){
		cin >> k;
		for (int j = 1; j <= k; j++){
			cin >> ta >> tt;
			a[i].push_back(ta);
			b[ta].push_back({i,tt});
			ump[ta][i] = tt;
		}
	}
	int x,y;
	vector<long long> dist(m+1,inf); vector<bool> vist(m+1,false);
	priority_queue<tpe,vector<tpe>> pq;
	while (q--){
		cin >> x >> y;
		fill(dist.begin(),dist.end(),inf);
		fill(vist.begin(),vist.end(),false);
		dist[x] = 0;
		pq.push({0,x,0});
		while (!pq.empty()){
			int d = pq.top().d, n = pq.top().n, o = pq.top().o; pq.pop(); 
			if (vist[n]) continue;
			vist[n] = true;
			for (pair<int,int> ti: b[n]){ 
				int z = ti.first, t = ti.second;
				for (int v : a[z]){
					if (vist[v]) continue;
					if (z == o) { 
						if (dist[v] > (d - t + ump[v][z])){
							dist[v] = d - t + ump[v][z];
							pq.push({(d - t + ump[v][z]), v, z});
						}
					} else { 
						if (dist[v] > (d + t + ump[v][z])){
							dist[v] = d + t + ump[v][z];
							pq.push({(d + t + ump[v][z]), v, z});
						}
					}
				} 
			}
		}
		cout << (dist[y]+w[x]+w[y]) << "\n";
	}
	return 0;
}