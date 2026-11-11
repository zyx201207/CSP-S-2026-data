#include<bits/stdc++.h>
using namespace std;
int n,l,r,mid,ans,maxx;
long long m,a[500001],sum[500001];
int main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		l=0,r=i-1;
		while(l<=r){
			mid=l+r>>1;
			if((i-mid)*a[i]-sum[i]+sum[mid]<=m)ans=mid,r=mid-1;
			else l=mid+1;
		}
		maxx=max(maxx,i-ans);
	}
	cout<<maxx;
	return 0;
}
