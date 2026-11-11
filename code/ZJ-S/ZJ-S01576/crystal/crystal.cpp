#include<bits/stdc++.h>
#define int long long
using namespace std;
long long a[500005],pre[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//------------------------------------------------
	long long n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	long long l=2,r=n,ans=1;
	while(l<=r){
		long long mid=(l+r)/2;
		bool f=false;
		for(long long i=mid;i<=n;i++){
			if(a[i]*mid-(pre[i]-pre[i-mid])<=m){
				ans=max(ans,mid);
				f=true;break;}}
		if(f==true) l=mid+1;
		else r=mid-1;}
	cout<<ans;
	//------------------------------------------------
	fclose(stdout);fclose(stdin);
	return 0;}