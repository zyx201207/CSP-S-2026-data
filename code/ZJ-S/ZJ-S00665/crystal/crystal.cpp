#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,sum,ans,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ans=1;
	for(int i=2,j=1;i<=n;i++){
		sum+=(i-j)*(a[i]-a[i-1]);
		while(j+1<=i&&sum>m) sum-=(a[i]-a[j]),j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}