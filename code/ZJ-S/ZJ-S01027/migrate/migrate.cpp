#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int n, d, _, a[N], nxt[N], lst[N], lstt[N], dp[N], ans[N];
void solve(){
	cin >> n >> d;
	for(int i = 0; i <= n + 3; i++)	a[i] = nxt[i] = lst[i] = lstt[i] = dp[i] = ans[i] = 0;
	for(int i = 1; i <= n; i++)	cin >> a[i];
	for(int i = 1, p = 1, q = 1, pp = 1; i <= n; i++){
		while(p < n && a[p + 1] - a[i] <= d)	p++;
		nxt[i] = p;
		if(i > 1)	while(q <= n && a[q] <= a[i - 1] + d)	q++;
		lst[i] = q;
		if(i > 2)	while(pp <= n && a[pp] <= a[i - 2] + d)	pp++;
		lstt[i] = pp;
	}
	for(int i = 1; i <= n; i++){
		if(lst[i] <= i)	lst[i] = i + 1;
		if(lstt[i] <= i)	lstt[i] = i + 1;
	}
	for(int i = n; i; i--){
		int j = nxt[i];
		if(j == i)	dp[i] = 0;
		else if(j < lst[i])	dp[i] = 0;
		else	dp[i] = dp[j] + j - lst[i] + 1;
	}
	// for(int i = 1; i <= n; i++)	cout << nxt[i] << ' ';
	// cout << '\n';
	// for(int i = 1; i <= n; i++)	cout << lst[i] << ' ';
	// cout << '\n';
	// for(int i = 1; i <= n; i++)	cout << lstt[i] << ' ';
	// cout << '\n';
	// for(int i = 1; i <= n; i++)	cout << dp[i] << ' ';
	// cout << '\n';
	for(int i = n; i; i--){
		int j = nxt[i];
		// cout << i << ' ' << j << ' ' << nxt[j] << '\n';
		if(nxt[j] == j)	continue;
		int l = 1, r = n, mid, p = nxt[j];
		while(l <= r){
			mid = (l + r) >> 1;
			if(a[mid] + d >= a[nxt[nxt[j]]])	r = mid - 1, p = mid;
			else	l = mid + 1;
		}
		if(nxt[j] >= lst[j])	ans[i] = lst[j] - lstt[j] + ans[j] * (!(_ == 11 || _ == 12) && a[j - 1] + d < a[p]);
		else if(nxt[j] < lst[j] && nxt[j] >= lstt[j])	ans[i] = dp[nxt[j]] + lst[j] - lstt[j];
	}
	// for(int i = 1; i <= n; i++)	cout << ans[i] << ' ';
	// cout << '\n';
	int ansans = 0;
	for(int i = 1; i <= n; i++)	ansans += ans[i];
	cout << ansans << '\n';
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> _ >> T;
	while(T--)	solve();
	return 0;
}
//10 22
//0 7 14 21 28 35 42 49 56 63