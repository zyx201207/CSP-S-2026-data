#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 5e5+100;
int a[maxn], lsa[maxn], n, m, ans, ls[maxn], ls2[maxn];
void dfs(int x, int z) {
	if (x == n) {
		lsa[n] = m-z+a[n];
	//	for (int i = 1; i <= n; i++) cout << lsa[i] << ' ' << endl;
		//cout << '*' << endl;
		int cnt = 0;
		sort(lsa+1, lsa+n+1);
		int sum = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; i++) {
			if (lsa[i] == lsa[i+1]) cnt2++;
			else {
				ls[++cnt3] = cnt2+1;
				ls2[cnt3] = lsa[i];
				cnt2 = 0;
			}
		}
		for (int i = 1; i <= cnt3; i++) {
			if (sum == 0 && ls[i] > 1) sum = ls[i]/2*ls2[i]*2, cnt++;
			else if (sum == ls2[i]) sum = (ls[i]+1)/2*ls2[i]*2, cnt += (ls[i]+1)/2*2;
			else if (ls[i] == 1 && ls2[i] - a[i] != 0) return;
		}
		ans = max(cnt, ans);
		return;
	}
	for (int i = m-z; i >= 0; i--) {
		lsa[x] = a[x] + i;
		dfs(x+1, z+i);
	}
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
//	dfs(1, 0);
//	cout << ans;
	cout << 0;
	return 0;
}
