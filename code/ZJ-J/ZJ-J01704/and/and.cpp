#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, ans, maxx, minn = 40, cnt = 1;
int a[N], vis[N], cc[N];
void dfs(int x, int s, int now){
	if(s == m){
		ans = max(ans, now);
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i])continue;
		vis[i] = 1;
		dfs(i, s + 1, now & a[i]);
		vis[i] = 0;
	}
}
int lowbit(int x){
	return x & -x;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		maxx = max(maxx, a[i]);
		int x = a[i];
		for(; x; x -= lowbit(x)){
			cc[i]++;
		}
		minn = min(cc[i], minn);
	}
	for(int i = 2; i <= n; i++){
		if(a[i] == a[i - 1])cnt++;
	}
		
	if(m == n){
		ans = a[1];
		for(int i = 1; i <= n; i++){
			ans &= a[i];
		}
		printf("%d\n", ans);
	}
	else if(m == 1){
		printf("%d\n", maxx);
	}
	else if(m == 2){
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				ans = max(ans, a[i] & a[j]);
			}
		}
		printf("%d\n", ans);
	}
	else if(m == n - 1){
		for(int i = 1; i <= n; i++){
			if(cc[i] != minn){
				ans &= a[i];
			}
		}
		printf("%d\n", ans);
	}
	else if(maxx <= 4){
		printf("4");
	}
	else if(cnt == n){
		printf("%d", a[1]);
	}
	else{
		for(int i = 1; i <= n; i++){
			vis[i] = 1;
			dfs(i, 1, a[i]);
			vis[i] = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
