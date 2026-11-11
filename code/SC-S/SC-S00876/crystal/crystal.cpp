#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
int n,ans;ll m,a[N],sum[N];
int geta(int id){
	int l=1,r=id-1;
	while(l<r){
		int mid=l+r>>1;
		if((id-mid)*a[id]-(sum[id-1]-sum[mid-1])>m)l=mid+1;
		else r=mid;
	}return id-l+1;
}int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);for(int i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)ans=max(geta(i),ans);
	cout<<ans<<endl;
	return 0;
}