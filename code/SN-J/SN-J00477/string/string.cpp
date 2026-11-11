#include<bits/stdc++.h>
using namespace std;

long long n, nl, nr, L, R, ans, a[200010];
char l, r, c[200010];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cin >> c[i];
	}
	L = 1;
	R = n;
	l = c[L];
	r = c[R];
	nl = a[L];
	nr = a[R];
	while(L < R){
		long long t = 0;
		if(l != r){
			t = 1;
		}
		if(nl == nr){
			ans += t * nl;
			L++;
			R--;
			l = c[L];
			r = c[R];
			nl = a[L];
			nr = a[R];
		}else if(nl < nr){
			ans += t * nl;
			nr -= nl;
			L++;
			l = c[L];
			nl = a[L];
		}else{
			ans += t * nr;
			nl -= nr;
			R--;
			r = c[R];
			nr = a[R];
		}
	}
	cout << ans << "\n";
	return 0;
}
/*
哦耶~ 桃花谢了有玫瑰~

人生几十年总会有风雨来陪 嘿~
潇潇洒洒赴会今不醉不归 耶~
往事后不后悔 慢慢去体会
此刻朋友这杯酒最珍贵 
*/
