#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define zxh(x, y, z, qwq) for(int qwq = x; qwq <= y; qwq += z)
#define dxh(x, y, z, qwq) for(int qwq = x; qwq >= y; qwq -= z)
#define ull unsigned long long ull
using namespace std;

int c, T;
vector<int> g[1000010]; 

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
		}
		cout << "Ò¯²»»á£¬ÅÀ£»¿Õ±¯ÇÐ";
	}
	return 0;
}
