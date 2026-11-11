#include<bits/stdc++.h>
using namespace std;
//不骗分是对题目的不礼貌！ 
const int N = 500010;//不要填错了qwq 
int n, m, a[N], last[N], mp[N], ans[N];
//last[i]表示下一个与a[i]相等的下标 
void each_game(int st) {
//	cout << "game" << st << ":"; 
	for(int i = st; i <= n; i++) {
		while(last[i] != i) i = last[i];
		ans[a[i]]++;
//		cout << i << " ";
	}
//	cout << endl;
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		last[i] = i;
	}
	for(int i = 1; i <= n; i++) {
		if(mp[a[i]]) {
			last[mp[a[i]]] = i;
		}
		mp[a[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		last[i] = mp[a[i]];
	}
//	for(int i = 1; i <= n; i++) {
//		cout << last[i] << " ";
//	} cout << endl;
	for(int i = 1; i <= n; i++) {
		each_game(i);
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
//总结，对于这种实现，最坏时间复杂度为n^2不满足通过要求 
//最坏情况：全不相同 

//在此吟诗一首：
//十年OI一场空， 
//忘开long long见祖宗。
//比赛期间数开小，
//教练自己两行泪。 
