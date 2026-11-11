#include<bits/stdc++.h>
using namespace std;
#define ing long long
const int N=5e5+7;
int n,m,a[N],b[N],c[N],d[N],ans=1;
int sum(int i,int j){
	return (j-i+1)*c[j]-(d[j]-d[i-1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i){
		b[i]=a[i+1]-a[i];
		c[i]=b[i]+c[i-1];
		d[i+1]=c[i]+d[i];
		if(b[i]<=m){
			ans=2;
		}
	}
	for(int i=1;i<n;++i){
		int l=i+1,r=n-1,mid;
		while(l<r){
			mid=(l+r)/2;
			if(sum(i,mid)<=m){
				l=mid+1;
			}
			else{
				r=mid;
			}
		}
		ans=max(ans,r-i+1);
	}
	cout<<ans;
	return 0;
}
