#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;

int n, ans = -1;
long long m;
long long nl[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> nl[i];
	}
	sort(nl, nl+n);
	for(int i = n-1; i >= 0; i--) {
		int e = m, cnt = 1, bz = nl[i];
		while(e > 0 && i-cnt >= 0) {
			e -= (bz-nl[i-cnt]);
			if(e < 0) break;
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	
	return 0;
}
