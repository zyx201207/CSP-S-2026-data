#include<bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, m;

vector<long long> dfs(vector<long long> v, int mx) {
	vector<long long> trie(100, 0);
	vector<long long> p[mx+1];
	for ( int i = 0; i < v.size(); i++ ) {
		for ( int j = mx; j >= 0; j-- ) {
			if ( (1LL<<j) & v[i]) {
				trie[j]++;
				p[j].push_back(v[i]);
			}
		}
	}
	for ( int j = mx; j >= 0; j-- ) {
		if ( trie[j] >= m && j != 0 ) {
			return dfs(p[j], j-1);
		}
	}
	return v;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	vector<long long> v;
	for ( int i = 1; i <= n; i++ ) {
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	vector<long long> t = dfs(v, 30);
	sort(t.begin(), t.end(), greater<long long>());
	long long ans = t.front();
	for ( int i = 0; i < m; i++ ) {
		ans &= t[i];
	}
	cout << ans;
}
