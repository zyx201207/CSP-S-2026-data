#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, m, arr[1000000], pos;
int cnt[1000000];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		string s;
		pos = i;
		for (int j = i; j <= n; j++) {
			s += arr[j] + '0';
			for (int k = pos; k < j; k++) {
				if (arr[k] == arr[j]) {
					s = arr[j] + '0';
					pos = j;
					break;
				}
			}
		}
		cout << s << endl;
		for (int x = 0; x < s.size(); x++) {
			int k = s[x] - '0';
			cnt[k]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " " ;
	}
	return 0;
}