#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans,ans1;
bool check(int x){
	int fei=0;
	for(int i=1;i<x;i++){
		fei+=(a[x]-a[i]);
	}
	if(fei<=m)return 1;
	for(int i=1;i<=n-x;i++){
		fei=fei-(a[x+i-1]-a[i])+(x-1)*(a[x+i]-a[x+i-1]);
		if(fei<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
//	for(int i=2;i<=n;i++)cout<<f[i]<<" ";
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
