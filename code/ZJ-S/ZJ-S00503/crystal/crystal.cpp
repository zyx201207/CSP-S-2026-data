#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],c[500005],d[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) c[i]=a[i+1]-a[i];
	for(int i=n-1;i>=1;i--) c[i]+=c[i+1],d[i]=c[i];
	for(int i=n-1;i>=1;i--) d[i]+=d[i+1];
	int ans=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,mid,res=1e10;
		while(l<=r){
			mid=l+r>>1;
			if(d[mid]-d[i]<=(i-mid)*c[i]+m) r=mid-1,res=mid;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<"\n";
	return 0;
}
//1 2 4 1
//8 7 5 1
