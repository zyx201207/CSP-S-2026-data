#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
inline void read(long long &x){
	x = 0;
	bool f = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		f = (c == '-');
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c & 15);
		c = getchar();
	}
	if(f) x = -x;
}
long long a[N] , sum[N];
long long n , m;
inline bool ck(long long x){
	for(long long i = x;i <= n;++ i){
		if(a[i] * x - sum[i] + sum[i - x] <= m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	read(n) , read(m);
	for(long long i = 1;i <= n;++ i){
		read(a[i]);
	}
	sort(a + 1 , a + 1 + n);
	for(long long i = 1;i <= n;++ i) sum[i] = sum[i - 1] + a[i];
	long long l = 1 , r = n;
	while(l < r){
		long long mid = (l + r) >> 1;
		if(ck(mid)) l = mid + 1;
		else r = mid;
	}
	if(!ck(l)) -- l;
	cout << l << '\n';
	return 0;
}