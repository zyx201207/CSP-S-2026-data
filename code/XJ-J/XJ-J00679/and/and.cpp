#include <bits/stdc++.h>
using namespace std;
const int N = 2147483647;
int n, m, a[200005], maxn = -1e9, sum, ans = -1e9, cnt[3005], d[3005];
bool flag[200005];
void dfs(int x, int s){
	if(x == m){
		ans = max(ans, s);
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(flag[i] != true){
			flag[i] = true;
			dfs(x+1, s&a[i]);
			flag[i] = false;
		}
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m >> a[1];
	sum = a[1];
	for(int i = 2; i <= n; i++){
		cin >> a[i];
		maxn = max(maxn, a[i]);
		sum &= a[i];
		if(a[i] <= 3000)
			cnt[a[i]]++;
	}
	if(m == 1){
		cout << maxn;
		return 0;
	}
	if(m == n){
		cout << sum;
		return 0;
	}
	if(m == 2){
		maxn = -1e9;
		sort(a+1, a+n+1);
		for(int i = n; i >= 2; i--)
			maxn = max(a[i]&a[i-1], maxn);
		cout << maxn;
		return 0;
	}
	if(n <= 20){
		dfs(0, N);
		cout << ans;
		return 0;
	}
	if(maxn <= 3000){
		sum = maxn;
		m -= cnt[maxn];
		if(m <= 0){
			cout << maxn;
			return 0;
		}
		for(int i = maxn-1; i >= 1 && m >= 0; i--){
			if(cnt[i] != 0){
				sum &= i;
				m -= cnt[i];
			}
		}
		cout << sum;
		return 0;
	}
	return 0;
}

