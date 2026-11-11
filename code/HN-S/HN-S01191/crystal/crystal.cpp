#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
long long ans[500005];
bool func(){
	long long d = a[2] - a[1];
	for(int i = n;i >= 1;i--){
		if(a[i] - a[i-1] != d){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool f = false;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != i) f = true;
		ans[i] = ans[i-1] + a[i]; 
	}
	if(!f && m != 1){
		for(int i = n;i >= 1;i--){
			if(ans[i]/2 <= m){
				cout << i;
				return 0;
			}
		}
	}
	else if(!f && m == 1){
		cout << 2;
		return 0;
	}
	else if(func() && m == 1){
		if(a[2]-a[1] != -1){
			cout << 0;
			return 0;
		}
		else{
			cout << 2;
			return 0;
		}
	}
	else if(func() && m == (a[2]-a[1])){
		cout << 2;
		return 0;
	}
	else if(func() && m != 1){
		for(int i = n;i >= 1;i--){
			if(abs(ans[i]/2) <= m){
				cout << i;
				return 0;
			}
		}
	}
	long long sum = -1;
	for(long long r = n;r >= 1;r--){
		for(long long i = 1;i <= r;i++){
			if(ans[r] - ans[i-1] < a[r]*(r-i+1) && ans[r] - ans[i-1] + m >= a[r]*(r-i+1)){
				sum = max(sum, r-i+1);
			}
		}
	}
	cout << sum;
	return 0;
}
