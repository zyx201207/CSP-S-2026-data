#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
int n, mx = 1;
ll m;
ll a[N], pre[N];
ll read(){
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f; 
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		int l = 1, r = i, mid, ans = i;
		while(l <= r){
			mid = (l + r) >> 1;
			if(((i - mid + 1) * a[i]) - (pre[i] - pre[mid - 1]) <= m) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		mx = max(mx, i - ans + 1);
	}
	cout << mx;
	return 0;
}
