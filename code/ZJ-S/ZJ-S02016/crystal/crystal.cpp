#include <bits/stdc++.h>
using namespace std;
inline void read(long long &x){
	long long k = 0,c = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-'){
			c = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		k *= 10;
		k += ch - '0';
		ch = getchar();
	}
	x = k * c;
}
long long n,m;
long long a[1000100];
long long cnt[1001000];
bool check(int k){
	for(int i = k;i <= n;i++){
		if(a[i] * k - (cnt[i] - cnt[i - k]) <= m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);
	read(m);
	for(int i = 1;i <= n;i++){
		read(a[i]);
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		cnt[i] = cnt[i - 1] + a[i];
	}
	int l = 1,r = n;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)){
			l = mid;
		}else{
			r = mid - 1;
		}
	}
	cout << l;
	return 0;
}
