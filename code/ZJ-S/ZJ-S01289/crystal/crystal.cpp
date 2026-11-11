#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],f[500010],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(f[i]-f[mid-1])<=m){
				ans=max(ans,(i-mid+1));
				r=mid-1;
			}else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
