#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5 * 1e5 + 5;
int n, m, ans;
int a[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int r = 1; r <= n; r++){
		int x = m, cnt = 0;
		for(int l = r - 1; l >= 1; l--){
			//cout << "r: " << r << " l: " << l << " x: " << x << " c: " << c[r] - c[l - 1] << endl;
			if(x - (a[r] - a[l]) >= 0){
			//	cout << "r: " << r << " l: " << l << endl;
				cnt++;
				x -= a[r] - a[l];
			}
			else{
			//	cout << "r: " << r << " l: " << l << " x: " << x << " c: " << c[r] - c[l - 1] << endl;
				break;
			}
		}
		//cout << "r: " << r << " cnt: " << cnt << endl;
		ans = max(ans, cnt + 1);
	}
	cout << ans;
	return 0;
}
