#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+7;
int n,m;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crustal.out","w",stdout);
	cin >> n >> m;
	int mx = -INF,mi = INF;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		mx = max(mx,a[i]);
		mi = min(mi,a[i]);
	}
	sort(a+1,a+1+n);
	int ans = 0,cnt,x;
	for (int i = mi;i <= mx;i++){
		cnt = 0,x = m;
		for (int j = 1;j <= n;j++){
			if (a[j] > i){
				break;
			}
			if (x - (i-a[j]) >= 0){
				x -= (i-a[j]);
				cnt++;
			}
		}
		ans = max(ans,cnt);
	}
	cout << ans;
	return 0;
}
