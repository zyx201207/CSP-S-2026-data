#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n,m,a[N],res[N];
//priority_queue unordered_map
//lower_bound upper_bound
map<int,int>mp;
void solve() {
	cin>>n>>m;
	if(m==2) {
		int l,r;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<=n; i++) {
			if(a[i]!=a[n]) {
				l++;
				r++;
			} else {
				if(a[i]==1) {
					l++;
				} else {
					r++;
				}
			}
		}
		cout<<l<<" "<<r;
		return;
	}
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n<=500) {
		for(int i=1; i<=m; i++) {
			mp.insert({i,0});
		}
		for(int i=1; i<=n; i++) {
			vector<int>v;
			for(int j=i; j<=n; j++) {
				if(v.size()) {
					bool f=1;
					for(auto it:v) {
						if(it==a[j]) {
							f=0;
						}
						if(!f) {
							v.pop_back();
						}
					}
				}
				v.push_back(a[j]);
			}
			for(auto it:v) {
				mp[it]++;
			}
		}
		for(int i=1; i<=m; i++) {
			cout<<mp[i]<<" ";
		}
	}
	for(int i=1; i<=m; i++) {
		mp.insert({i,0});
	}
	for(int i=1; i<=n; i++) {
		mp[a[i]]=i;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(mp[j]>=i) {
				res[j]++;
			}
		}
	}
	for(int j=1; j<=m; j++) {
		cout<<res[j]<<" ";
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int _ = 1;
//	cin>>_;
	while(_--) {
		solve();
	}
	return 0;
}
