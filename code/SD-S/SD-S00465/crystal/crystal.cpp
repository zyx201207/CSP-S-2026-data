#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500010],r,l,b[500010],maxx = 1;
bool check(ll x,ll mx){
	ll maxnum = a[mx] * (mx - x + 1);
	ll posnum = b[mx] - b[x - 1];
	return (maxnum - posnum <= m);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	l = 1;r = n;
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i ++) b[i] = b[i - 1] + a[i];	
	for (int i = n;i >= 1;i --){
		l = 1;r = i;
		while (l < r){
			int mid = (l + r) / 2;
			if (check(mid,i)) r = mid;
			else l = mid + 1;
		}
		maxx = max(maxx,i - l + 1);
	}
	cout << maxx;
	return 0;
}

