#include<bits/stdc++.h>
#define ll long long
using namespace std;
//进行拆分成二进制后的前缀和，依次遍历看是否大于m
int a[200010], s[40];
int n,m;
int maxn = -2e9;
void dfs(int l, int st, int sum){
	if(l > m){
		maxn = max(maxn, sum);
		return ;
	}
	for(int i = st;i<=n;i++){
		dfs(l+1, i+1, sum & a[i]);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		dfs(2, i+1, a[i]);
	}
	
	cout << maxn;
	return 0;
}