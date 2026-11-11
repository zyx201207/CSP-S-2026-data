#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q,w[500010],k,a,t,x,y;
vector<pair<int,int> > s[500010];
ll dis[510][510],ans,inf=0x3f3f3f3f3f3f3f3f;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k=read();
		while(k--){
			a=read(),t=read();
			s[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=(i==j?0:inf);
	for(int i=1;i<=m;i++){
		for(int j=0;j<s[i].size();j++)
			for(int k=j+1;k<s[i].size();k++){
				int u=s[i][j].first,v=s[i][k].first;
				ll w=s[i][j].second+s[i][k].second;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		x=read(),y=read();
		ans=inf;
		for(auto it1:s[x])
			for(auto it2:s[y]){
				ans=min(ans,dis[it1.first][it2.first]+it1.second+it2.second);
//				printf("%lld %lld %lld\n",dis[it1.first][it2.first],it1.second,it2.second);
			}
		printf("%lld\n",ans+w[x]+w[y]);
	}
}