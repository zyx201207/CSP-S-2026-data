#include<bits/stdc++.h>
using namespace std;
long long int n, m, a[200010], cnt, mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.oiut","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	cnt = a[1];
	mx = a[1];
	for (int i = 2; i <= n; i ++){
		cin >> a[i];
		mx = max(mx, a[i]);
		cnt = cnt & a[i];
	}
	if (m == 1)cout << mx;
	if (m == n)cout << cnt;
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int r1(long long int x){
	int g, x1 = 1;
	while (x > 0){
		g = x % 2;
		x -= g;
		x /= 2;
		x1 *= 10;
		x1 += g;
	}
	return x1;
	
}
int r2(long long int x1){
	long long int x, g;
	while (x1 != 1){
		g = x1 % 10;
		x1 -= g;
		x1 /= 10;
		x *= 10;
		x += g;
	}
	return x;
}
int c(long long int x){
	long long int cnt;
	while (x > 0){
		x /= 2;
		cnt ++;
	}
	return cnt;
}
int d(long long int x,long long int y, int x1, int x2){
	long long int k, g1, g2, z = 1, g3;
	int mx = max(x1, x2);
	if (x1 == mx){
		k = mx - x2;
		for (int i = 1; i <= k; i ++)
		    y *= 10;
	}
	else {
		k = mx - x1;
		for (int i = 1; i <= k ; i ++)
		    x *= 10;
	}
	
	while (x != 1 && y != 1){
		g1 = x % 10;
		g2 = y % 10;
		g3 = g1 & g2;
		x -= g1;
		y -= g2;
		x /= 10;
		y /= 10;
		z *= 10;
		z += g3;
	}
	int l = c(z);
	long long int p = 1;
	for (int i = 1; i <= l; i ++){
		p *= 10;
	}
	z = z % p;
	return z;
}
long long int n, m, a[200010], mx;
int main(){
	cin >> n >> m;
    for (int i = 1; i <= n; i ++){
    	cin >> a[i];
    	mx = max (a[i], mx);
	}
	if (m == 1){
		cout << mx ;
		return 0;
	}
	if 
	cout << d(111,1001,2,3);
	cout << 1;
}
*/