#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[500010],sum[500010];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n,now=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[mid]*(mid-i+1)-sum[mid]+sum[i-1]<=m){
				l=mid+1;
				now=mid;
			}
			else r=mid-1;
		}
		ans=max(ans,now-i+1);
	}
	cout<<ans;
}
