#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
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
	int ans=0;
	for(int i=n;i>=1;i--){
		int l=0,r=i+1;
		while(l+1<r){
			int mid=(l+r)>>1;
			int u=a[i]*mid-sum[i]+sum[i-mid];
		//	cout<<i<<' '<<u<<" "<<mid<<endl;
			if(u<=m){
				l=mid;
			}else{
				r=mid;
			}
		}
		ans=max(ans,l);
	}
	cout<<ans<<endl;
}
//Oct31==Dec25?
//a[i]-a[i-1]+a[i]-a[i-2]
