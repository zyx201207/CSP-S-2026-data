#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pcr = pair<ll , char>;
int n;
int main() {
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<pcr> in;
	int idx = -1;
	for(int i = 1;i <= n;i++) {
		int a;
		char c;
		cin >> a >> c;
		if(idx == -1 || in[idx].first != c) {
			in.push_back({a , c});
			idx++;
		}
		else {
			in[idx].first += a;
		}
	}
	ll ans = 0;
	int l = 0 , r = idx;
	while(l < r) {
		int re = min(in[l].first , in[r].first);
		in[l].first -= re;
		in[r].first -= re;
		if(in[l].second != in[r].second) {
			ans += re;
		}
		if(in[l].first == 0) l++;
		if(in[r].first == 0) r--;
	}
	cout << ans << '\n';
	return 0;
}
