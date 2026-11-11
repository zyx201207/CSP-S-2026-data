#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500010; 
int n, m;
int a[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int need = 0, ans = 1;
	for(int l = 1, r = 1; r <= n; ){
		r ++;
		need += (a[r] - a[r - 1]) * (r - l);
//		cout << need << ' ';
		while(need > m){
			need -= (a[r] - a[l]);
			l ++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}
//14min£¬100pts
