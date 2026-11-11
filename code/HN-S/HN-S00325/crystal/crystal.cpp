#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int n,m,a[N],sum[N],ans=0;
bool check(int l,int r,int x){
	int total=sum[r]-sum[l-1],zh=(r-l+1)*x;
	return (zh-total)<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n;i++){
		int l=1,r=i,st;	
		while(l<=r){
			int mid=(l+r)>>1;
			if (check(mid,i,a[i])){
				st=mid;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-st+1);
	}
	cout<<ans;
	return 0;
}
