#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long res = 0ll;
	long long a = 1ll;
	char ch = getchar();
	while (ch < '0' || ch > '9'){
		if (ch == '-') a = -1ll;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9'){
		res = res * 10ll + ch - '0';
		ch = getchar();
	}
	return res * (long long)a;
} 
int n;
long long a[1000005];
long long sum[1000005];
long long m;
bool check(int x){
	for (int i = x;i <= n;i++){
		long long x1 = a[i] * (long long)x;
		long long x2 = sum[i] - sum[i - x];
		if (x1 - x2 <= m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read();
	m = read();
	for (int i = 1;i <= n;i++){
		a[i] = read();
	}
	sort(a+1,a+1+n);
	for (int i = 1;i <= n;i++){
		sum[i] = sum[i-1] + a[i];
	} 
	int l = 1;
	int r = n;
	while (l < r-1){
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
//		printf("l:%d,r:%d\n",l,r);
	}
	printf("%d\n",l);
	return 0;
}