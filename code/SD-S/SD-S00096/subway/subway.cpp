#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fr first
#define sc second
#define ls(p) (p<<1)
#define rs(p) ((p<<1)|1)
using namespace std;
typedef pair<int,int> pii;
int const N=5e5+5,INF=1e18;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m,ccc,d,q,ww[N],ans; 
vector<pii> t[N];
int g[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ccc=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		ww[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read(),x=0,y=0;
		for(int j=1;j<=k;j++){
			x=read(),y=read();
			t[x].pb({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=INF;
			g[j][i]=INF;
		}
	}
	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int i=1;i<=m;i++){
		int lll=t[i].size();
		for(int j=0;j<lll;j++){
			for(int k=0;k<lll;k++){
				int w=t[i][j].sc+t[i][k].sc,u=t[i][j].fr,v=t[i][k].fr;
				g[u][v]=min(g[u][v],w);
				g[v][u]=min(g[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read();
		ans=INF;
		for(auto ed:t[x]){
			for(auto dd:t[y]){
				int xx=ed.fr,yy=dd.fr,w=ed.sc+dd.sc;
				ans=min(ans,w+g[xx][yy]);
			}
		}
		cout<<ans+ww[x]+ww[y]<<'\n';
	}
	return 0;
}
/*
！！！！！！！！注意 数组大小 我暴力是只能开这么大 正解别忘了 
我图的形态是
我是不是可以从每一条路的第一个节点开始做
对于询问 我的终点是好枚举出来的
我有若干条链 
 

*/

