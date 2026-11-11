#include<bits/stdc++.h>
#define file(x) freopen(x".in","r",stdin);\
				freopen(x".out","w",stdout);
#define lowbit(x) ((x)&(-(x)))
#define int long long
using namespace std;
const int N=505,M=5e5+5,inf=1e18;
int dis[N][N],w[M];
struct Isolation{
	int to,v;
};
vector<Isolation>to[M];
signed main(){
	file("subway");
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,x,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>t;
			to[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j) dis[i][j]=0;
			else dis[i][j]=inf;
	for(int i=1;i<=m;i++){
		for(Isolation s1:to[i])
			for(Isolation s2:to[i])
				dis[s1.to][s2.to]=min(dis[s1.to][s2.to],s1.v+s2.v);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int st,ed;
		cin>>st>>ed;
		int ans=inf;
		for(Isolation s1:to[st])
			for(Isolation s2:to[ed])
				ans=min(ans,dis[s1.to][s2.to]+s1.v+s2.v);
		cout<<(ans+w[st]+w[ed])<<'\n';
	}
	return 0;
}

