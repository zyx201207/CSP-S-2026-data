#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 3;
int a[N] , b[N]; 
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out", "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n , m ;
	cin >> n >> m; //cerr << n << ' ' << m << '\n'; return 0;
	int w  = 0;
	for(int i = 1; i <= n; ++ i) cin >> a[i] ;
	sort(a + 1,  a + n + 1);
	for(int i = 1; i <= n; ++ i)b[i] = b[i - 1] + a[i];
	for(int i = 1; i <= n; ++ i){
		int l = 1 , r = i , ans = i;
		while(l <= r){
			int mid = l + r >> 1;
			//[mid , i] is ok?
		//	int res = 0;
			//for(int j = mid; j <= i; ++ j) res += a[i] - a[j];
			//assert(res == a[i] * (i - mid + 1) - (b[i] - b[mid - 1]));
			if(a[i] * (i - mid + 1) - (b[i] - b[mid - 1]) <= m) {
				ans = mid; r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		w = max(w , i - ans + 1);
	}cout << w << '\n';
	return 0;
}

