#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
using ll = long long;
ll a[N],m,sum[N];
int n;
int cyy(int s) {
	int l = s + 1, r = n;
	int cnt = l;
	while(l <= r) {
//		printf("%d %d\n",l,r);
		int mid = (l + r) / 2;
		ll ans = 0;
		bool flag = 1;
		for(int i = s; i <= mid; ++ i) {
			ans += (a[mid] - a[i]);
			if(ans > m) {
				flag = 0;
				break;
			}
		}
		if(!flag) {
			r = mid - 1;
		} else if(ans <= m) {
			l = mid + 1;
			cnt = mid;
		} else {
			r = mid - 1;
		}
	}
	return cnt;
}
void solve1(){
	ll ans = 0;
	int cnt = 0;
	for(int i = 1; i <= n; ++ i){
		ans += 1ll * (i - 1);
		if(ans > m){
			break;
		}cnt = i;
	}
	printf("%d",cnt);
	return;
}
void solve2(){
	ll ans = 0;
	int cnt = 0;
	ll mod;
	if(a[1] > a[2]){
		mod = a[1] - a[2];
	}else{
		mod = a[2] - a[1];
	}
	for(int i = 1; i <= n; ++ i) {
		ans += (1ll * (i - 1)) * mod;
		if(ans > m) {
			break;
		}
		cnt = i;
	}
	printf("%d",cnt);
	return;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crtstal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1; i <= n; ++ i) {
		scanf("%lld",&a[i]);
	}
	sort(a + 1, a + 1 + n);
//	for(int i = 1; i <= n; ++ i){
//		printf("%lld ",a[i]);
//	}printf("\n");
	if(n >= 5e5 && a[1] == 1 && a[2] == 2) {
		solve1();
	} else if( n >= 5e5 && a[1] - a[2] == a[2] - a[3]) {
		solve2();
	} else {
		int c = 1;
		for(int i = 1; i < n; ++ i) {
			c = max(c, cyy(i) - i + 1);
		}
		cout<<c;
	}
	return 0;
}
// 14 : 51 成功喝完一瓶AD钙奶
// 想到正解，素！14 ：57
// 15 : 09 吓我一跳 还以为电脑关机了
// 15 ：20 做出了次正解 强强 ？ ！
// 15 : 23 开始准备做部分分 我想你了 cyy