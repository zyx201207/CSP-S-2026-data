#include<bits/stdc++.h>
using namespace std;
#define pll pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define int long long
#define gc getchar
const int M=5e5+5;
const int N=5e2+5;
const int INF=1e18;
int CASE,n,m,DDD,q;
int w[M];
int d[N][N];
vector<pll> train[M];
int read(){
	int f=1,sum=0;
	char c=gc();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=gc();
	}
	while(c>='0'&&c<='9'){
		sum=sum*10+c-'0';
		c=gc();
	}
	return sum*f;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	CASE=read(),n=read(),m=read(),DDD=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int v=read(),c=read();
			train[v].emplace_back(mkp(i,c));
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=m;i++){
		for(pll e1:train[i]){
			for(pll e2:train[i]){
				int u=e1.fi,v=e2.fi,w=e1.se+e2.se;
				if(u==v){
					continue;
				}
				d[u][v]=d[v][u]=min(d[u][v],w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		d[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				if(x==y){
					continue;
				}
				d[x][y]=min(d[x][y],d[x][k]+d[k][y]);
			}
		}
	}
	while(q--){
		int x=read(),y=read();
		int ans=INF;
		for(pll e1:train[x]){
			for(pll e2:train[y]){
				int u=e1.fi,v=e2.fi,w=e1.se+e2.se;
				ans=min(ans,d[u][v]+w);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
} 
