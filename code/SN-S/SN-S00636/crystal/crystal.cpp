#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;

int n;
ll a[N], m, ans, cost, len;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>a[i];
	sort(a + 1, a + n + 1);
	int l = 1;
	int r = 1;
	len = 1;
	while(r < n){
		r++;
		cost += len * (a[r] - a[r - 1]);
		while(cost > m){
			cost -= a[r] - a[l];
			l++;
		}
		len = r - l + 1;
		ans = max(ans, len);
	}
	cout<<ans<<'\n';
	return 0;
}
