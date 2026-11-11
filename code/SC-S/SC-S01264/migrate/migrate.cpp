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
int c;
int t;
int n;
long long d;
long long ans = 0;
long long x[1000005];
bool check(int i){
	return (x[i+3] - x[i] > d) && (x[i+2] - x[i] <= d) && (x[i+1] - x[i] <= d) && (x[i+3] - x[i+1] <= d) && (x[i+3] - x[i+2] <= d);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read();
	t = read();
	while (t--){
		n = read();
		d = read();
		for (int i = 1;i <= n;i++){
			x[i] = read();
		}
		int leng = 1;
		ans = 0;
		for (int i = 1;i <= n - 3;i++){
			if (check(i)){
				leng++;
			}
			else leng = 1;
			
			ans += leng / 2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/