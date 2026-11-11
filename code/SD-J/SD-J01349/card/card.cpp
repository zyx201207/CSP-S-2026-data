#include <bits/stdc++.h>
#define ll long long
#define pub push_back
#define pob pop_back
using namespace std;

const int N = 5e5 + 23;

int n, m, a[N];
int ans[N];
vector<int> card;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int num = 1; num <= n; num++) { // µÚnum¾ÖÓÎÏ· 
		card.clear();
		for (int i = num; i <= n; i++) { 
			if (!card.empty()) {
				int pos = lower_bound(card.begin(), card.end(), a[i]) - card.begin();
				if (card[pos] == a[i]) {
					while (card.back() != a[i]) 
						card.pob();
					card.pob();
				}
			}
			card.pub(a[i]);
		}	
		
		for (auto x : card) {
			ans[x]++;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	return 0;
}
