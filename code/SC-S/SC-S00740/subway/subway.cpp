#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int mx=1e3+10,inf=1e9+7;
int c,n,m,d,q;
int w[mx],a[mx][mx],t[mx][mx],k[mx],x,y,ans=inf;
bool vis[mx],visr[mx];
struct node{
	int rout[mx],num[mx],tim[mx],top=0;
}sta[mx];
struct node2{
	int pos[mx],top=0,tim[mx],bon[mx];
}lin[mx];
void dfs(int x0,int r0,int t0){
	if(x0==y){
		ans=min(ans,t0+lin[r0].tim[lin[r0].bon[x0]]);
		return;
	}
	visr[r0]=1;
	vis[x0]=1;
	for(int i=1;i<=lin[r0].top;i++){
		if(vis[lin[r0].pos[i]]==1) continue;
		dfs(lin[r0].pos[i],r0,t0);
	}
	for(int i=1;i<=sta[x0].top;i++){
		if(visr[sta[x0].rout[i]]==1) continue;
		dfs(x0,sta[x0].rout[i],t0+sta[x0].tim[i]+lin[sta[x0].rout[i]].tim[lin[sta[x0].rout[i]].bon[x0]]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			sta[a[i][j]].rout[++sta[a[i][j]].top]=i;
			sta[a[i][j]].num[sta[a[i][j]].top]=j;
			sta[a[i][j]].tim[sta[a[i][j]].top]=t[i][j];
			lin[i].pos[++lin[i].top]=a[i][j];
			lin[i].tim[lin[i].top]=t[i][j];
			lin[i].bon[a[i][j]]=lin[i].top;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=inf;
		memset(vis,0,sizeof(vis));
		memset(visr,0,sizeof(visr));
		for(int i=1;i<=sta[x].top;i++){
			dfs(x,sta[x].rout[i],sta[x].tim[i]);
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
} 