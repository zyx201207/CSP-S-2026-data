#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 5e5 + 10;
long long a[N];
long long num[N];
long long sum[N];
long long n, m;
int ans = -1;
inline long long read() {
	long long f = 1;
	long long x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return f * x;
}

long long get(int l, int r){
//	cout << "r " << r << " l - 1 " << l - 1 << endl;
//	cout << "sum[r] " << sum[r] << " sum[l - 1] " << sum[l - 1] << " num[r] " << num[r] << endl;
	return (sum[r] - sum[l - 1]) - num[r] * (r - l + 1);
}

int find(int x){
//	cout << "==" << x << "==" << endl;
	if(sum[x] < m) return x;
	int l = 1, r = x, mid;
	while(l < r){
		mid = (r - l) / 2 + l; 
//		cout << "l " << l << " r " << r << " mid " << mid << endl; 
//		cout << "mid " << mid << " x " << x << " get " << tmp << endl;
		if(get(mid, x) <= m){	
			r = mid;
		}else{
			l = mid + 1;
		}
	}
//	cout << "res " << l << endl;
	return x - l + 1;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    n = read();
    m = read();
    for(int i = 1; i <= n; i++){
    	a[i] = read();
	}
	sort(a + 1, a + n + 1); 
	for(int i = 1; i <= n; i++){
		num[i] = a[n] - a[i];
		sum[i] = sum[i - 1] + num[i];
//		cout << i << " " << num[i] << endl;
//		cout << i << " " << sum[i] << endl;
	}
	for(int i = 1; i <= n; i++){
		ans = max(ans, find(i));
	}
	cout << ans; 
	return 0;
}
