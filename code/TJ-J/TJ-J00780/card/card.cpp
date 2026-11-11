#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],cnt[300005];
bool cnt2[300005];
int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;++i) {
		cin>>a[i];
	}
	for (int i = 1;i <= n;++i) {
		stack <int> q;
		for (int j = 1;j <= m;++j) {
			cnt2[j] = 0;
		}
		for (int j = i;j <= n;++j) {
			if (!cnt2[a[j]]) {
				q.push (a[j]);
				cnt2[a[j]] = 1;
				++cnt[a[j]];
			}
			else {
				int c = q.top ();
				while (c != a[j]) {
					cnt2[c] = 0;
					--cnt[c];
					q.pop ();
					c = q.top ();
				}
			}
		}
	}
	for (int i = 1;i <= m;++i) {
		cout<<cnt[i]<<' ';
	}
	return 0;
}
