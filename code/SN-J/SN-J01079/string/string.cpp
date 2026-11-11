#include<bits/stdc++.h>
using namespace std;
long long n, a[200005], l, ans, op, flag;
char c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> a[i] >> c[i];
		l += a[i];
		if(i >= 1 && c[i] != c[i - 1]) flag = 1;
	}
	if(flag == 0){
		cout << 0;
		return 0;
	}
	if(l % 2 == 1) op = 1;
	l /= 2;
	ans = l;
	long long f = 0;
	for(int i = 0; i < n; i ++){
		f += a[i];
		if(f >= l){
			f -= l;
//			if(op == 1) f += 1;
			ans -= min(a[i] - f, f);
			if(op == 1 && f != 0) ans += 1;
			break;
		}
	}
	long long i = 0, j = n - 1;
	while(l > 0){
		if(i == j) break;
		if(c[i] == c[j]){
			if(a[i] < a[j]){
				ans -= a[i];
				a[j] -= a[i];
				l -= a[i];
				i ++;
			}
			else if(a[i] > a[j]){
				ans -= a[j];
				a[i] -= a[j];
				l -= a[j];
				j --;
			}
			else{
				ans -= a[i];
				l -= a[i];
				i ++, j --;
			}
		}
		else{
			if(a[i] < a[j]){
				a[j] -= a[i];
				l -= a[i];
				i ++;
			}
			else if(a[i] > a[j]){
				a[i] -= a[j];
				l -= a[j];
				j --;
			}
			else{
				l -= a[i];
				i ++, j --;
			}
		}
	}
	cout << ans;
	return 0;
}
/*
3
2 a
2 b
1 c
*/
