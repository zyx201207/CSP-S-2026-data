#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m;
ll a[N],sum[N],cnt[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum[1]=0,cnt[1]=1;
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
		cnt[i]=i;
		if(sum[i]<=m)continue;
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			ll s=sum[mid]+mid*(a[i]-a[mid]);
			if(sum[i]-s<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		cnt[i]-=r;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,cnt[i]);
	cout<<ans<<"\n";
	return 0;
}