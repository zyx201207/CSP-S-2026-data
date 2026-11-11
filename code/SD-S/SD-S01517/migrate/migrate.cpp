#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
ll c,t,n,d,a[N],ans,zd[N],k,dp[N][N],maxx;
map<ll,ll> mp;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++) scanf("%lld",&a[i]),mp[a[i]]=i;
		ll m=1,g=1;
		while(m<=n){
			ans=0;
			while(m<n&&a[m+1]-a[m]<=d) m++;
			for(int i=g;i<=m-2;i++){
				k=i,zd[i]=0;
				for(int j=i+1;j<=m;j++){
					if(a[j]-a[k]<=d) zd[j]=zd[k]+1;
					else k=j-1,zd[j]=zd[k]+1;
				}
				dp[i][i]=1;
				for(int j=i+1;j<=m;j++){
					for(int q=a[j]-d;q<=a[j]-1;q++){
						if(mp.count(q)&&zd[mp[q]]+1<=zd[j]) dp[i][j]+=dp[i][mp[q]];
					}
					if(dp[i][j]==2) ans++;
				}
			}
			g=m,m++;
			maxx=max(maxx,ans);
		}
		printf("%lld\n",maxx);
	}
	return 0;
}
