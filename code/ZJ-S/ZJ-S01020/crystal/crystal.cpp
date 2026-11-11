#include<bits/stdc++.h>
#define int long long
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	FIO
	int n,m,i,maxn,ans;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	maxn=ans=0;
	int l=1,r=1;
	while(l<=r&&r<=n){
		if(ans<=m) maxn=max(maxn,r-l+1);
		if(ans<=m) r++,ans+=(r-l)*(a[r]-a[r-1]);
		else ans-=a[r]-a[l],l++;
	}
	cout<<maxn;
	return 0;
}