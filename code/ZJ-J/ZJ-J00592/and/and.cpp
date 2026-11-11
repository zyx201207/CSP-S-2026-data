#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

long long a[MAXN];

long long ans;

int n, m;

inline void dfs(int last, long long sum, int cnt){
	if(last > n){
		return ;
	}
	if(cnt == m){
//		cout << ans << " ";
		ans = max(ans, sum);
//		cout << "ans: " << ans << '\n';
		return ;
	}
	for(int i = last + 1; i <= n; ++ i){
//		cout << sum << " " << cnt << '\n';
		dfs(i, (sum & a[i]), cnt + 1);
	}
}

inline bool cmp(int x, int y){
	return x > y;
}

int main(){
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios :: sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i){
		cin >> a[i];
	}
	
//	long long ans;
	if(m == n){
		ans = a[1];
		for(int i = 2; i <= n; ++ i){
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}
	if(n > 2000){
		sort(a + 1, a + n + 1, cmp);
		cout << a[m];
		return 0;
	} 
	for(int i = 1; i + m - 1 <= n; ++ i){
		dfs(i, a[i], 1);
	}
//		cout << '\n';
	cout << ans;
	
	
	return 0; 
} 
