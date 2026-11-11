//Author: yangwang2013
#include <bits/stdc++.h>
#define dbg(x) cerr << #x << " = " << x << endl
#define sz(x) (int)x.size()
#define all(x) (x.begin(),x.end())
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 505;
const int MAXM = 500005;
int c,n,m,d,q,a[MAXN][MAXM],t[MAXN][MAXM],w[MAXM],vst[MAXM],dist[MAXM];
vector<pii> g[MAXM];

void solve(){
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++){
		int k;
		cin >> k;
		if (k == 1)
			cin >> a[i][1] >> t[i][1];
		else{
			cin >> a[i][1] >> t[i][2] >> a[i][2] >> t[i][2];
			g[a[i][1]].push_back({a[i][2],i});
			g[a[i][2]].push_back({a[i][1],i});
		}
	}
	while (q--){
		memset(vst,0,sizeof vst);
		memset(dist,0x3f,sizeof dist);
		int s,e;
		cin >> s >> e;
		queue<int> q;
		q.push(s);
		vst[s] = 1;
		dist[s] = 0;
		while (!q.empty()){
			int u = q.front();
			q.pop();
			for (auto v : g[u]){
				if (vst[v.fi]) continue;
				dist[v.fi] = min(dist[u] + t[v.se][3-v.fi],dist[v.fi]);
				q.push(v.fi);
			}
		}
		cout << w[s] + dist[e] + w[e] << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int tc = 1;
	//cin >> t;
	while (tc--){
		solve();
	}
	return 0;
}
