#include<bits/stdc++.h>
#define int long long

const int N=510;

const int M=5e5+10;

using namespace std;

int T;

int c;

int n,m,d,q;

int W[M];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+(ch&15),ch=getchar();
	return ret*f;
}

struct info{
	int id,t;
};

vector<info>tmp[M];

int f[N][N];

void _solve(){
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)W[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int a=read(),t=read();
			tmp[a].push_back((info){i,t});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=1e18;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		int siz=tmp[i].size();
		for(int j=0;j<siz;j++){
			for(int k=0;k<j;k++){
				int u=tmp[i][j].id,v=tmp[i][k].id;
				int w=tmp[i][j].t+tmp[i][k].t;
				f[u][v]=f[v][u]=min(f[u][v],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][k]+f[k][j]<f[i][j]){
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
	while(q--){
		int x=read(),y=read();
		int siz_1=tmp[x].size();
		int siz_2=tmp[y].size();
		int ans=1e18;
		for(int i=0;i<siz_1;i++){
			for(int j=0;j<siz_2;j++){
				int u=tmp[x][i].id,v=tmp[y][j].id;
				ans=min(ans,f[u][v]+tmp[x][i].t+tmp[y][j].t);
			}
		}
		ans+=W[x]+W[y];
		printf("%lld\n",ans);
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	T=1;
	while(T--)_solve();
	return 0;
}