#include <iostream> 
#include <map>
using namespace std;
const int N = 2e5 + 5;
const int M = 3e5 + 5;
map<int, int> mp;
int n, m, a[N], cnt[M], b[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		mp.clear();
		int l = 0;
		for (int j = i; j <= n; j++) {
			if (mp.count(a[j]) && mp[a[j]] != -1) {
				int t = mp[a[j]];
				for (int k = mp[a[j]]; k <= l; k++) mp[b[k]] = -1;
				l = t - 1;
			}
			b[++l] = a[j];
			mp[a[j]] = l;
		}
		for (int j = 1; j <= l; j++) {
			cnt[b[j]]++;
		}
	}  
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}
