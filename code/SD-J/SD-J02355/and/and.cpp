#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 5;
LL ans, n, m, a[N], cnt;
void dfs(LL cur, LL sum, LL cnt){
	if(cur > n){
		if(cnt == m){
			ans = max(ans, cnt);
		}
		return ;
	}
	if(cnt == 0) dfs(cur + 1, a[cur], cnt + 1);
	else dfs(cur + 1, sum & a[cur], cnt + 1);
	dfs(cur + 1, sum, cnt);
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++){
		if((a[i] + 1 & a[i]) == 0)  cnt ++;
	}
	if(cnt == n){
		sort(a + 1, a + 1 + n);
		cout << a[n - m + 1];
	}//A 
	else if(m == 1){
		for(int i = 1;i <= n;i ++){
			ans = max(ans, a[i]);
		}
		cout << ans;
	}
	else if(m == 2){
		for(int i = 1; i <= n; i ++) {
			for(int j = i + 1;j <= n; j ++){
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
	}
	else{
		dfs(1, 0, cnt);
		cout << ans;
	}
	return 0;
}
