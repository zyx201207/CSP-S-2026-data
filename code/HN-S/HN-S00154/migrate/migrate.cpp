#include<bits/stdc++.h>
#define rep(i,a,b) for(long long i=(a);i<=(b);++i)
#define debug(a) cout<<#a<<"="<<a<<"\n";
using namespace std;
const long long N=2e6+7;
long long n,m,a[N],b[N],dp[N][2],f[N][2],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int id,T;
	scanf("%d%d",&id,&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		rep(i,1,n){
			b[i]=0;
			rep(j,0,1) dp[i][j]=f[i][j]=0;
		}
		ans=0;
		rep(i,1,n){
			scanf("%lld",&a[i]);
		}
		int l=1;
		rep(i,1,n){
			while(l<i&&abs(a[i]-a[l])>m) l++;
			f[i][0]=l;
		}
		l=n;
		for(int i=n;i>=1;i--){
			while(l>i&&abs(a[i]-a[l])>m) l--;
			f[i][1]=l;
		}
		rep(i,1,n){
			dp[i][0]++;
			if(f[i][1]!=i){
				if(f[i-1][1]==f[i][1]) dp[f[i][1]][0]++;
				else b[f[i][1]]=i,dp[f[i][1]][0]+=dp[i][0];
			}
		}
		for(int i=n;i>=1;i--){
			if(f[i][1]==i||f[i-1][1]==f[i][1]){
				dp[i][1]=1;
				continue;
			}
			dp[i][1]=dp[f[i][1]][1]+(f[i][1]-i)-(f[i-1][1]-i);
		}
		rep(i,1,n){
//			cout<<dp[i][0]<<" "<<dp[i][1]<<"/"<<f[i][0]<<" "<<f[i][1]<<"\n";
			if(i-f[i][0]<=1) continue;
			long long x=1;
//			debug(f[i][0]+1)
//			debug(b[f[i][0]+1])
			if(f[b[f[i][0]+1]-1][1]==f[i][0]) x=dp[b[f[i][0]+1]][0];
			if(f[f[i][0]+1][1]==i) ans+=(dp[f[i][0]+1][0]-x)*dp[i][1];
			else ans+=dp[f[i][0]+1][0]-x;
//			debug(ans)
		}
		printf("%lld\n",ans);
	}
    return 0;
}
