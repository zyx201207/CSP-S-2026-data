#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long a[500005];
struct way{
	int id;
	long long dis;
};
long long dis[505][505];
vector<way> to[500005];
long long read(){
	long long ans=0,f=1;
	char s=getchar();
	while(s!='-'&&(s>'9'||s<'0')) s=getchar();
	if(s=='-') s=getchar(),f=-1;
	while(s>='0'&&s<='9') ans=ans*10+s-'0',s=getchar();
	return ans*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			long long u,x;
			u=read();
			x=read();
			to[u].push_back((way){i,x});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) dis[i][j]=1e18;
	for(int i=1;i<=m;i++)
		for(int j=0;j<to[i].size();j++)
			for(int k=0;k<to[i].size();k++){
				if(j==k) continue;
				dis[to[i][k].id][to[i][j].id]=dis[to[i][j].id][to[i][k].id]=min(to[i][j].dis+to[i][k].dis,dis[to[i][j].id][to[i][k].id]);
			}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=1;k<=n;k++) dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		long long ans=1e18;
		for(int i=0;i<to[u].size();i++)
			for(int j=0;j<to[v].size();j++) ans=min(ans,to[u][i].dis+to[v][j].dis+dis[to[u][i].id][to[v][j].id]);
		printf("%lld\n",ans+a[u]+a[v]);
	}
	return 0;
}