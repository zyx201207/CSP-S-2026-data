#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500010;
int w[maxn],cnt[1010];
const int INF=1e18;
vector<pair<int,int> > g[maxn];
int d[1010][1010];
int read(){
	int ans=0;
	char c=getchar();
	while('0'<=c&&c<='9'){ans=ans*10+(c-'0'),c=getchar();}
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int c=read(),n=read(),m=read(),t=read(),q=read();
	//scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&t,&q);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) d[i][j]=INF;
			else d[i][j]=0;
	
	for(int i=1;i<=m;i++) w[i]=read();//scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		cnt[i]=read();
		//scanf("%lld",&cnt[i]);
		for(int j=1;j<=cnt[i];j++){
			int x=read(),t=read();
			//cin>>x>>t;
			//G[i].push_back(make_pair(x,t));
			g[x].push_back(make_pair(i,t));
		}
	}
	for(int t=1;t<=m;t++)
		for(int i=0;i<g[t].size();i++)
			for(int j=0;j<i;j++)
				d[g[t][j].first][g[t][i].first]=d[g[t][i].first][g[t][j].first]=min(d[g[t][i].first][g[t][j].first],g[t][i].second+g[t][j].second);
		
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<d[i][j]<<" ";
		cout<<endl;	
	}
	*/
	while(q--){
		int u=read(),v=read();
		//scanf("%lld%lld",&u,&v);
		int ans=INF;
		for(int i=0;i<g[u].size();i++)
			for(int j=0;j<g[v].size();j++)
				ans=min(ans,g[u][i].second+g[v][j].second+d[g[u][i].first][g[v][j].first]);
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}

