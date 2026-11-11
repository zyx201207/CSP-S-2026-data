#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],ans=1;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,sum=0;
	for (int r=2; r<=n; r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while (sum>m) sum-=a[r]-a[l++];
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}