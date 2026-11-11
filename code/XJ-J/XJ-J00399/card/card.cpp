#include <bits/stdc++.h>
using namespace std;

const int M = 3e5 + 5;
int n, m, cnt[M], ans[M];
deque<int> a;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1, x;i <= n;i++)
		cin >> x, a.push_back(x);	

	for (int i = 1;i <= n;i++) {
		vector<int> v;
		for (int j = 0;j < a.size();j++) {
			bool f = false;
			for (int k = 0;k < v.size();k++)
				if (a[j] == v[k]) {
					for (int l = k;l >= j;l--)
						cnt[a[l]]--;
					v.erase(v.begin() + k);
					f = true;
					break;
				}
			if (!f)
				v.push_back(a[j]);
			cnt[a[j]]++;
		}
		a.pop_front();
		for (int j = 1;j <= m;j++)
			ans[j] += int(cnt[j] > 0);
		memset(cnt, 0, sizeof(cnt));
	}
	
	for (int i = 1;i <= m;i++)
		cout << ans[i] << ' ';

	return 0;
}
