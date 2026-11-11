#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005];
bool judge(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*(x-1)-(sum[i-1]-sum[i-x])<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(judge(mid)==true) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
