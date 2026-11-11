#include<bits/stdc++.h>
#define ll long long
#define ac read()
#define M 500005
using namespace std;
inline ll read() {
	ll x=0,f=1;
	int c=getchar();
	while(!isdigit(c)) {
		f=(c=='-')?-1:1;
		c=getchar();
	}
	while(isdigit(c)) {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
ll c,n,m,d,q;
ll w[M];
ll sub[M][23],s[M];
ll way[M][23];
ll Dt[555][555];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=ac,n=ac,m=ac,d=ac,q=ac;
	for(int i=1; i<=m; ++i) {
		w[i]=ac;
	}
	ll u=0,v=0,t=0;
	for(int i=1; i<=n; ++i) {
		int k=ac;
		for(int j=1; j<=k; ++j) {
			u=ac,t=ac;
			sub[u][++s[u]]=i;
			way[u][s[u]]=t;
		}
	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			Dt[i][j]=1e18;
		}
	}
	for(int i=1; i<=m; ++i) {
		for(int j=1; j<=s[i]; ++j) {
			for(int k=1; k<=s[i]; ++k) {
				if(j==k) continue;
				u=sub[i][j],v=sub[i][k];
				Dt[u][v]=min(Dt[u][v],way[i][j]+way[i][k]);
			}
		}
	}
	for(int k=1; k<=n; ++k) {
		for(int i=1; i<=n; ++i) {
			if(i==k) continue;
			for(int j=1; j<=n; ++j) {
				if((j==i)||(j==k)) continue;
				Dt[i][j]=min(Dt[i][j],Dt[i][k]+Dt[j][k]);
			}
		}
	}
	ll a=0,b=0;
	for(int i=1; i<=q; ++i) {
		a=ac,b=ac;
		ll ans=1e18;
		for(int j=1; j<=s[a]; ++j) {
			for(int k=1; k<=s[b]; ++k) {
				u=sub[a][j],v=sub[b][k];
				ll sum=way[a][j]+way[b][k];
				if(u==v) {
					ans=min(ans,sum);
				} else {
					ans=min(ans,sum+Dt[u][v]);
				}
			}
		}
		cout<<ans+w[a]+w[b]<<"\n";
	}
	return 0;
}
