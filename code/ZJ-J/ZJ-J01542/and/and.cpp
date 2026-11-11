#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[100005];
long long ans;

void dfs(int num, long long sum){
	if(num == m + 1) {
		ans = max(sum, ans);
		return ;	
	}
	for(int i = num ;i <= n;i ++){
		dfs(num + 1, sum & a[i]);
	}
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	dfs(1, 1);
	cout << ans;
	return 0;
}
