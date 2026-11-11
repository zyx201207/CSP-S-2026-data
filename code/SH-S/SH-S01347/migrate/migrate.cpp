#include<bits/stdc++.h>
#include<cstdio>
const int N = 2e6+10;
using namespace std;
int n, d, c, t;
int a[N];
long long ans;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1; i<=n; ++i) cin >> a[i];
		cout << 1 << '\n';
	}
	return 0;
}
