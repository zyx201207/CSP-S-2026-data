#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n,m,a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a +1,a + n +1);
	int l = 1,cost = 0;
	for(int r = 1;r <= n;r++){
		cost += (a[r] - a[r - 1]) * (r - l);
		while(l < r && cost > m){
			cost -= a[r] - a[l];l++;
		}
		ans = max(ans,r - l + 1);
	}
	cout << ans;
	return 0;
}

