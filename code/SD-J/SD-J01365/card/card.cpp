#include <bits/stdc++.h>
#define int long long
using namespace std;
const unsigned long long rp = 2e18;
int n,m;
int a[500010],ans[300010];
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int k = 1;k <= n;++k) {
		stack<int> st;bitset<300010> v;
		for (int i = k;i <= n;++i) {
			if (v[a[i]]) {
				while (st.top() != a[i]) v[st.top()] = 0,st.pop(); 
			}
			else st.push(a[i]),v[a[i]] = 1;
		}
		while (st.size()) ++ans[st.top()],st.pop();
	}
	for (int i = 1;i <= m;++i) cout << ans[i] << " ";
	return 0;
}

