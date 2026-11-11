#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000000
using namespace std;
ll c,n,m,d,q,dp[510][510],w[500010],k,a,t,xr,yr,ans;
vector <pair<ll,ll> > e[500010];
template <typename type>
inline void read(type &x) {
	x=0;bool flag(0);char ch=getchar();
	while(!isdigit(ch)) flag=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	flag?x=-x:0;
	return;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);
	read(n);
	read(m);
	read(d);
	read(q);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(i!=j) dp[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++) {
		read(w[i]);
	}
	for(int i=1;i<=n;i++) {
		read(k);
		for(int j=1;j<=k;j++) {
			read(a),read(t);
			e[a].emplace_back(i,t);
		}
	}
	int tx,ty;
	for(int i=1;i<=m;i++) {
		for(int j=0;j<e[i].size();j++) {
			tx=e[i][j].first,ty=e[i][j].second;
			for(int g=j+1;g<e[i].size();g++) {
				dp[tx][e[i][g].first]=min(dp[tx][e[i][g].first],ty+e[i][g].second);
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			dp[i][j]=min(dp[i][j],dp[j][i]);
		}
	}
	for(int u=1;u<=n;u++){
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				dp[i][j]=min(dp[i][j],dp[i][u]+dp[u][j]);
			}
		}
	}
	for(int i=1;i<=q;i++) {
		cin>>xr>>yr;
		ans=INF;
		for(int j=0;j<e[xr].size();j++) {
			for(int u=0;u<e[yr].size();u++) {
				ans=min(ans,dp[e[xr][j].first][e[yr][u].first]+e[xr][j].second+e[yr][u].second);
			}
		}
		cout<<(ans+w[xr]+w[yr])<<"\n";
	}
	return 0;
}