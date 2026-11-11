#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int c,t;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		cout << n/d;
	}
	return 0;
}
