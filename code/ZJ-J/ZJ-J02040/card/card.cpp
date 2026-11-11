#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector<int> Ans(m + 1);
	for (int i = 1; i <= n; i ++) {
		vector<int> t, sccx(m + 1, 1e9);
		int now = 0;
		for(int j = i; j <= n; j ++) {
			if (sccx[a[j]] < now) {
				now = sccx[a[j]] + 1;
			} else {
				t.push_back(a[j]);
				now ++;
				sccx[a[j]] = j;
				
			}
		}
		for (int j = 0; j < now; j ++) {
			Ans[t[j]] ++;
		}
	}
	for (int i = 1; i <= m; i ++) {
		cout << Ans[i] << ' ';
	}
	return 0;
}