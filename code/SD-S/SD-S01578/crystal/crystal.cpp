#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(I, A, B) for(int I = (A); I <= (B); I++)
#define den(I, A, B) for(int I = (A); I >= (B); I--)
#define debug "-------------"
#define int long long
/*
很闲然 先排序
然后这个具有单调性，直接二分
二分对于长度为 mid 的滑动窗口 然后就做完了
tim : 14:38 待完成 
tim : 15:23 看完前三题 写代码 
tim : 15:35 写完代码 测试完成 
*/
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 5e5 + 5;
int a[N];
int s[N];
int lim;
int n;
bool check(int len){
	for(int l = 1, r = l + len - 1; r <= n; l++, r = l + len - 1){
		int cur = a[r] * len - (s[r] - s[l - 1]);
//		cout << l << " " << r << " " << cur << endl;
		if(cur <= lim) return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> lim;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);
	rep(i, 1, n) s[i] = s[i - 1] + a[i];
	int l = 1, r = n;
	int ans = 1;
	while(l <= r){
		int mid = (l + r) >> 1;
//		cout << mid << " " << check(mid) << endl;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}else r = mid - 1;
//		cout << debug;
	}
	cout << ans << endl;
	return 0;
}

