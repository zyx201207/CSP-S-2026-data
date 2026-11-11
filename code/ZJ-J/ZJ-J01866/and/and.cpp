// Pass 75
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, final, ansm;
int a[200005], b[200005];

bool check(int x){
	while (x != 1){
		if (x % 2 != 0) return false;
		x /= 2;
	}
	return true;
}

void dfs(int k, int now){
	if (k > m){
		int ans = b[1];
		for (int i = 2; i <= m; i++) ans &= b[i];
		final = max(final, ans);
	}
	else{
		for (int i = now + 1; i <= n; i++){
			b[k] = a[i];
			dfs(k + 1, i);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	//
	bool flagB = 1, flagA = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (i == 1) ansm = a[i];
		else ansm &= a[i];
		if (check(a[i] + 1) == false) flagA = 0;
		if (a[i] != i - 1) flagB = 0;
	}
	
	//
	if (m == n){
		cout << ansm << '\n';
	}
	else if (flagA){
		sort(a + 1, a + 1 + n);
		cout << a[n - m + 1] << '\n';
	}
	else if (flagB){
		int ans = a[n];
		for (int i = n - 1; i >= n - m + 1; i--) ans &= a[i];
		cout << ans << '\n';
	}
	else{
		dfs(1, 0);
		cout << final << '\n';
	}
	
	//
	
	return 0;
}