#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=3e6+5;
ll c,t;
ll n,d;
ll x[N];
ll dp[5005][5005];
ll f[5005][5005];

inline ll read(){
	ll f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}

void solve(){
	ll ans=0;
	vector<vector<ll>> dp(n+5,vector<ll>(n+5,0x3f3f3f3f3f));
	vector<vector<ll>> f(n+5,vector<ll>(n+5,1));
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d)dp[i][j]=dp[j][i]=1;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i][j]>dp[i][k]+dp[k][j]){
					dp[i][j]=dp[i][k]+dp[k][j];
					f[i][j]=f[i][k]*f[k][j];
				}else if(dp[i][j]==dp[i][k]+dp[k][j]){
					f[i][j]+=f[i][k]*f[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[i][j]==2)++ans;
		}
	}
	printf("%lld\n",ans);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		solve();
	}
	return 0;
}
