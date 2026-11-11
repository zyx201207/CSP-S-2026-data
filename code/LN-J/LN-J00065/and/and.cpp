#include<bits/stdc++.h>
#define finline inline __attribute__((always_inline))
using namespace std;
const int MAXN = 2e5 + 10;
int n,m,ans,a[MAXN];
inline void dfs(int x,int cnt,int now){
	if(cnt == m){
		ans = max(ans,now);
		//cout << endl;
		return;
	}
	if(now < ans) return;
	for(int i = x + 1;i <= n;++i){
		//cout << i << " ";
		dfs(i,cnt + 1,now & a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) cin >> a[i];
	if(n >= 2000&&m != n - 1){
		sort(a + 1,a + 1 + n,greater<int>());
		ans = a[1];
		for(int i = 2;i <= m;++i) ans &= a[i];
		cout << ans;
		return 0;
	}
	if(m == 1){
		cout << *max_element(a + 1,a + 1 + n);
		return 0;
	}
	if(m == 2){
		int ans = 0;
		for(int i = 1;i <= n;++i){
			for(int j = i + 1;j <= n;++j){
				ans = max(ans,a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(m == n){
		int ans = a[1];
		for(int i = 2;i <= n;++i) ans &= a[i];
		cout << ans;
		return 0;
	}
	if(m == n - 1){
		int ans = a[1];
		for(int i = 2;i <= n;++i) ans &= a[i];
		int ma = 0;
		for(int i = 1;i <= n;++i){
			ma = max(ma,ans ^ a[i]);
		}
		cout << ma;
		return 0;
	}
	if(n <= 20){
		//cout << "dfs: " << endl;
		for(int i = 1;i <= n;++i){
			dfs(i,0,a[i]);
		}
		//cout << endl;
		cout << ans;
		return 0;
	}
	return 0;
}
/*
5 3
31 3 1 15 7

7
*/
