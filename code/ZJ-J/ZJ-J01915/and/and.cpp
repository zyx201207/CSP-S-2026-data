#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
int n, m;
ll a[N];
int cnt[35];
bool vis[N];
vector <ll> q[35]; 
ll ad () {
	ll sum = 0;
	bool a1 = true;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			if (a1) { sum = a[i]; a1 = false; }
			sum = (sum & a[i]);
		}
	}
	return sum;
}
int main() { 
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 0; j <= 30; j++) {
			if ((a[i] & (1 << j)) != 0) {
				cnt[j]++;
				q[j].push_back(i);
			}
		}
	}
	bool v1 = true;
	for (int i = 30; i >= 0; i++) {
		if (cnt[i] >= m) {
			int len = q[i].size();
			for (int j = 0; i < len; i++) {
				int u = q[i][j];
				if (vis[u] || v1) vis[u] = true;
			} 
			if (cnt[i] == m) { cout << ad(); return 0; }
			v1 = false;
		}
	}
	
	return 0;
}
