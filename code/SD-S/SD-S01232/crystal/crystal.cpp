#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <iomanip>
#define ll long long
using namespace std;
const int MAXN = 1e6 + 5;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int n;
ll A[MAXN], m;

int main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> A[i];
	}
	sort(A + 1, A + n + 1);
	int ans = 1, l = 1;
	ll k = 0;
	for(int r = 2; r <= n; r ++) {
		k += (A[r] - A[r - 1]) * (ll)(r - l);
		while(k > m) {
			k -= (A[r] - A[l]);
			l ++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	
	return 0;
	
}

