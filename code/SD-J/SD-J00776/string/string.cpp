#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
string c,s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	if(n <= 1) {
		cout << 0;
		return 0;
	}
	else if(n > 1&&n <= 2) {
		cout << 1;
		return 0;
	}
	for(int i = 1;i <= n;i ++) {
		cin >> a[i] >> c[i];
		for(int j = 1;j <= a[i];j ++) s[j] = c[i];
	}
	int sum = 0;
	for(int i = 1;i <= n;i ++) {
		sum += a[i];
	}
	if(sum % 2 == 1 && n == sum) {
		cout << n - 3 << '\n';
		return 0;
	}
	else if(n % 2 == 0 && n == sum){
		cout << n - 2 << '\n';
		return 0;
	}
	else if(sum % 2 == 1 && n != sum) {
		cout << n - 3 - a; 
		return 0;
	}else if(sum % 2 == 0 && n != sum) {
		cout << n - 2 - a; 
		return 0;
	}
	if(sum <= 1) {
		int cnt = 0;
		while(i --) {
			if(s[i] == s[i + sum - 1]) {
				cout << cnt;
				return 0;
			}
			cnt ++;
		}
	}
	return 0;
}

