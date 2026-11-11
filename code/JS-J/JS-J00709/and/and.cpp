#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m;
long long a[N];
char s[N][45];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int x = a[i];
        for (int j = 35; j; j--) {
            s[i][j] = (int) x % 2 + '0';
            x /= 2;
        }
	}

	int k = n - m;
	map <long long, long long> mp;
	for (int i = 1; i <= n; i++)
		mp[a[i]]++;
	for (int i = 1; i <= 35; i++) {
		vector <int> c;
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (!mp[a[j]]) continue;
			if (s[j][i] == '1')
				cnt++;
			else
				c.push_back(j);
		}
		if (c.size() <= k) {
			for (int j = 0; j < (int) c.size(); j++) {
				mp[a[c[j]]]--;
                k--;
            }
		}
	}

	int ans;
	for (int i = 1; i <= n; i++)
		if (mp[a[i]])
			ans = a[i];
    for (int i = 1; i <= n; i++)
		if (mp[a[i]])
			ans &= a[i];
    cout << ans << "\n";
}
