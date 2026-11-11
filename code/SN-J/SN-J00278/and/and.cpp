#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], maxx, ans, ans1, cnt;
bool f1 = 1, f2 = 1;
void dfs(int sum, int num, int id){
	if (id == n + 1){
		if (num == m){
			ans1 = max(ans1, sum);
		}
		return;
	}
	if (num > m){
		return;
	}
	if (num == 0){
		dfs(a[id], num + 1, id + 1);
		dfs(0, num, id + 1);
	}
	else{
		dfs(sum & a[id], num + 1, id + 1);
		dfs(sum, num, id + 1);
	}
}
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> a[1];
	ans = a[1];
	if (pow(2, log2(n)) != n){
		f2 = 0;
	}
	if (a[1] != 0){
		f2 = 0;
	}
	for (int i = 2; i <= n; i++){
		cin >> a[i];
		if (pow(2, (int)log2(a[i] + 1)) != a[i] + 1){
			f1 = 0;
		}
		if (a[i] != i - 1){
			f2 = 0;
		}
		maxx = max(maxx, a[i]);
		ans &= a[i];
	}
	if (f1){
		sort(a + 1, a + n + 1, cmp);
		cout << a[m];
		return 0;
	}
	else if (f2){
		cnt = 0;
		int t = n;
		if (m > n / 2){
			cout << 0;
			return 0;
		}
		while (m <= n / 2){
			n /= 2;
			cnt++;
		}
		cout << t - pow(2, log2(t) - cnt);
		return 0;
	}
	if (n <= 20){
		dfs(0, 0, 1);
		cout << ans1;
		return 0;
	}
	if (m == 1){
		cout << maxx;
		return 0;
	}
	else if (m == n){
		cout << ans;
		return 0;
	}
	else if (m == 2){
		int x = 0;
		for (int i = 1; i < n; i++){
			for (int j = i + 1; j <= n; j++){
				x = max(a[i] & a[j], x);
			}
		}
		cout << x;
		return 0;
	}
	return 0;
}
