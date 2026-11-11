#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 2e9;
const int M = 5e5 + 2;
int a[M], h[M];
int n, m;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int ans = -inf;
	for(int i = 1; i <= n; i ++){
		h[i] = h[i - 1] + a[i];
	}
	for(int j = n; j > 0; j --){
		int x = a[j] * j - h[j];
		for(int i = 1; i < j; i ++){
			int dt = a[i] + a[j];
			if(x <= m){
				ans = max(ans, j - i + 1);
				break;
			}
			x -= dt;
		}
	}
	cout << ans;
}