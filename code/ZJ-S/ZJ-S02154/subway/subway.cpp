#include<bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
typedef long long ll;
void fileIO(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
inline ll read(){
	ll s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
const int MAX=5e5+11,MA=505;
int c,n,m,d,q,w[MAX],k[MA];
ll dis[MA][MA];
struct node{
	int to,val;
};
vector<node>edge[MAX];
int main(){
	fileIO();
	c=read(),n=read(),m=read(),d=read(),q=read();
	rep(i,1,m){
		w[i]=read();
	}
	rep(i,1,n){
		k[i]=read();
		int a,t;
		node xx;
		xx.to=i;
		rep(j,1,k[i]){
			a=read(),t=read();
			xx.val=t;
			edge[a].push_back(xx);
		}
	}
	memset(dis,0x1f,sizeof(dis));
	rep(i,1,n){
		dis[i][i]=0;
	}
	for(int i=1,g,x,y;i<=m;i++){
		g=edge[i].size();
		ll dic;
		rep(j,0,g-1){
			x=edge[i][j].to;
			dic=edge[i][j].val;
			rep(p,j+1,g-1){
				y=edge[i][p].to;
				dis[x][y]=min(dis[x][y],dic+edge[i][p].val);
				dis[y][x]=dis[x][y];
			}
		}
	}
	for(int K=1;K<=n;K++){
		for(int i=1;i<=n;i++){
			ll dic=dis[i][K];
			for(int j=i+1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dic+dis[K][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	for(int i=1,xx,yy,g1,g2,x,y;i<=q;i++){
		xx=read(),yy=read();
		ll ans=3e18,dic1,dic2;
		g1=edge[xx].size();
		g2=edge[yy].size();
		rep(j,0,g1-1){
			x=edge[xx][j].to;
			dic1=edge[xx][j].val;
			rep(p,0,g2-1){
				y=edge[yy][p].to;
				dic2=edge[yy][p].val;
				ans=min(ans,dic1+dic2+dis[x][y]);
			}
		}
		ans=ans+w[xx]+w[yy];
		printf("%lld\n",ans);
	}
	return 0;
}
