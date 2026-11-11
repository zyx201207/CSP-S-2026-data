#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pi pair<int,int>
#define mini pi,vector<pi>,greater<pi>
#define fs first
#define se second
#define P_Q priority_queue
using namespace std;
const int N = 2e5 + 5, M = 5e5 + 5, inf = 0x3f3f3f3f3f3f3f3f;

int st, ed;
int n, m, c, d, q;// nÏß mÕ¾ 
vector<pi> v[M * 3];
//v[i] = ¿Ú v[i + m] = Ìü v[i + m * 2] = Ïß(»»³Ë) 

int dis[M];
bool vis[M];
void bfs(){
	P_Q<mini> q;
	for(int i = 1;i <= m * 3;i++) dis[i] = inf, vis[i] = 0;
	q.push({0, st});
	dis[st] = 0, vis[st] = 1;
	while(q.size()){
		auto tp = q.top();q.pop();
		int x = tp.se;
		for(auto f : v[x]){
			int y = f.fs, w = f.se;
			if(vis[y]) continue;
			vis[y] = 1;
			dis[y] = min(dis[y], dis[x] + w);
			if(y == ed) return;
			q.push({dis[y], y});
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin); freopen("subway.out","w",stdout);

	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) {
		int x;
		cin >> x;
		v[i].push_back({i + m, x});
		v[i + m].push_back({i, x});
	}
	
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int x, y;
			cin >> x >> y;
			v[i + m + m].push_back({x + m, y});
			v[x + m].push_back({i + m + m, y});
		}
	}
	
	int pre = -1;
	while(q--){
		cin >> st >> ed;
		if(st != pre) bfs();
		pre = st;
		cout << dis[ed] << endl;
	}

	return 0;
}

