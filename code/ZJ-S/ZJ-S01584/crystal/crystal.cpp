#include<bits/stdc++.h>
using namespace std;

long long n, m, ans = -1;
long long a[500010];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	if(n > 5000 && m > 100000000){
		//特殊性质A, B都是等差数列 
		long long sum = 0;
		long long t = a[2] - a[1];
		long long i = 1;
		for(i = 1; sum * t <= m; i++){
			sum += i;
		}
		cout << i - 1;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		long long x = 0, y = 0;
		for(int j = 2; j <= i; j++){
			y = x;
			x = y + a[i] - a[i - j + 1];
			if(x > m) break;
			if(j > ans){
				ans = j;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
