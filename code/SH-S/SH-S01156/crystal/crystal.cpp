#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+14;
int n, m, ans;
int a[N], s[N];
bool cmp(int x, int y){ return x < y; }
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a+1, a+n+1, cmp);
	int cur = 0;
	for(int i = 1; i <= n; i ++){
		s[i] = s[i-1]+a[i];
	}
	for(int i = 1; i <= n; i ++){
		if((n-i+1)*a[n]-s[n]+s[i-1] <= m){
			ans = max(ans, n-i+1);
			continue;
		}
		int l = i, r = n;
		while(l < r-1){
			int mid = (l+r)>>1;
			if(s[mid]-s[i-1]+m >= a[mid]*(mid-i+1)) l = mid;
			else r = mid;
		}
		ans = max(ans, l-i+1);
	}
	cout << ans << '\n';
	return 0;
}
