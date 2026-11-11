#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
int maxn = 0;
int n, m;
void dfs(int step, int cnt, int sa){
	//printf("M %lld\n", m);
	if(cnt > m) return;
	if(step > n){
		if(cnt == m) {
			// printf("%lld %lld %lld\n", step, cnt, sa);
			maxn = max(maxn, sa);
		}
		return;
	}
	dfs(step+1, cnt, sa);
	if(cnt < m) dfs(step+1, cnt+1, sa & a[step]);
}
bool b4(){
	for(int i = 1; i <= n; i++){
		if(a[i] >= 4) return 0;
	}
	return 1;
}
int t[4];
signed main(){
	freopen("and.in", "r", stdin);
	// printf("SUC\n");
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	if(n <= 2000 && m == 2){
		int maxn = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j) continue;
				maxn = max(maxn, a[i] & a[j]);
			}
		}
		cout << maxn << endl;
		return 0;
	}
	if(n <= 20){
		dfs(1, 0, 0b11111111111111111111111111111111111);
		cout << maxn << endl;
		return 0;
	}
	
	if(b4()){
		for(int i = 1; i <= n; i++){
			t[a[i]]++;
		}
		if(t[3] >= m) printf("3\n");
		else if(t[3] + t[2] >= m) printf("2\n");
		else if(t[3] + t[1] >= m) printf("1\n");
		else printf("0\n");
		return 0;
	}
	
	
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	int sa = a[1];
	for(int i = 2; i <= m; i++){
		sa = sa & a[i];
	}
	printf("%lld\n", sa);
	return 0;
}
