#include<bits/stdc++.h>
using namespace std;

const long long N = 1000000000001;
long long n, m, a[500005], ans;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld", &n);
	scanf("%lld", &m);
	for(long long i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	int i = 1;
	for(long long i = 1; i <= n && m > 0; i++){
		if(a[i] == N){
			continue;
		}
		for(long long j = 1; j <= n; j++){
			if(a[j] == N){
				continue;
			}
			if(a[i] == a[j]){
				ans++;
				a[i] += a[j];
				a[j] = N;
			}
			else if(a[i] > a[j]){
				swap(a[i], a[j]);
			}
			else if(a[i] < a[j]){
				if(m - (a[j] - a[i]) >= 0){
					m -= a[j] - a[i];
					ans++;
					a[i] = 2 * a[j];
					a[j] = N;
				}
			}
		}
	}
	printf("%d", n - ans + 2);
	return 0;
} 
