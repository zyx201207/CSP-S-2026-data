#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m,a[2000006],re[2000006],vis=1,cnt[2000006],sum[2000006];
void miin(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for (int i=1;i<=n;i++){
		vis=i;
		for (int j=1;j<=n;j++){
			re[j]=1e16;
			cnt[j]=0;
		}sum[vis]=1;sum[vis-1]=0;
		re[vis]=0;cnt[vis]=1;int l,r,mid,lst,ed;
		for (int j=vis+1;j<=n;j++){
			lst=lower_bound(a+vis,a+n+1,a[j]-m)-a;ed=0;
			l=lst;r=j-1;re[j]=re[lst]+1;
			while (l<=r){
				mid=(l+r)>>1;
				if (re[mid]==re[lst]){
					ed=max(ed,mid);
					l=mid+1;
				}else r=mid-1;
			}cnt[j]=sum[ed]-sum[lst-1];
			sum[j]=sum[j-1]+cnt[j];
		}
		for (int j=1;j<=n;j++){
			if (cnt[j]==2)ans++;
		}
	}cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T,c;
	cin>>c>>T;
	while (T--){
		miin();
	}
}
