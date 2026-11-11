#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 500100;

ll n, m;
ll a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	int ma = INT_MIN;
	ll m_;
	for (int i = n; i >= 2; i--) {
		int cnt = 1;
		m_ = m;
		int j = i - 1;
		while (m_) {
			if (m_ >= a[i] - a[j]) {
				m_ -= a[i] - a[j];
				cnt++;
				j--;
				if (j == 0) break;
			}
			else break;
		}
		
		ma = max(ma, cnt);
	}
	
	cout << ma;
	
	return 0;
}
