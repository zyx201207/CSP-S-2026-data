#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n, m;
int a[N], S[N];
bool check(int lim) {
	int ans=8000000000000000000;
	for(int l=1; l+lim-1<=n; ++l) {
		ans = min(ans, a[l+lim-1]*lim-(S[l+lim-1]-S[l-1]));
	}
	return ans<=m;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	} sort(a+1, a+1+n);
	for(int i=1; i<=n; ++i) S[i]=S[i-1]+a[i];
	int low=1, high=n+1; //lowÊÇ´ð°¸ 
	while(high - low > 1) {
		int mid = (low + high) / 2;
		if(check(mid)) low=mid;
		else high=mid;
	}
	cout << low;
}
