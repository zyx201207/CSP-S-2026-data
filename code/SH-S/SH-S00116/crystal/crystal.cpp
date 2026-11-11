#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	long long n , m;
	cin >> n >> m;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	long long sum = a[1];
	long long l = 1;
	long long ans = -1;
	for(long long i = 2; i <= n; i++){
		while(a[i] * (i - l) - sum > m){
			ans = max(ans , i - l);
			sum -= a[l];
			l++;
		}
		sum += a[i];
	}
	cout << max(ans , n - l + 1);
} 
