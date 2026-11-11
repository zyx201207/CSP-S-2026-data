#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
const int M = 300005;
int n, m;
int a[N], last[M], ans[M]; 
void dfs(int s){
	if(s == n + 1)return;
	ans[a[s]]++;
	dfs(last[a[s]] + 1);
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		last[a[i]] = i;
	}
	for(int i = 1; i <= n; i ++)dfs(i);
	for(int i = 1; i <= m; i ++){
		cout << ans[i] << " ";
	}
	return 0;
}
