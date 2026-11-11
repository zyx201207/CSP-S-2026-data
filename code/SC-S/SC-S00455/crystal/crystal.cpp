#include<bits/stdc++.h>
using namespace std;
long long sum[500005];
long long f[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
	}
	sort(f + 1, f + 1 + n);
	for (int i = 2; i <= n; i++) {
		sum[i] = (f[i] - f[i - 1]) * (i - 1) + sum[i - 1];
	}
	/*for (int lty = 1; lty <= n; lty++) {
		cout << sum[lty] << " ";
	}*/
	
	int l = 1, r = 1;
	int ans = -1;
	while (r <= n) {
		/*int q=0;
		for (int i = l; i <= r; i++) {
			q=q+f[r]-f[i];
		}*/
		
		if (sum[r] -(f[r]-f[l])*(l-1)-sum[l]> m) {
			l++;
			//cout<<q<<endl;
		} else {
			ans = max(ans, r - l+1 );
			//cout<<r-l+1<<endl;
			r++;
		}
		if (l == r) {
			r++;
		}
	}
	cout<<ans;
	return 0;
}
//a_i不是递增！！！CAN NOT USE SORT,5e5;
//but the use Ultra 9 285K CPU @ 3.70 GHz, 5e5 log 5e5 can?
//oh it can ,we can use sort
//“特殊性质B：a1,a2,...,an构成等差数列。”why give?
//to use 特殊性质.
//it ok,have 20pst
//oh , i think is not right, ans not is m/d!
//c[i]=(a[i]-a[i-1])*(i-1)+c[i-1];
//foxy,i have 20+pst!?
//only crystal4 no right ,think it why are not right?
/*
in
7 10
-10 0 1 2 2 2 3
out 2
ans 6
*/
//use if (a[2] - a[1] > (a[3] - a[2]) * 3),can AC my hack,but WA on crystal4
//crystal4 is very good hack
//min i do ,max? not to do it!
//do T2, I am not good
//i can not do T2,WHAT!only i can do T1;
//thinking:
//do it on
//i have idea!!!And i have 1h26min!
//5min,but i AC IT!!!! 