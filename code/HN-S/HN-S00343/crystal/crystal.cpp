// hello CSP-S2026
// %%% @CCF  %%% dlc666
// @wu_yichen 
// Trick||Treat! 
// Oct31==Dec25? 
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

// 使用 m 次操作，最多可以将多少颗水晶化为能量为 a[x] 的水晶 
int check(long long, int, int);

vector<long long> a;	// 初始能量 
vector<long long> d;	// 升级所需能量 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n; cin >> n;
	long long m; cin >> m;
	a.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());	// 先排个序 
	
	d.resize(n);
	for(int i = 0; i < n; i++) {
		if(i == n - 1) d[i] = 0;
		else d[i] = a[i + 1] - a[i];
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = max(ans, check(m, n, i));
	}
	
	cout << ans << endl;
	return 0;
}

int check(long long m, int n, int x) {
	int ps = x;
	long long diff = 0;
	int sum = 0;
	while(ps < n - 1 && a[ps + 1] == a[ps]) ps++;
	for(int i = ps; ; i--) {
		if(m <= 0) break;
//		cout << "当前能量" << a[i] << endl; 
		sum++;
		m -= diff;
		if(i != 0) diff += d[i - 1];
		else break;
	}
	return sum;
}

