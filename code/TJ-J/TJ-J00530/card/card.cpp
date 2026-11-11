//BLÄ£Äâ  12/25
#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500010];
vector <int> q;
int t[300010],ans[300010];

int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++) {
		q.clear ();
		memset (t,0,sizeof (t));
		for (int j = i;j <= n;j++) {
			if (t[a[j]] != 0) {
				int yy = 0;
				for (int k = t[a[j]] - 1;k < q.size();k++) {
					t[q[k]] = 0;
					yy++;
				}
				for (int k = 1;k <= yy;k++) {
					q.pop_back ();
				}
				q.push_back (a[j]);
				t[a[j]] = q.size ();
			} else {
				q.push_back (a[j]);
				t[a[j]] = q.size ();
			}
		}
		for (int j = 1;j <= m;j++) {
			if (t[j] != 0) {
				ans[j]++;
			}
		}
	}
	for (int i = 1;i <= m;i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}
