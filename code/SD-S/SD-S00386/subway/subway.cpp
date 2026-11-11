#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>

const int N = 5e5 + 502,inf = 1e18;
struct node{
	vector<pii> v;
	int d = inf;
	int b;
}a[N];
int n,m,d,q;
int w[N];
priority_queue<pii,vector<pii>,greater<pii> > pq;
queue<pii> bq;

void bfs(){
	int t;
	cin >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n + m;i++){
		a[i].b = 0;
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int u;
			cin >> u >> t;
			a[u].v.emplace_back(1,i + m);
			a[i + m].v.emplace_back(1,u);
		}
	}
	while(q--){
		int x,y,ans;
		cin >> x >> y;
		while(!bq.empty()) bq.pop();
		bq.push({x,0});
		while(!bq.empty()){
			auto k = bq.front();
			bq.pop();
			if(k.first == y){
				ans = k.second * t;
				break;
			}
			for(auto i : a[k.first].v){
				if(!a[i.second].b){
					a[i.second].b = 1;
					bq.push({i.second,k.second + 1});
				}
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;  cin >> c;
	if(c >= 12&&c <= 19){
		bfs();
		return 0;	
	}
	cin >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int u,t;
			cin >> u >> t;
			a[u].v.emplace_back(t,i + m);
			a[i + m].v.emplace_back(t,u);
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		while(!pq.empty()) pq.pop();
		for(int i = 1;i <= n + m;i++){
			a[i].d = inf;
		}
		pq.push({0,x});
		a[x].d = 0;
		while(!pq.empty()){
			auto nd = pq.top().first;
			auto np = pq.top().second;
			pq.pop();
			if(nd != a[np].d) continue;
			for(auto i : a[np].v){
				if(nd + i.first < a[i.second].d){
					a[i.second].d = nd + i.first;
					pq.push({a[i.second].d,i.second});
				}
			}
		}
		cout << a[y].d + w[x] + w[y] << '\n';
	}
	return 0;
}
