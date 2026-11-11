#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, a[500005], ans[500005];
int b[300005];
vector<int> v;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	scanf("%d", &a[i]);
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			v.clear();
			for (int j = 1; j <= m; j++)
				b[j] = 0;
			for (int j = i; j <= n; j++)
				if (b[a[j]]) {
					while (v.size() && v.back() != a[j])
						b[v.back()]--, v.pop_back();
				} else
					b[a[j]]++, v.push_back(a[j]);
			for (auto i : v)
				ans[i]++;
		}
		for (int i = 1; i <= m; i++)
			printf("%d ", ans[i]);
		return 0;
	}
}       
