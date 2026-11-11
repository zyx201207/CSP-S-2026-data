#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], ans;

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
	sort(a + 1, a + n + 1);
	a[0] = a[1];
	int l = 1, sum = 0;
	for(int i = 1; i <= n; i++){
		sum += ((a[i] - a[i - 1]) * (i - l));
		while(l <= i && sum > m) sum -= (a[i] - a[l]), l++;
		ans = max(ans, i - l + 1);
	}
	cout << ans << '\n';
	return 0;
}

//14:51
//zym 预言家刀了
//@DanseSolo 姐姐可爱喵 