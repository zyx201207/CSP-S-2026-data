#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5;
long long A[N];
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n);
	int a = A[1] - A[0], t = 1;
	for (int i = 2; i < n; i++) {
		if (A[i] - A[i - 1] != a) {
			t = 0;
			break;
		}
	}
	if (t) {
		int i = a;
		for ( ; m - i >= 0; i += a) {m -= i;}
		int cnt = i / a;
		if (cnt > n) cout << n;
		else cout << cnt;
		return 0;
	}
	
	int ans = -1;
	for (int i = 1; i < n; i++) {
		int cnt = 1, k = m;
		for (int j = i - 1; j >= 0; j--) {
			if (A[i] - A[j] <= k) {
				cnt++;
				k -= A[i] - A[j];
			}
			else break;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}