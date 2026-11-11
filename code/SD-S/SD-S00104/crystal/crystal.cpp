#include <iostream>
#include <cstdio>
#include <algorithm>
#define lnl long long
using namespace std;
int n,ans=1;
lnl a[500005],m,f[500005];
int check(int l,int r,lnl val){
	int mid,res=0,R=r;
	while(l<=r){
		mid=(l+r)/2;
		if(1ll*val*(R-mid+1)-(f[R]-f[mid-1])<=m){
			res=R-mid+1;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	for(i=1;i<=n;i++){
		j=check(1,i-1,a[i]);
		ans=max(ans,j+1);
		//cout<<"ans["<<i<<"]="<<j+1<<"\n";
	}
	cout<<ans;
	return 0;
}
