#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], ans = 1, s[500005];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++){
		s[i] = (a[i] - a[i - 1]) * (i - 1) + s[i - 1];
		if(s[i] <= m){
			ans = i;
		}else{
			break;
		}
	}
	cout << ans;
	return 0;
}