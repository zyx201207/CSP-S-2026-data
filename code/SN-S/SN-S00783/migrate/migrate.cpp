#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e6 + 10;
ll n,m,A = 1,op,a[N]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		if (i == 2) {
			op = a[i] - a[i - 1]; 
		}
		if (a[i] - a[i - 1] != op) A = 0;
	}
	if (A) {
		if (op % m == 0) {
			cout << n / (m / op);
		}else {
			cout << n / (m / op + 1);
		}
		return 0;
	}
	return 0;
}
