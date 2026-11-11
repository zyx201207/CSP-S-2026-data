#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k,u,l,r,i,j,x,v,a[1005],dp[1005][1005],ans,fa[1005];
bool f[1005][1005];
vector<ll> b[1005];
ll read() {
	ll k=0;
	ll f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') {
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
void write(ll x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x<10) {
		putchar(x+'0');
	} else {
		write(x/10);
		putchar(x%10+'0');
	}
}
ll find(ll x) {
	if(fa[x]==x) {
		return x;
	}
	return fa[x]=find(fa[x]);
}
void unite(ll x,ll y) {
	l=find(x);
	r=find(y);
	fa[l]=r;
	return ;
}
bool same(ll x,ll y) {
	if(find(x)==find(y)) {
		return 1;
	}
	return 0;
}
void fout() {
	ll cnt=k;
	for(ll i=1; i<=k; i++) {
		for(ll j=1; j<=k; j++) {
			if(i!=j) {
				if(f[i][j]==1) {
					if(same(i,j)==0) {
						unite(i,j);
						cnt--;
					}
				}
			}
		}
	}
	if(cnt>2) {
		return ;
	} else {
		ll sum=LLONG_MAX;
		for(ll i=1; i<=n; i++) {
			for(ll j=1; j<=n; j++) {
				sum=max(sum,dp[i][j]);
			}
		}
		ans=min(sum,ans);
	}
	return ;
}
void dfs(ll x,ll s) {
	if(s==k) {
		for(ll i=1;i<=n;i++){
			fa[i]=i;
		}
		return ;
	}
	for(ll i=x+1; i<=n; i++) {
		a[s+1]=i;
		dfs(i,s+1);
	}
	return ;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	t=read();
	while(t--) {
		n=read();
		k=read();
		for(i=1; i<=n; i++) {
			for(j=1; j<=n; j++) {
				f[i][j]=0;
			}
		}
		for(i=1; i<=n-1; i++) {
			u=read();
			v=read();
			f[u][v]=1;
			f[v][u]=1;
			dp[u][v]=1;
			dp[v][u]=1;
			b[u].push_back(v);
			b[v].push_back(u);
		}
		for(k=1; k<=n; k++) {
			for(i=1; i<=n; i++) {
				for(j=1; j<=n; j++) {
					if(f[i][k]==1&&f[j][k]==1) {
						x=dp[i][k]+dp[k][j]+1;
						dp[i][j]=min(dp[i][j],x);
					}
				}
			}
		}
		ans=LLONG_MAX;
		dfs(0,0);
		write(ans);
		putchar('\n');
	}
	return 0;
}