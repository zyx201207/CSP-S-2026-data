#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=1;
int a[500005];
int sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n,now=1;
		//cout<<i<<":"<<"\n";
		while(l<=r){
			int mid=(l+r)/2;
			//cout<<mid<<" "<<(mid-i)*a[mid]-(sum[mid-1]-sum[i-1])<<"\n";
			if(mid<=n&&(mid-i)*a[mid]-(sum[mid-1]-sum[i-1])<=m){
				l=mid+1;
				now=mid;
			}
			else{
				r=mid-1;
			}
		}
		//cout<<"now:"<<now<<"\n";
		ans=max(ans,now-i+1);
	}
	cout<<ans;
}
