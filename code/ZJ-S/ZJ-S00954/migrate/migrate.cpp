#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define lINF 0x3f3f3f3f3f3f3f3f
using namespace std;
void read(ll &x){
	ll f=1;x=0;char s=getchar();
	while(s<'0'||s>'9'){if (s=='-'){f=-f;}s=getchar();}
	while (s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	x*=f;
}
ll c,T,n,d;
const ll N=2e6+5;
ll a[N];
ll dp[305][305],cnt[305][305];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c);read(T);
	while (T--){
		read(n);read(d);
		if (c<=6){
			memset(dp,INF,sizeof(dp));
			memset(cnt,0,sizeof(cnt));
			for (ll i=1;i<=n;i++){
				read(a[i]);
				if (i>1) a[i]=a[i]-a[1];		
				dp[i][i]=0;
				cnt[i][i]=1;
			}
			a[1]=0;
			for (ll i=1;i<=n;i++){
				ll j=i+1; 
				while (j<=n && a[j]-a[i]<=d){
					for (ll k=1;k<=i;k++){
						ll v=dp[k][i]+1;
						if (v<dp[k][j]){
							dp[k][j]=v;
							cnt[k][j]=0;
						}
						if (v==dp[k][j]) cnt[k][j]+=cnt[k][i];
					}
					j++;
				}
			}
			ll ans=0;
			for (ll i=1;i<=n;i++){
				for (ll j=i+1;j<=n;j++){
					if (cnt[i][j]==2) ans++;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}

