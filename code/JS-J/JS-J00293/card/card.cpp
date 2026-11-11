#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
int a[500005];
int mp[300005];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		}
	for (int i=1;i<=n;i++) {
		set<int> st;
		deque<int> dq;
		for (int j=i;j<=n;j++) {
			int k = a[j];
			if (st.count(k)) {
				while (!dq.empty()) {
						int x = dq.back();
						if (x == k) {
							break;
						}
						dq.pop_back();
						st.erase(x);
				}
				
			} else {
				dq.push_back(k);
				st.insert(k);
				}
		}
		for (auto it=st.begin();it!=st.end();++it) {
			mp[*it]++;
			}
	}
	for (int i=1;i<=m;i++) {
		cout << mp[i] << ' ';
		}
	return 0;
}
