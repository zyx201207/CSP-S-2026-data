#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5*1e5+5;
typedef long long ll;

ll a[MAXN];
bool b[MAXN];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	ll m;
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	ll ans = 0, cnt = 0;
	for (int i=0; i<n; i++){
		if ((i+1) < n){
			if (a[i] == a[i+1]){
				b[i] = 1;
				b[i+1] = 1;
			} else{
				ll now = a[i+1]-a[i];
				if ((i+1)*now <= m && cnt < m){
					cnt += (i+1)*now;
					m -= (i+1)*now;
					b[i] = 1;
					b[i+1] = 1;
				}
			}
		}
	}
	for (int i=0; i<n; i++)
		if (b[i] == 1) ans++;
	cout << ans;
	return 0;
}
