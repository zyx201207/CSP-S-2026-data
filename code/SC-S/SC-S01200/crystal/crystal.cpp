#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);int last=0;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		while(a[i]*(i-last)-sum[i]+sum[last]>m) last++;
		ans=max(ans,i-last);
	}
	cout<<ans;
	return 0;
}
