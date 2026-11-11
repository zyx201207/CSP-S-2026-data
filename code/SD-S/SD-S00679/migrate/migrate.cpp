#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fir first
#define sec second
#define endl '\n'
const int N = 1e6 + 5, INF = 0x3f3f3f3f3f3f3f3f;

int c;
int n, k;
int a[N];
void code(){
	cin >> n >> k;
	if(13 <= c && c <= 14){
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
		}
		int num = 0, ans = 0;
		for(int i = 1; i <= n; i ++){
			if(a[i] - a[1] <= k && a[n] - a[i] <= k){
				num = i;
				break;
			}
		}
		for(int i = num + 1; i <= n; i ++){
			a[i - 1] = a[i];
		}
		n --;
		for(int i = 3; i <= n; i ++){
			if(a[i] - a[i - 2] > k) ans ++;
		}
		cout << ans << endl;
	}else if(11 <= c && c <= 12){
		int x, y;
		cin >> x;
		for(int i = 2; i <= n; i ++){
			x = y;
			cin >> y;
		}
		if(y + y - x - x <= k && k < y - x + y - x + y - x){
			cout << max(0ll, n - 3) << endl;
		}else{
			cout << 0 << endl;
		}
	}
}

signed main(){
	fst
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int t;
	cin >> c >> t;
	while(t --) code();
	return 0;
}



/*
0 1
6 4
-3 0 1 2 3 4

6

*/

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/




//生活在经验里
//直到大厦崩塌
//云层深处的黑暗啊
//淹没心底的景观

// 1433474

