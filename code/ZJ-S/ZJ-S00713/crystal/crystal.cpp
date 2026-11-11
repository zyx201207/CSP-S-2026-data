#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, ans = 0;
ll m, a[500005], qz[500005];
bool check(int l, int r){
	ll len = r-l+1;
	return len*a[r]-(qz[r]-qz[l-1]) <= m;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i <= n; ++i)  cin >> a[i];
	sort(a+1, a+n+1);
	for (int i=1; i <= n; ++i)  qz[i] = qz[i-1]+a[i];
	for (int i=1; i <= n; ++i){
		int l=1, r=i, mid, hd=i;
		while (l <= r){
			mid = l+(r-l)/2;
			if (check(mid, i))  hd = min(hd, mid), r = mid-1;
			else  l = mid+1;
		}
		ans = max(ans, i-hd+1);
	}
	cout << ans;
	return 0;
}
