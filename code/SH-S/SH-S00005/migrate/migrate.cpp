#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N = 2e6 + 10;
LL c, T, n, d;
LL a[N];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(LL i = 1; i <= n; i++)	cin >> a[i];
		LL ans = 0;
//		for(LL i = 1; i <= n; i++)	cout << a[i] << ' ';
//		cout << '\n';
		for(LL i = 1; i <= n; i++){
			for(LL j = i + 1; j <= n; j++){
//				bool flg = false;
				LL min = 0;
				LL pre_s = -1;
				for(LL k = i; k <= j; k++){
					if(k + 2 <= j && a[k + 2] - a[k] == d){
//						cout << i << ' ' << j << ' ' << k << '\n';
						if(pre_s == k - 1)	min++;
						pre_s = k;
					}
					if(a[k] - a[k - 1] > d){
						min = 0;
						break;
					}
				}
				if(min == 1)	ans++;
			}
		}
		cout << ans << '\n';
	}
//	cout << 111 << '\n';
	return 0;
}

