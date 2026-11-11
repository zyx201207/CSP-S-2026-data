#include<bits/stdc++.h>
using namespace std;
struct subway{
	long long s=0,t=0;
};
vector<subway> g[50005];
subway o[50005];
long long c,n,m,d,q,vis[50005],w[50005],a[50005];
void dfs(long long x,long long st){
	a[x]=min(a[x],st);
	if (vis[x]==0 || a[x]>st){
		vis[x]=1;
		for (int i=0;i<g[x].size();i++){
			dfs(g[x][i].s,st+g[x][i].t);
		}
	}else{
		return;
	}
}
int main(){
	freopen("subway.in","r",stdin);//文件读写，记得把txt删了 
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		int r;
		cin>>r;
		memset(o,0,sizeof(o));
		for (int j=1;j<=r;j++){
			cin>>o[j].s>>o[j].t;
		}
		for (int j=1;j<=r;j++){
			o[j].t+=o[j-1].t;//存储路径、时间 
			g[o[j-1].s].push_back(o[j]);
			o[j].t-=o[j-1].t;
			o[j-1].t+=o[j].t;
			g[o[j].s].push_back(o[j-1]);
			o[j-1].t-=o[j].t;
		}
	}
	for (int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		memset(a,0x7f,sizeof(a));
		dfs(x,0);
		cout<<w[x]+a[y]+w[y]<<endl;
	}
	return 0;
}