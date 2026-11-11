#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],sum[500005],f[500005];
int calc(int l,int r){return a[r]*(r-l+1)-(sum[r]-sum[l-1]);}
int ask(int pos){
	int l=1,r=pos,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		int res=calc(mid,pos);
		if(res<=m)ans=max(ans,pos-mid+1),r=mid-1;
		else l=mid+1;
	}
	return ans;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)f[i]=max(f[i-1],ask(i));
	cout<<f[n];
	return 0;
}