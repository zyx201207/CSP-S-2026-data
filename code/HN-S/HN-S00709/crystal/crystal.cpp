#include <iostream>
#include <algorithm>
#undef _
using namespace std;
typedef long long ll;

// crystal.cpp

// I'm not going to AFO!!!!!!
// NEVER!!!!!!!!!

// Copyright (C) Utf8734. All Rights Reversed. 

const int N = 5e5 + 3;

int n;
ll m;
ll A[N], S[N];

int main() {
	ios::sync_with_stdio(false);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) 
		cin >> A[i];
	
	sort(A + 1, A + n + 1);
	
	for (int i = 1; i <= n; ++i) 
		S[i] = S[i - 1] + A[i];
	
	int ans = 1;
	for (int i = 2; i <= n; ++i) {
		int l = 0, r = i;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			ll t = A[i] * mid - S[i] + S[i - 1 - mid];
			if (t == m) {
				l = r = mid;
				break;
			} else if (t < m) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		ans = max(ans, l);
	}
	
	cout << ans << endl;
	
	return 0;
} 
