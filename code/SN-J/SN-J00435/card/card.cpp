#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m,n;
vector<ll> a, cnt;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	a.resize(n);
	cnt.resize(m+1); 
	for (ll i=0;i<n;i++) {
		cin >> a[i];
	}
	
	for (ll i=0;i<n;i++) {
		ll end=0;
		vector<pair<bool,ll> > vis(m+1);
		for (ll j=i;j<n;j++) {
			if (vis[a[j]].first) {
				end = vis[a[j]].second;
				for (ll k=1;k<=m;k++) {
					if (vis[k].first && vis[k].second > end) vis[k].first = false; 
				}
			} else {
				vis[a[j]].first=true;
				end++;
			}
			vis[a[j]].second=end;
		}
		for (ll j=1;j<=m;j++) {
			cnt[j] += vis[j].first;
		}
	}
	
	for (ll i=1;i<=m;i++) {
		cout << cnt[i] << (i==m ? "\n" : " ");
	}
	
	return 0;
}


