#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXM=5e5+7,MAXN=5e2+7;
const long long INF=0x3f3f3f3f3f3f3f3f;
struct EDGE{
	int to,nxt;
	long long value;
}e[MAXM];
int head[MAXM],e_cnt;
inline void add(int u,int v,long long w){
	e[++e_cnt]={v,head[u],w};
	head[u]=e_cnt;
}

long long dis[MAXN][MAXN],w[MAXM];
int c,n,m,d,q;
inline void Read(){
	for(int i=0;i<MAXN;i++)
		for(int j=0;j<MAXN;j++)
			if(i!=j) dis[i][j]=INF;
	memset(head,0,sizeof head),e_cnt=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,u;j<=k;j++){
			long long t;
			cin>>u>>t;
			for(int ii=head[u];ii;ii=e[ii].nxt){
				int v=e[ii].to;
				long long w=e[ii].value;
				dis[i][v]=dis[v][i]=min(dis[i][v],w+t);
			}
			add(u,i,t);
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	Read();
	while(q--){
		int a,b;
		long long ans=INF;
		cin>>a>>b;
		for(int i=head[a];i;i=e[i].nxt)
			for(int j=head[b];j;j=e[j].nxt){
				int u=e[i].to,v=e[j].to;
				long long uw=e[i].value,vw=e[j].value;
				ans=min(ans,w[a]+w[b]+uw+vw+dis[u][v]);
			}
		cout<<ans<<"\n";
	}
	return 0;
}
