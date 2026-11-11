#include <bits/stdc++.h>
#define ine long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int n,m;
int a[N];
int b[N];
bool check(int x){
	int ans = 0;
	for (int i = 1;i <= x;i++){
		int tmp = a[x] - a[i];
		ans += tmp;
		if (ans > m) break;
	}
//	cout<<ans<<endl;
//	if (ans <= m) cout<<x<<' '<<ans<<endl;
	if (ans <= m) return 1;
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++) {
		cin>>a[i];
	}
	sort(a + 1,a + n + 1);
	int l = 1,r = n;
	while (l < r - 1){
		int mid = (l + r) / 2;
//		cout<<l<<' '<<r<<' '<<mid<<' '<<check(mid)<<endl;
		if (check(mid)) l = mid;
		else r = mid;
	}
	cout<<l;
	return 0;
}

