#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fir first
#define sec second
#define endl '\n'
const int N = 1e6 + 5, INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
int a[N];
int s[N];

signed main(){
	fst
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++){
		s[i] = s[i - 1] + a[i];
	}
	a[n + 1] = INF;
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		int l = 1, r = i - 1, res = 0;
		while(l <= r){
			int mid = l + r >> 1;
			if(a[i] * (i - mid) - s[i - 1] + s[mid - 1] <= m){
				res = mid;
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans << endl;
	return 0;
}







//生活在经验里
//直到大厦崩塌
//云层深处的黑暗啊
//淹没心底的景观

// 1433474
