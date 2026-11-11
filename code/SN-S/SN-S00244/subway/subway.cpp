#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=5e5+10;
int C,n,m,d,q;
int w[maxn];
struct A{
	int to,tim,bh;
};
vector<A> g[maxn];
int sy[maxn],sy1[maxn];
int pd[maxn],pd2[510],dis[maxn];
int x,y;
int ans;
void dfs(int nowx,int ansx){
	if(nowx==y){
		ans=min(ans,ansx+w[x]+w[y]);
		return;
	}
	int siz=g[nowx].size();
	for(int i=0;i<siz;i++){
		if(pd[g[nowx][i].to]||pd2[g[nowx][i].bh]) continue;
		int jz=g[nowx][i].tim;
		if(dis[g[nowx][i].to]<ansx+jz) continue;
		dis[g[nowx][i].to]=ansx+jz;
		pd2[g[nowx][i].bh]=1;
		pd[nowx]=1;
		dfs(g[nowx][i].to,ansx+jz);
		pd2[g[nowx][i].bh]=0;
		pd[nowx]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>sy[j]>>sy1[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				g[sy[j]].push_back({sy[l],sy1[j]+sy1[l],i});
			}
		}
	}
	for(int i=1;i<=q;i++){
		ans=1e9+10;
		cin>>x>>y;
		for(int j=1;j<=m;j++){
			dis[j]=1e9+10;
		}
		dfs(x,0);
		cout<<ans<<"\n";
	}
	return 0;
}
