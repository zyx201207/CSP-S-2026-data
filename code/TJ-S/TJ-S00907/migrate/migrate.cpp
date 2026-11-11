#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t;
unsigned long long d;
long long a[N], n;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
	}
	return 0;
}

