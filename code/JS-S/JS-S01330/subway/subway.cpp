#include<bits/stdc++.h>
using namespace std;
static inline int read(){
	char c;int a=0;
	while(!isdigit(c=getchar()));
	do a=a*10+(c^48);while(isdigit(c=getchar()));
	return a;
}
int n,m,q;
int w[500010];
vector<pair<int,int> >v[500010];
long long dis[510][510];
static inline void update(long long&x,const long long&k){x=min(x,k);}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(),n=read(),m=read(),read(),q=read();
	for(int i=1;i<=m;++i)w[i]=read();
	for(int i=1;i<=n;++i){
		int k=read();
		while(k--){
			int a=read(),t=read();
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<n;++i)for(int j=i+1;j<=n;++j)dis[i][j]=dis[j][i]=1e17;
	for(int i=1;i<=m;++i){
		int k=v[i].size();
		for(int j=0;j<k;++j)for(int l=0;l<k;++l)if(j^l)
			update(dis[v[i][j].first][v[i][l].first],v[i][j].second+v[i][l].second);
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				update(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x=read(),y=read();
		long long ans=LLONG_MAX;
		for(pair<int,int>A:v[x])for(pair<int,int>B:v[y])
			update(ans,dis[A.first][B.first]+A.second+B.second);
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
