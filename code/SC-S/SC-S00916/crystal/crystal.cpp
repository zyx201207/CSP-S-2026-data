#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],sum[N];
int query(int l,int r){
	return sum[r]-sum[l-1];
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-1-mid+1)-query(mid,i-1)<=m)
				res=max(res,i-1-mid+1),r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,res+1);
	}
	cout<<ans;
	return 0;
}