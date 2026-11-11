#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 100;
int x[N], n, d, c, t;
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		memset(x, 0, sizeof x); 
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		cout << n - 2 * d + 1 << endl;
	}
    return 0;
}
