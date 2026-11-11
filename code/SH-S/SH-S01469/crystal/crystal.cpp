#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n;
long long m;
long long a[N];
bool cuo1,cuo2;
long long k[N];
long ca;
long long sy[N];
long long sx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	cuo1 = true;
	cuo2 = true;
	long long ans = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != i){
			cuo1 = false;
		}
	}
	for(int i = 2;i < n;i++){
		if(a[i+1] - a[i] != a[i] - a[i-1]){
			cuo2 = false;
		}else{
			ca = a[i+1] - a[i];
		}
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j) continue;
			k[i] = k[i] + abs(a[i] - a[j]);
		}
	}
	int min = 0x3f;
	for(int i = 1;i <= n;i++){
		if(k[i] < min){
			min = k[i];
			sx = i;
		}
	}
	for(int i = 1;i <= n;i++){
		sy[i] = abs(a[i] - a[sx]);
	}
	sort(sy+1,sy+n+1);
	if(cuo1){
		for(int i = 1;i <= n / 2;i++){
			if(m >= 2 * i){
				m -= 2 * i;
				ans += 2;
			}else if(m >= i){
				m -= i;
				ans += 1;
			}
		}
		cout << ans;
	}else if(cuo2){
		for(int i = ca;i <= (n / 2) * ca;i += ca){
			if(m >= 2 * i){
				m -= 2 * i;
				ans += 2;
			}else if(m >= i){
				m -= i;
				ans += 1;
			}
		}
		cout << ans;
	}else{
		for(int i = 1;i <= n;i++){
			if(m >= sy[i]){
				m -= sy[i];
				ans++;
			}else{
				break;
			}
		}
		cout << ans;
	}
	return 0;
} 
