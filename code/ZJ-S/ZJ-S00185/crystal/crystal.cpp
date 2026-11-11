#include<bits/stdc++.h>
using namespace std;
long long n, m, tmm, a[500010], c, ans = 0, cnt = 1, id = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a + n + 1);
	for(long long c = 1; c <= n; c++) {
		cnt = 1;
		tmm = m;
		if(a[c] == a[c - 1] && c > 1) continue;
	    for(long long i = c - 1; i >= 1; i--) {
		    if(tmm >= (a[c] - a[i])){
			    tmm -= (a[c] - a[i]);
			    cnt++;
		    }else break;
     	}
     	for(long long i = c + 1; i <= n; i++) {
     		if(a[i] == a[c])cnt++;
     		else break;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}