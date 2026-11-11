#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=1e12;
int a[N],sum[N];
int cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			//cout<<l<<" "<<r<<" "<<mid<<" "<<(i-mid+1)*a[i]-sum[i]+sum[mid-1]<<"\n";
			if((i-mid+1)*a[i]-sum[i]+sum[mid-1]<=m){
				ans=mid,r=mid-1;
			}
			else l=mid+1;
		}
		//cout<<ans<<"\n";
		maxx=max(maxx,i-ans+1);
	}
	cout<<maxx;
	return 0;
}
