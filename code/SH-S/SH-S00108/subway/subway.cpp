#include<bits/stdc++.h>
#define pii pair<int,int>
#define i1 first
#define i2 second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef double db;
const int N=509,M=2e4+9,INF=0x3f3f3f3f;
int c,n,m,dd,qq,w[M],k[N],a[N][M],t[N][M],g[M][M],dt[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(g,INF,sizeof(g));
	cin>>c>>n>>m>>dd>>qq;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int l=1;l<=k[i];l++){
			int u=a[i][l];
			for(int r=l+1;r<=k[i];r++){
				int v=a[i][r];
				int tm=t[i][l]+t[i][r];
				g[u][v]=min(g[u][v],tm);
				g[v][u]=min(g[v][u],tm);
			}
		}
	}
	while(qq--){
		int x,y,ans=INF; cin>>x>>y;
		memset(dt,INF,sizeof(dt));
		queue<int> q; dt[x]=0; q.push(x);
		while(!q.empty()){
			int u=q.front(),d=dt[q.front()]; q.pop();
			if(u==y){ans=min(ans,d); continue;}
			for(int v=1;v<=m;v++){
				if(g[u][v]==INF) continue;
				if(dt[v]>d+g[u][v]){
					dt[v]=d+g[u][v];
					q.push(v);
				}
			}
		}
		cout<<w[x]+ans+w[y]<<endl;
	}
	return 0;
}
//g32
