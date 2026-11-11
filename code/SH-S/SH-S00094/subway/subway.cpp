#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5e5+10,N=510;
ll c,n,m,d,Q,w[M],k,a,tt,y,dp[N][N],b,l,r,ya,yb,ans,s;
struct p{
	ll v,t;
};
vector<p> g[M],h[N];
priority_queue<pair<ll,ll> > q;
bool vs[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
		g[i].clear();
	}
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a>>tt;
			g[a].push_back({i,tt});
		}
		for(int j=1;j<=n;++j)
			dp[i][j]=1e18;
		dp[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		y=g[i].size();
		for(int j=0;j<y;++j)
			for(int k=j+1;k<y;++k){
				a=g[i][j].v;
				b=g[i][k].v;
				l=g[i][j].t+g[i][k].t;
				dp[a][b]=min(dp[a][b],l);
				dp[b][a]=min(dp[b][a],l);
			}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			if(i==j||dp[i][j]==1e18)
				continue;
			h[i].push_back({j,dp[i][j]});
			dp[i][j]=1e18;
		}
	for(int i=1;i<=n;++i){
		while(!q.empty())
			q.pop();
		for(int j=1;j<=n;++j)
			vs[j]=0;
		q.push({0,i});
		while(!q.empty()){
			a=q.top().second;
			l=q.top().first*(-1);
			q.pop();
			if(vs[a])
				continue;
			vs[a]=1;
			for(p o:h[a]){
				b=o.v;
				r=o.t;
				if(l+r<dp[i][b]){
					dp[i][b]=l+r;
					q.push({dp[i][b]*(-1),b});
				}
			}
		}
	}
	while(Q--){
		cin>>a>>b;
		ans=1e18;
		ya=g[a].size();
		yb=g[b].size();
		for(int i=0;i<ya;++i)
			for(int j=0;j<yb;++j){
				l=g[a][i].v;
				r=g[b][j].v;
				s=dp[l][r]+g[a][i].t+g[b][j].t;
				ans=min(ans,s);
			}
		ans+=w[a]+w[b];
		cout<<ans<<'\n';
	}
	return 0;
}
