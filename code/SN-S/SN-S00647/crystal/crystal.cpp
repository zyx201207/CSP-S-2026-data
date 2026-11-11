#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],sum[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int now=-1;
		for(int j=(1<<20);j;j>>=1){
			if(now+j<i&&(i-now-j)*a[i]-(sum[i]-sum[now+j])>m)now+=j;
		}
		ans=max(ans,i-now-1);
	}
	cout<<ans<<"\n";
	return 0;
}
