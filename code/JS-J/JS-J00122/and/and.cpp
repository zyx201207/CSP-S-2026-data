#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
// #define LOC
#ifdef LOC
#define DEBUG(x) cerr<<#x<<"="<<x<<"\n"
#else
#define DEBUG(x) ;
#endif
using namespace std;
int n;
int m;
int a[200002];
int cnt[32];
bool wasted[200002];
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		for(int j = 0; j < 30; j++){
			int bit = (1 << j);
			if(a[i] & bit){
				cnt[j]++;
			}
		}
	}
	// for(int i = 0; i < 20; i++){
	// 	cerr << cnt[i] << "\n";
	// }
	for(int j = 30 - 1; j >= 0; j--){
		DEBUG(cnt[j]);
		if(cnt[j] >= m){
			ans |= (1 << j);
			memset(cnt, 0, sizeof(cnt));			
			for(int i = 0; i < n; i++){
				if( (a[i] & (1 << j)) == 0 ) wasted[i] = true;
			}
			for(int i = 0; i < n; i++){

				if(wasted[i]) continue;
				for(int k = 0; k < 30; k++){
					int bit = (1 << k);
					if(a[i] & bit){
						// cerr << a[i] << "," << k << "\n";
						cnt[k]++;
					}
				}


			}
		}
		DEBUG(ans);
	}
	cout << ans << "\n";
	return 0;
}
/* fo zu bao you    mei you bug */
