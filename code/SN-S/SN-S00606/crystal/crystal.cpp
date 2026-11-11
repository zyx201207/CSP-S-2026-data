#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int nowp=0,nown=1,ans=1;
	for(int i=2;i<=n;i++){
		nowp+=nown*(a[i]-a[i-1]);
		while(nowp>m) nowp-=a[i]-a[i-(nown--)];
		nown++,ans=max(ans,nown);
	}
	cout<<ans;
	return 0;
}
