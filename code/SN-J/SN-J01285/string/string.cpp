#include<bits/stdc++.h>
using namespace std;
string s;
long long n , op , ans , num , sum;
char x;
int main() {
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++) {
		cin >> op >> x;
		ans += op;
		while(op--) {
			s += x;
		}
	}
	num = ans;
	if(ans % 2 == 0) {
		ans /= 2;
	} else {
		ans -= 1;
	    ans /= 2;
	}
	for(long long i = 0;i < ans;i++) {
		if(s[i] != s[num - i - 1]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}

