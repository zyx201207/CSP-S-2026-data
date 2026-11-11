#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
/*
多测清空
build
初始化
dij vis[s]不要设为0 
线段树4倍空间
并查集merge 比较fx 和fy 
树状数组跳到值域 
*/
const int MAXN = 2e6 + 3;
int n;
ll d, a[MAXN];
void solve1(){
	cin >> n >> d;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	ll d_ = a[2] - a[1];
	int k = (n - 1) * d_ / d;
//	cout << "n : " << n << "d = " << d << "\n";
//	cout << "d' = " << d_ << " k : " << k << "\n";
	if(d < 2 * d_){
		cout << "0\n";
		return ;
	}
	if(1ll * k * d == 1ll * (n - 1) * d_){
		cout << "0\n";
	} else {
		cout << k << "\n";
	}
}
int main(){
	IOS
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
//	if(c == 11 || c == 12){
		while(t--){
			solve1();
		}
//	}
	return 0;
}
