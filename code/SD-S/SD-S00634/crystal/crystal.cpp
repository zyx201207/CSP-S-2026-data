#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int a[M];
long long sum[M];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,ans=0;long long m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=l+r>>1;
			long long x=1ll*a[i]*(i-mid+1)-(sum[i]-sum[mid-1]);
			if(x<=m)r=mid-1;
			else l=mid+1;
		}ans=max(ans,i-l+1);
	}cout<<ans<<"\n";
	return 0;
}
