#include<bits/stdc++.h>

using namespace std;

#define LL long long

inline void read(LL &x){
	x = 0;int f = 1, c = getchar();
	while (c < 48 || c > 57){
		if (c == '-') f = -1;
		c = getchar(); 
	}
	while (c >= 48 && c <= 57){
		x = (x << 3) + (x << 1) + (c & 15);
		c = getchar();
	}
	x *= f;
}
const int N = 500100;
LL n, m, a[N], ans = -1, now;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);read(m);
	for (int i = 1;i <= n;i ++)
		read(a[i]);
	
	sort(a + 1, a + 1 + n);
	for (int i = 1, l = 1;i <= n;i ++){
		now += (a[i] - a[i - 1]) * (i - l);
		if (now <= m){
			ans = max(ans, 1ll * i - l + 1);
		}
		else {
			while (now > m){
				now -= a[i] - a[l];
				l ++;
			}
			ans = max(ans, 1ll * i - l + 1);
		}
	}
	cout << ans << endl;
	
	return 0; 
}
