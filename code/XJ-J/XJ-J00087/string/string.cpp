#include<bits/stdc++.h>
using namespace std;
long long n, a[10000001], sum;
string s, k[10000001]; 
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	bool flag = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> k[i];
		if(k[i] != k[i - 1] && i >= 2){
			flag = 1;
		}
	}
	if(!flag){
		cout << 0 << "\n";
		return 0;
	}
	bool flag1 = 0;
	for(int i = 1; i <= n; i++){
		if(i > n - i + 1) break;
		if(a[i] != a[n - i + 1] || k[i] != k[n - i + 1]){
			flag1 = 1;
		}
	}
	if(!flag1){
		cout << 0 << "\n";
		return 0;
	}
	int i = n / 2 + 1;
	for(i; i <= n; i++) sum += a[i];
	cout << sum << "\n";
	return 0;
} 
