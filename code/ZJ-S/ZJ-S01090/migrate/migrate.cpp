#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin >> c >> t;
	while (t--){
		int n;
		ll d;
		cin >> n >> d;
		vector<ll> a(n+1);
		for (int i = 1;i <= n;++i){
			cin >> a[i];
		}
		vector<pair<int,int> > v;
		for (int i = 1;i <= n;++i){
			int l = upper_bound(a.begin()+i,a.end(),a[i]+d)-a.begin()-1;
			v.push_back({i,l});
		}
		vector<pair<int,int> > v2;
		int ans = 0;
		for (int i = 1;i < v.size();++i){
			int l1 = v[i-1].first,r1 = v[i-1].second;
			int l = v[i].first,r = v[i].second;
			if (r1-l == 1&& r1 < r) ++ans;
		}
		cout << ans-1 << '\n';
	}
	return 0;
}
