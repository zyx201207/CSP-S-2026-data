#include<bits/stdc++.h>
#define INF 1e18
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define Rep(i,l,r) for(int i=(l);i>=(r);--i)
#define gc getchar()
#define pii pair<int,int>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=gc;
	}
	return x*f;
}
const int N=509,M=500009;
int c,n,m,D,q;
int w[M];
vector<pii> e[M];
int d[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),D=read(),q=read();
	rep(i,1,m){
		w[i]=read();
	}
	rep(i,1,n){
		rep(j,1,n) d[i][j]=INF;
		d[i][i]=0;
	}
	rep(i,1,n){
		int k=read();
		rep(j,1,k){
			int a=read(),t=read();
			e[a].push_back({i,t});
		}
	}
	rep(x,1,m){
		int sz=e[x].size();
		rep(i,0,sz-1){
			rep(j,0,sz-1){
				int u=e[x][i].first,val1=e[x][i].second,v=e[x][j].first,val2=e[x][j].second;
				d[u][v]=min(d[u][v],val1+val2);
				d[v][u]=min(d[v][u],val1+val2);
			}
		}
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
//	rep(i,1,n){
//		rep(j,1,n){
//			printf("d[%d][%d]=%d\n",i,j,d[i][j]);
//		}
//	}
	rep(tst,1,q){
		int x=read(),y=read();
		int ans=INF;
		int sz1=e[x].size(),sz2=e[y].size();
		rep(i,0,sz1-1){
			rep(j,0,sz2-1){
				int u=e[x][i].first,val1=e[x][i].second,v=e[y][j].first,val2=e[y][j].second;
				ans=min(ans,d[u][v]+val1+val2);
			}
		}
		ans+=w[x];
		ans+=w[y];
		cout<<ans<<'\n';
	}
	return 0;
}

