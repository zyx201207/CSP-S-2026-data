#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int maxn=5e5+10;
int a[maxn];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,ans=1,cost=0;
	for(int r=2;r<=n;r++) {
		cost+=(r-l)*(a[r]-a[r-1]);
		while(cost>m) {
			cost-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
