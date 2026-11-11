#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005];
struct node{
	int s, num;
};
vector <node> V[40];//V[i]:转换为二进制后，第i位为1的数
int pow2[40] = {1, 2};
map <int, bool> vis;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int len = log2(n);
	for (int i=2; i<=30; ++i) pow2[i] = pow2[i-1]*2;
	bool B = true;
	if (n != pow2[len]) B = false;
	bool A = true;
	for (int i=1; i<=n; ++i){
		scanf("%d", a+i);
		int len = ceil(log2(a[i]+1));
		if (a[i] != pow2[len]-1) A = false;
		if (a[i] != i-1) B = false;
	}
	sort(a+1, a+n+1);
	len = 1;
	int num = a[1];
	for (int i=2; i<=n; ++i){
		if (a[i] == a[i-1]){
			len++;
		}else{
			for (int j=1; pow2[j-1]<=num; ++j){
				if (num%pow2[j] >= pow2[j-1]){
					V[j].push_back({len, num});
				}
			}
			len = 1, num = a[i];
		}
	}
	for (int j=1; pow2[j-1]<=num; ++j){
		if (num%pow2[j] >= pow2[j-1]){
			V[j].push_back({len, num});
		}
	}
	if (m == 1){
		int ans = 0;
		for (int i=1; i<=n; ++i){
			ans = max(ans, a[i]);
		}
		cout << ans << endl;
		return 0;
	}
	if (m == n){
		int ans = a[1];
		for (int i=2; i<=n; ++i){
			ans = ans & a[i];
		}
		cout << ans << endl;
		return 0;
	}
	if (n <= 2000 && m == 2){
		int ans = 0;
		for (int i=1; i<=n; ++i){
			for (int j=1; j<=m; ++j){
				if (i != j){
					ans = max(ans, a[i]&a[j]);
				}
			}
		}
		cout << ans << endl;
		return 0;
	}
	if (A){
		sort(a+1, a+n+1);
		cout << a[n-m+1] << endl;
		return 0;
	}
	if (B){
		int len = ceil(log2(n+1));
		if (m-len <= 0){
			cout << a[n] << endl;
			return 0;
		}
	}
	bool ok = false;
	long long ans = 0;
	len = ceil(log2(a[n]+1));
	for (int i=len; i; --i){
		if (!ok){
			int cnt = 0;
			for (auto x : V[i]){
				cnt += x.s;
			}
			if (cnt >= m){
				ok = true;
				for (auto x : V[i]){
					vis[x.num] = true;
				}
				ans = pow2[i-1];
			}
		}else{
			int cnt = 0;
			for (auto x : V[i]){
				if (vis[x.num]){
					cnt += x.s;
				}
			}
			if (cnt >= m){
				ans += pow2[i-1];
			}
		}
	}
	cout << ans << endl;
	return 0;
}