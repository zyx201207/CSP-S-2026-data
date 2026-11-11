#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,inf=1e18;
int a[N],sum[N],c[N];
int n,m;
bool check(int x){
	int ans=inf;
	for(int i=1;i+x-1<=n;i++){
		ans=min(ans,x*a[i+x-1]-sum[i+x-1]+sum[i-1]);
	}
	return ans<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;		
	}
	cout<<l;
	return 0;
}