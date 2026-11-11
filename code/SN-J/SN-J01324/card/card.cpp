#include <bits/stdc++.h>
#define int long long
#define INIT(a, n, v) for(int i = 1; i <= n; i++) a[i] = v
using namespace std;
const int N = 5e5 + 5;
int n, a[N], cnt[N], ans[N], m, flag1 = 1, flag2;
void solve1(){
	for(int i = 1; i <= n; i++){
		ans[a[i]] = i;
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
}
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i > 1 && a[i] < a[i - 1]) flag1 = 0;
		if(i > 1 && a[i] != a[i - 1]) flag2++;
	}
	if(flag1){
		solve1();
		return 0;
	}
	for(int i = 1; i <= n; i++){
		INIT(cnt, n, 0);
		stack<int> stk;
		for(int j = i; j <= n; j++){
			if(cnt[a[j]]){
				while(!stk.empty() && stk.top() != a[j]){
					cnt[stk.top()]--;
					stk.pop();
				}
			}else{
				stk.push(a[j]);
				cnt[a[j]]++;
			}
		}
		for(int i = 1; i <= m; i++) ans[i] += cnt[i];
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
