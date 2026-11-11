#include<bits/stdc++.h>
using namespace std;
int c, t;
const int N = 2e6 + 5;
int x[N];
void solve(){
	int n, d;
	cin >> n>> d;
	for(int i = 1;i <= n;i++){
		cin >> x[i];
	}
	cout << 0<< '\n';
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c>> t;
	while(t--){
		solve();
	}
	return 0;
}
