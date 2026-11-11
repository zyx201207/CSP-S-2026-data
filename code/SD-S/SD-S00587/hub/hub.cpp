#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > z;
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c == 0) cout << 0;
	else {
		while(t --) {
			int n,k;
			cin >> n >> k;
			int u,v;
			cin >> u >> v;
			if(k == 2) {
				cout << min(u,v) << '\n';
			}
			
			if(k == 1) cout << 0 << '\n';
		}
	}
	return 0;
}

