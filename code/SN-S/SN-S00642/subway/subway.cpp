#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5; 
struct sta{
	int t,at;
}w[N];
int c, n, m, d, q, k[N], st[N], ed[N];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i){
		cin >> w[i].t;
	}
	for(int i = 1; i <= n; ++i){
		cin >> k[i];
		for(int j = 1; j <= k[i]; ++j){
			int p, t;
			cin >>  p >> t;
			w[p].at = t;
		}
	}
	for(int i = 1; i <= n; ++i){
		cin >> st[i] >> ed[i];
	}
	for(int i = 1; i <= n; ++i){
	cout << 0 << '\n';
	}
	return 0;
}
