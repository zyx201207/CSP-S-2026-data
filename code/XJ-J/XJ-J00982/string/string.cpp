#include<bits/stdc++.h>
using namespace std;
long long int n, a[200010], zc, o, b[200010], qu1 = 1, qu2 = 1, k1 = 0, k2 = 0, cnt = 0;;
char c[200010], d[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	o = n;
	for (int i = 1; i <= n; i ++){
		cin >> a[i] >> c[i];
		b[o] = a[i];
		d[o] = c[i];
		o --;
		zc += a[i];
	}
	for (int i = 1; i <= zc; i ++){
		k1 ++;
		k2 ++;
		if (k1 > a[qu1]){
			k1 -= a[qu1];
			qu1 ++;
		}
		if (k2 > b[qu2]){
			k2 -= b[qu2];
		    qu2 ++;	
		}
		if (c[qu1] != d[qu2])cnt ++;
		//cout << k1 <<' '<< k2 <<' '<< cnt << endl;
	}
	cout << cnt / 2;
	return 0;
}
/*
n    1    2    3    4    5    6  
a   10    10   10   10   10   10
b   10    10   10   10   10   10     
c    a    a    a    b    b    b
d    b    b    b    a    a    a
*/