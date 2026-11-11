#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long x[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		long long n, d;
		cin >> n >> d;
		for (int j = 1; j <= n; j++){
			cin >> x[j];
		}
		if (n == d){
			cout << 0;
		}
	}
	return 0;
}

