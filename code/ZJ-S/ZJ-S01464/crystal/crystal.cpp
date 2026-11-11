#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],sum[N],n,m,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(l<r){
			int j=(l+r)>>1;
			if(sum[i]-sum[j]>=(i-j)*a[i]-m)r=j;
			else l=j+1;
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
}