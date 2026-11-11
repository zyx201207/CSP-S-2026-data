#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N], pw[32];
int n, m;
bool check(int x){
	int cnt = 0;
	for(int i = 1; i <= n; i++) if((a[i]&x) >= x) cnt++;
	return cnt >= m;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	pw[0] = 1;
	for(int i = 1; i <= 30; i++) pw[i] = pw[i-1]*2;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int k = 0;
	for(int i = 30; i >= 0; i--) if(check(k+pw[i])) k += pw[i];
	cout << k << '\n';
	return 0;
}
