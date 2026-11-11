#include <bits/stdc++.h>
using namespace std;
int a[500005];
vector<int> s;
long long ans[300005];
bool flag[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {//每局
		for (int j = i; j <= n; j++) {//每轮打出的牌
			for (int k = 0; k < s.size(); k++) {//检查是否有点数为K的牌
				if (s[k] == a[j]) {
					for (int l = k; l < s.size(); l++) {
						s.pop_back();
					}
					break;
				}
			}
			s.push_back(a[j]);
		}
		for (int k = 0; k < s.size(); k++) {
			if (flag[s[k]] == 0) {
				ans[s[k]]++;
				flag[s[k]] = 1;
			}
		}
		for (int k = 0; k <= n; k++) {
			flag[k] = 0;
		}
		for (int l = 0; l < s.size(); l++) {
			s.pop_back();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[m] << ' ';
	}
	return 0;
}

