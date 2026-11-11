#include<bits/stdc++.h>
using namespace std;
long long n , m , a[500001] , b[500001] , ans , mi = LONG_MAX , x , cnt = 0;
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		ans += a[i];
	}
	sort(a + 1 , a + 1 + n);
	ans /= n;
	for(int i = 1;i <= n;i++){
		if(mi >= abs(a[i] - ans)){
			mi = abs(a[i] - ans) , x = i;
		}
	}
	for(int i = 1;i <= n;i++){
		if(i == x) continue;
		b[i] = abs(a[i] - a[x]);
	}
	sort(b + 1 , b + 1 + n);
	for(int i = 1;i <= n;i++){
		if(m > 0){
			if(m < b[i]) break;
			cnt++;
			m -= b[i];
		}else break;
	}
	cout << cnt;
	return 0;
} 
