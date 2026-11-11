#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
int n, m, ans, mx;
int a[N], vis[N]; 
void dfs(int dep, int num){
	if(dep >= m){
		ans = max(num, ans);
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			vis[i] = 1;
			if(dep != 0)dfs(dep + 1, num & a[i]);
			else dfs(dep + 1, a[i]);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int j = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	dfs(0, 0);
	printf("%d", ans);
	return 0;
}

