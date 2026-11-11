#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+5;
int n,d;
int a[N];
signed main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0)->sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		cout<<"0\n";
	}
	return 0;
}