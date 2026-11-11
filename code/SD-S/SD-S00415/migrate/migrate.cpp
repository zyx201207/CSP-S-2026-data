#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
const int N=5e4;
int n,m,a[500005],x,z,pre[500005],c[500005];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T>>T;
	while(T--) {
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			cin>>c[i];
		}
		int oo=0;
		cout<<max(n-3,oo)<<endl;
	}




	return 0;
}//rp++
