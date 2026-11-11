#include <bits/stdc++.h>
using namespace std;

const int M = 500010; 
const int N = 510;
int c, n, m, d, q;
int w[M], k[N];
vector<int> a[N], t[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;++ i)
		cin >> w[i];
		
	for(int i = 1;i <= n;++ i) {
		cin >> k[i];
		int x;
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j = 1;j <= k[i];++ j) {
			cin >> x;
			a[i].push_back(x);
			cin >> x;
			t[i].push_back(x);	
		}	
	}	
	
	for(int i = 1;i <= q;++ i) {
		int x, y;
		cin >> x >> y;
		cout << rand() + w[x] + w[y] << "\n";
	}
	
	return 0;
}
