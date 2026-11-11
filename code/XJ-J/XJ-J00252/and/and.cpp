#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m, ans = 2147483647, a[N], cnt;
void dfs(int idx, int num, int ce){
	if(ce == m){
		cnt = max(cnt, num);
		return ;
	}
	if(idx == n)
		return ;
	dfs(idx + 1, num, ce);
	dfs(idx + 1, num & a[idx+1], ce + 1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1, x; i <= n; i ++){
		cin >> a[i];
	}
	if(n == m){
		for(int i = 1; i <= n; i ++)
			ans &= a[i];
		cout << ans;
	}else if(n <= 5 || m <= 3){
		dfs(0, ans, 0);
		cout << cnt;
	}else{
		sort(a+1,a+1+n);
		cout << a[n-m+1];
	}
	return 0;
}
