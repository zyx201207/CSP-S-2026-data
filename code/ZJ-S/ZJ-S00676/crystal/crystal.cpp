#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,ans;
ll a[N],m,sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,now=i;
		while(l<=r){
			mid=l+r>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				r=mid-1;
				now=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,i-now+1);
	}
	cout<<ans<<'\n';
	return 0;
}