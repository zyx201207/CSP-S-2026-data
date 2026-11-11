#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[500010];
int f[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,k=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-f[i]+f[mid-1]<=m){
				r=mid-1;
				k=mid;
			}else l=mid+1;
		}
		ans=max(ans,i-k+1);
	}
	cout<<ans;
	return 0;
}