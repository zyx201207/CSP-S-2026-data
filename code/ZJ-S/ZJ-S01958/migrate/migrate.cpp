#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int a[N];
int cnt[N], s[N];
int n, d;
struct node{
	int u, dep;
};
bool check(int x, int y){
	bool can = false;
	for(int i = x+1; i <= y; i++){
		if(a[i]-a[i-1] > d) return false;
		if(i > x+1 && a[i]-a[i-2] <= d){
			if(can) return false;
			can = true;
		}
		if(i > x+2 && a[i]-a[i-3] <= d) return false;
	}
	return true;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int bh, T;
	cin >> bh >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		long long cnt = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i+2; j <= n; j++){
				if(check(i, j)) cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
