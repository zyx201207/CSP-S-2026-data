#include<bits/stdc++.h>
#define ll long long
#define maxn 500005
#define INFint (int)(1e9 + 5)
#define INFll (long long)(1e18 + 5)
#define ull unsigned long long
using namespace std;

int n;
ll m;
ll a[maxn],qzh[maxn];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++ i){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;++ i){
		qzh[i] = qzh[i - 1] + a[i];
	}
	ll ans = 1;
	for(int i = 2;i <= n;++ i){
		ll l = 1,r = i,nw = i;
		while(l <= r){
			ll mid = (l + r) >> 1;
			ll nd = (i - mid + 1) * a[i] - (qzh[i] - qzh[mid - 1]);
			if(nd <= m) r = mid - 1,nw = mid;
			else l = mid + 1;
		}
		ans = max(ans,i - nw + 1);
	}
	cout << ans << "\n";
	
	return 0;
}

