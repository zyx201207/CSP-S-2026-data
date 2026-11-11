#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N], vis[N], tot[N], r[N];
int ans[N];
void dfs(int i, int k){
	if(i == n + 1) return;
	if(r[a[i]] == i){
		ans[a[i]] += k;
		dfs(i + 1, k);
	}
	else dfs(r[a[i]], k);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		tot[a[i]]++;
	}
	for(int i = n; i >= 1; i--)
		r[a[i]] = max(r[a[i]], i);
	int cnt = 0;
	for(int i = n; i >= 1; i--){
		if(vis[a[i]]) continue;
		vis[a[i]] = 1;
		cnt++;
		dfs(i, tot[a[i]]);
		if(cnt == m) break;
	
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}
