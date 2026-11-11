#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=507,M=5e5+7;
const ll INF=1e17+7;

int c,n,m,d,q,k,a,t,x,y;
ll halltogate[M],dis[N][N],res,ans;
struct line {
	int id;
	ll ti;
};
struct station {
	vector<line> X;
} S[M];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>halltogate[i];
	for(int i=1;i<=n;i++) {
		cin>>k;
		for(int j=1;j<=k;j++) {
			cin>>a>>t;
			S[a].X.push_back(line{i,t});
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(i==j)dis[i][j]=0;
			else dis[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++) {
		for(int j=0;j<S[i].X.size();j++) {
			for(int k=j+1;k<S[i].X.size();k++) {
				int u=S[i].X[j].id,v=S[i].X[k].id;
				ll wu=S[i].X[j].ti,wv=S[i].X[k].ti;
				dis[u][v]=min(dis[u][v],wu+wv);
				dis[v][u]=min(dis[v][u],wu+wv);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=q;i++) {
		cin>>x>>y;
		res=0,ans=INF;
		res+=halltogate[x]+halltogate[y];
		for(int j=0;j<S[x].X.size();j++) {
			for(int k=0;k<S[y].X.size();k++) {
				int u=S[x].X[j].id,v=S[y].X[k].id;
				ll wu=S[x].X[j].ti,wv=S[y].X[k].ti;
				ans=min(ans,res+wu+wv+dis[u][v]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
