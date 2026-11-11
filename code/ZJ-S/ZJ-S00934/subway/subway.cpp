#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int> 
#define fi first
#define se second
#define gc getchar
#define pc putchar
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll=long long;using db=double;
const ll INF=1e18;
const int inf=0x3f3f3f3f;
namespace IO{
	inline int read(){
		int x=0,f=1;
		char ch=gc();
		while(!isdigit(ch)){
			if(ch=='-') f=-f;
			ch=gc();
		}
		while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=gc();
		return x*f;
	}
	inline void write(int x){
		if(x<0) pc('-'),x=-x;
		if(x>9) write(x/10);
		pc(x%10+'0');
	}
}using namespace IO;
const int N=5e2+10,M=5e5+1005;
int c,n,m,d,q,w[M],dis[N][N];
vector<PII> g[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int id=read(),len=read();
			g[id].emplace_back(m+i,len);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=INF;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int u=g[i][j].fi-m,v=g[i][k].fi-m;
				int w=g[i][j].se+g[i][k].se;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=dis[u][v];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		int u=read(),v=read(),res=INF;
		for(auto p1:g[u]){
			int i=p1.fi-m,w1=p1.se;
			for(auto p2:g[v]){
				int j=p2.fi-m,w2=p2.se;
				if(dis[i][j]==INF) continue;
				res=min(res,dis[i][j]+w1+w2);
			}
		}
		write(res+w[u]+w[v]),puts("");
	}
	return 0;
}