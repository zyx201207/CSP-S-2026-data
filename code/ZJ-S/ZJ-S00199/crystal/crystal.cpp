#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,sum,l,r,ans=-2e18,a[500010];
bool cmp(int q,int h){return q>h;}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(l=1;l<=n;l++){
		while(sum+a[l]-a[r+1]<=m&&r<n) r++,sum+=a[l]-a[r];
		if(l<=r) sum-=(a[l]-a[l+1])*(r-l);
		else r=l,sum=0;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}