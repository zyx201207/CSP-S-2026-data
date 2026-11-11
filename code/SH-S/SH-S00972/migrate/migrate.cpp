#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll CASE,T,n,maxd;
const ll N=2e6+10;
ll a[N],dst[N];
ll feas[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>CASE>>T;
	if (CASE==11 || CASE==12) {
		while (T--) {
			cin>>n>>maxd;
			ll tmpx,tmpy;
			for (ll i=1;i<n;++i) {
				cin>>tmpx;
			}
			cin>>tmpy;
			ll delta=abs(tmpy-tmpx);
			ll val=maxd/delta;
			if (val==0) {
				cout<<0<<"\n";
			} else if (val==1) {
				cout<<0<<"\n";
			} else {
				if (n+1-2*val>0) {
					cout<<n+1-2*val<<"\n";
				} else {
					cout<<0<<"\n";
				}
			}
		}
		return 0;
	}
//	if (CASE<=6) {
		while (T--) {
			ll ans=0;
			cin>>n>>maxd;
			for (ll i=1;i<=n;++i) {
				cin>>a[i];
			}
			for (ll i=1;i<=n;++i) {
				for (ll j=1;j<=n;++j) {
					feas[j]=0;
				}
				ll cnt=0;
				dst[i]=0;
				ll ST=i;
				set<ll> ids;
				vector<ll> ers;
				while (ST<n) {
					//最后一个满足a[j]<=a[ST]+maxd的元素
					ll ED=upper_bound(a+1,a+n+1,a[ST]+maxd)-a-1;
					ers.push_back(ED);
					ids.insert(ED-1);
					ids.insert(ED-2);
					if (ids.count(ST)) {
						ids.erase(ST);
					}
					++cnt;
					for (ll j=ST+1;j<=ED;++j) {
						dst[j]=cnt;
						++feas[j];
					}
					if (ST==ED) {
						break;
					}
					ST=ED;
				}
				for (ll v:ers) {
					if (ids.count(v)) {
						ids.erase(v);
					}
				}
				if (ids.count(ST)) {
					ids.erase(ST);
				}
				for (ll star:ids) {
					if (star<=i) {
						continue;
					}
					ll ST=star;
					cnt=dst[ST];
					while (ST<n) {
						ll ED=upper_bound(a+1,a+n+1,a[ST]+maxd)-a-1;
						++cnt;
						for (ll j=ST+1;j<=ED;++j) {
							if (dst[j]==cnt) {
								++feas[j];
							}
						}
						if (ST==ED) {
							break;
						}
						ST=ED;
					}
				}
				for (ll j=i+1;j<=n;++j) {
					if (feas[j]==2) {
						++ans;
					}
				}
			}
			cout<<ans<<"\n"; 
		}
//	}
	return 0;
}

