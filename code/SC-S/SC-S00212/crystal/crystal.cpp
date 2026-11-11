#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;n>=i;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;n>=i;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;n>=i;i++){
		int l=1,r=i,mid,gl=0;
		while(l<=r){
			mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])>m)
				l=mid+1;
			else{
				 r=mid-1;
				gl=mid; 
			}
		}
		ans=max(ans,1+i-gl);
	}
	cout<<ans;
	return 0;
}