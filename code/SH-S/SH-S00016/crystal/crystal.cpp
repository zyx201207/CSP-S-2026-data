#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[500010],p[500010],n,m;
int check(int k){
	for(int i=k;i<=n;i++)if(a[i]*k-(p[i]-p[i-k])<=m)return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	int l=0,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
} 
