#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 5e5+10;
ll a[N], m, lift[N];
int p[N] = {0}, ans[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	sort(a+1, a+n+1);
	
	int t = m;
	
	ans[n] = 1;
	for (int i = n-1; i >= 1; --i) {
		if (t < a[n] - a[i]) {
			p[n] = i;
			lift[n] = t;
			break;
		}
		++ans[n];
		t -= (a[n] - a[i]);
	}
	
	for (int i = n-1; i >= 1; --i) {
		t = lift[i+1] + (ans[i+1]-1) * (a[i+1]-a[i]);
		ans[i] = ans[i+1]-1;
		for (int k = p[i+1]; k >= 1; --k) {
			if (t < a[i] - a[k]) {
				p[i] = k;
				lift[i] = t;
				break;	
			}
			++ans[i];
			t -= (a[i] - a[k]);
		}
	}
	
	int answer = -1;
	for (int i = 1; i <= n; ++i) {
		answer = max(answer, ans[i]);
	}
	cout << answer << endl;
	
	return 0;
}