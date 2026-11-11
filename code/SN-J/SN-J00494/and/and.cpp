#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,a[200005],b[200005],maxn;
int ans = INT_MAX,lg[35],cur;
bool f1 = 1,f2 = 1;
map<int,bool> mp;

bool cmp(int x,int y) {
	return x > y;
}

void dfs(int step,int x,int c) {
	if (x <= maxn) return ;
	if (c > m) {
		if (x != INT_MAX)
			maxn = max(maxn,x);
		return ;
	}
	if (step > n) return ;
	for (int i = 1;i <= n;i++)
		if (b[i] == 0) {
			dfs(step + 1,x,c);
			b[i] = 1;
			dfs(step + 1,x & a[i],c + 1);
			b[i] = 0;
		}
	return ;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	lg[0] = mp[1] = 1;
	for (int i = 1;i <= 30;i++) {
		lg[i] = lg[i - 1] * 2;
		mp[lg[i]] = 1;
	}
	cin >> n >> m;
	if (mp[n] == 0) f2 = 0;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		ans &= a[i];
		if (mp[a[i] + 1] == 0) f1 = 0;
		if (a[i] != i - 1) f2 = 0;
	}
	sort(a + 1,a + n + 1,cmp);
	if (m == 1) {
		cout << a[1] << "\n";
		return 0;
	} if (m == n) {
		cout << ans << "\n";
		return 0;
	} if (f1) {
		cout << a[m] << "\n";
		return 0;
	} if (f2) {
		ans = a[1];m--;
		for (int i = 2;i <= m;i++) {
			if (mp[i] == 1) {
				cur++;
				ans -= lg[cur];
			}
		}
		cout << ans - 1 << "\n";
		return 0;
	} if (m == 2) {
		int maxn = 0;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				if (i != j) {
					ans = (INT_MAX & a[i] & a[j]);
					maxn = max(maxn,ans);
				}
		cout << maxn << "\n";
		return 0;
	} if (m == n - 1) {
		int maxn = 0;
		for (int i = 1;i <= n;i++) {
			ans = INT_MAX;
			for (int j = 1;j <= n;j++)
				if (i != j)
					ans &= a[j];
			maxn = max(maxn,ans);
		}
		cout << maxn << "\n";
		return 0;
	}
	dfs(1,INT_MAX,1);
	cout << maxn << "\n";
	return 0;
}
