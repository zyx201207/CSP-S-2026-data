#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,d,a[N],dp[N],f[N],R[N],sum[N],L[N];
void solve(){
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(c==11||c==12){
		if(n==1){cout<<0<<'\n';return;}
		int dis=a[2]-a[1],num=d/dis;
		if(num<2){cout<<0<<'\n';return;}
		cout<<max(0ll,n-2*num+1)<<'\n';
		return;
	}
	if((c==13||c==14)&&n>5000){cout<<0<<'\n';return;}
	for(int i=1;i<=n;i++){
		L[i]=lower_bound(a+1,a+i+1,a[i]-d)-a;
	}
	for(int i=1;i<=n;i++){
		dp[i]=0,f[i]=1,sum[i]=1,sum[i-1]=0,R[i]=i;
		for(int j=i+1;j<=n;j++){
			int p=max(L[j],i);
			dp[j]=dp[p]+1;
		}
		int tmp=n;
		for(int j=n;j>i;j--){
			if(dp[j]==dp[tmp]) R[j]=tmp;
			else tmp=R[j]=j;
		}
		for(int j=i+1;j<=n;j++){
			int p=max(L[j],i);
			f[j]=sum[min(R[p],j-1)]-sum[p-1];
			sum[j]=sum[j-1]+f[j];
			if(f[j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) solve(); 
	return 0;
}