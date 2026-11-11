#include<bits/stdc++.h>
#define il inline 
#define ll long long
using namespace std;
#define rep(x,l,r) for(int x=l;x<=r;++x)
#define per(x,l,r) for(int x=l;x>=r;--x)
il ll read(){
	ll f=1,k=0; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){k=(k<<1)+(k<<3)+(c^48);c=getchar();}return f*k;
}
const int N=2e6+10;
int c,T,n,dp[N],g[N],cnt;
ll a[N],x[N],d;
il int num(int l,int r){
	cnt=0;
	rep(i,l,r) a[++cnt]=x[i];
	rep(i,1,cnt){
		dp[i]=1e9;
		g[i]=0;
	}
	g[1]=1;
	dp[1]=0;
	rep(i,2,cnt){
		rep(j,1,i-1){
			if(abs(a[i]-a[j])>d) continue;
			if(dp[i]>dp[j]+1){
				dp[i]=dp[j]+1;
				g[i]=g[j];
			}
			else if(dp[i]==dp[j]+1){
				g[i]+=g[j];
			}
		}
	}
	if(g[cnt]==2) return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		rep(i,1,n){
			x[i]=read();
		}
		ll ans=0;
		rep(i,1,n){
			rep(j,i+1,n){
				ans+=num(i,j);
			}
		}
		printf("%lld\n",ans);
	}
	
	
	
	
	
	return 0;
}

