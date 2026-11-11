#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+5;
int c, t, u[N], v[N], n, k;
bool ok[N];

signed main ()
{
	 freopen("hub.in","r",stdin);
	 freopen("hub.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while (t--) {
		cin>>n>>k;
		cout<<k-1<<'\n';
	}

	return 0;
}
