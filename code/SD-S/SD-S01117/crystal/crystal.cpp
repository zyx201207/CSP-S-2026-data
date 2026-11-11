#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],sum[500005];
int get(int l,int r){
	int tp=sum[r]-sum[l-1];
	return a[r]*(r-l+1)-tp;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(get(mid,i)<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,(i-l+1));
	}
	cout<<ans;
	return 0;
}
