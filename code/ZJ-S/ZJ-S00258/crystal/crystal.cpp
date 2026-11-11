#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n,m,a[N],ans = -1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1,a + n + 1);
	ll l = 1,cnt = 0;
	for(int i = 2;i <= n;i ++){
		ll t = (a[i] - a[i - 1]) * (i - l);
		if(cnt + t <= m) cnt += t;
		else{
			ans = max(ans,i - l);
			cnt -= (a[i - 1] - a[l]);
			l ++;
			i --;
		}
	}
	ans = max(ans,n - l + 1);
	cout << ans;
	return 0;
}
