#include <bits/stdc++.h>
#define ll1 long long
using namespace std;

int n,a[200005],ll[200005],rr[200005],curl,curr,ans;
vector<pair<pair<int,int>,char> > v;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		char ch;
		cin >> a[i] >> ch;
		int l = a[i - 1] + 1,r = a[i];
		v.push_back({{l,r},ch});
		ll[++curl] = l;
		rr[++curr] = r;
	}
	for (pair<pair<int,int>,int> i : v) {
		int l = i.first.first,r = i.first.second;
		char ch = i.second;
		int tl = n - r + 1,tr = n - l + 1;
		if (tr < tl) swap(tl,tr);
		for (int j = 1;j <= curl;j++) {
			char ch1 = v[j].second;
			if (tl <= ll[j] && ll[j] <= tr && tr <= rr[j]) {
				if (ch != ch1) ans += tr - ll[j] + 1;
				break;
			}
			if (ll[j] <= tl && tl <= rr[j] && rr[j] <= tr)
				if (ch != ch1) ans += rr[j] - tl + 1;
			if (ll[j] <= tl && tl <= rr[j] && 
					ll[j] <= tr && tr <= rr[j]) {
				if (ch != ch1) ans += tr - tl + 1;
				break;
			}
			if (tl <= ll[j] && rr[j] <= tr)
				if (ch != ch1) ans += rr[j] - ll[j] + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
