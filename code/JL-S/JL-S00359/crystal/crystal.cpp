#include<bits/stdc++.h>
#define int long long
#define QwQ 0
#define debug cout << "!!!" << '\n';
using namespace std;
int n, m;
int a[500010];
int ans, cnt;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int r = 0;
	for(int l = 1; l <= n; l++){
		cnt -= a[r] - a[l - 1];
		if(r < l)	r = l;
		while(r < n && cnt + (r - l + 1) * (a[r + 1] - a[r]) <= m){
			cnt += (r - l + 1) * (a[r + 1] - a[r]);
			r++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
	return QwQ;
}