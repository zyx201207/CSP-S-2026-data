#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500001];
long long sum[500001];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>0;--i){
		int l=0,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(sum[i]-sum[mid-1]+m>=a[i]*(i-mid+1)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
