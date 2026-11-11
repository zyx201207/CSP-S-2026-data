#include<bits/stdc++.h>
using namespace std;

#define N 500007
#define inf 0x7f7f7f7f
#define inF 0x7f7f7f7f7f7f7f7f
#define ll long long
#define ull unsinge ll

int n;
ll m;
ll a[N];
ll d[N];

int A(ll x) {
//	cout << x << "\n";
	ll _m = m;
	ll sum = 0;
	int t = lower_bound(a + 1, a + n + 1, x) - a;
	int T = lower_bound(a + 1, a + n + 1, x + 1) - a;
	int cnt = T - t;
	t--;
	int l = 1, r = t;
	if(r < l) return cnt;
	while(l < r) {
		int mid = l + r >> 1;
		if(d[mid] - d[t + 1] - (t - mid + 1) * (a[n] - a[t + 1]) <= m) r = mid;
		else l = mid + 1;
	}
//	cout << t << " " << x << " " << r << " " << t - r + 1 + cnt << "\n";
	return t - r + 1 + cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
//	int ATR = clock();
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = n; i >= 1; i--) {
		d[i] = d[i + 1] + (a[n] - a[i]);
	} 
//	for(int i = 1; i <= n; i++) {
//		cout << d[i] << " ";
//	}
//	cout << "\n";
	int maxn = 0;
	for(int i = 1; i <= n; i++) {
		maxn = max(maxn, A(a[i])); 
//		cout << i << "\n";
	}
	cout << maxn << "\n";
	return 0; 
} 
