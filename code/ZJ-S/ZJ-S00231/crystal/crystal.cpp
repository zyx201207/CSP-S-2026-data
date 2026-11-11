#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,k;
		while(l<=r){
			mid=(l+r)/2;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])>m) l=mid+1;
			else{
				k=mid;
				r=mid-1;
			}
		}
		ans=max(ans,i-k+1);
	}
	cout<<ans;
	return 0;
}
