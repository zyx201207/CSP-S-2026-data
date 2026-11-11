#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	while (t--){
		int n,k;
		cin >> n >> k;
		for (int i=1;i<=n-1;i++) {
			int u,v;
			cin >> u >> v;
		}
		cout << (n/2-k)/10<< '\n';
	}
	return 0;
}

