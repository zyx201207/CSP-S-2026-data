#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+10;
const int M=1e5+10;
struct node{
	ll a,t;
}df[N][N];
ll c,n,m,d,q,w[N],k[N],a[N][N],t[N][N],x[M],y[M],dp[N][N],cnt,sumn[M];
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(ll i=1;i<=m;i++){
		w[i]=read();
	}
	for(ll i=1;i<=n;i++){
		k[i]=read();
		for(ll j=1;j<=k[i];j++){
			df[i][j].a=read();
			df[i][j].t=read();
		}
	}
	memset(dp,0x3f,sizeof(dp));
	cnt=m*2+n;
	for(ll i=1;i<=cnt;i++){
		dp[i][i]=0;
	}
	for(ll i=1;i<=m;i++){
		dp[i][i+m]=min(dp[i][i+m],w[i]);
		dp[i+m][i]=min(dp[i+m][i],w[i]);
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=k[i];j++){
			dp[m*2+i][df[i][j].a+m]=min(dp[m*2+i][df[i][j].a+m],df[i][j].t);
			dp[df[i][j].a+m][m*2+i]=min(dp[df[i][j].a+m][m*2+i],df[i][j].t);
		}
	}
	for(ll kx=1;kx<=cnt;kx++){
		for(ll i=1;i<=cnt;i++){
			for(ll j=1;j<=cnt;j++){
				if(kx==i||i==j||kx==j)
					continue;
				dp[i][j]=min(dp[i][j],dp[i][kx]+dp[kx][j]);
			}
		}
	}
	for(ll i=1;i<=q;i++){
		x[i]=read();y[i]=read();
		sumn[i]=dp[x[i]][y[i]];
	}
	for(ll i=1;i<=q;i++){
		cout<<sumn[i]<<"\n";
	}
	return 0;
}
