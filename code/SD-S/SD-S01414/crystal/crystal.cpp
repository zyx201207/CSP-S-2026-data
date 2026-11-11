#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],sum[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int mx=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,best=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(mid*a[i]-(sum[i]-sum[i-mid])<=m){
				l=mid+1;
				best=mid;
			}else{
				r=mid-1;
			}
		}
		mx=max(mx,best);
	}
	cout<<mx<<"\n";
	return 0;
} 
//×¢Òâ·¶Î§ ×¢Òâ±ß½ç 
