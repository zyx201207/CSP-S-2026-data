#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10,INF=0x3f3f3f3f;
int c,n,m,d,q,ans,dis[N];
int w[N],a[501][N],t[501][N],k[501];
int fst[N],nex[N],to[N],sw[N],tot;
bool vis[N];
void add(int x,int y,int z){
	nex[++tot]=fst[x];
	fst[x]=tot;
	to[tot]=y;
	sw[tot]=z;
}
int dijstla(int s,int h){
	for(int i=1;i<=m;i++) dis[i]=INF,vis[i]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,s});
	vis[s]=1;
	while(!q.empty()){
		pair<int,int> num=q.top();
		q.pop();
		int u=num.second;
		//if(!vis[u]) continue;
		dis[u]=num.first;
		for(int i=fst[u];i;i=nex[i]){
			int y=to[i];
			//cout<<sw[i]<<" "<<u<<" "<<y<<endl;
			if(dis[y]>dis[u]+sw[i]){
				dis[y]=dis[u]+sw[i];
				q.push({dis[y],y});
				//vis[y]=1;
			}
		}
	}
	return dis[h];
}
signed main(){
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
			for(int p=1;p<j;p++){
				int a1=a[i][j],a2=a[i][p];
				//cout<<a1<<" "<<a2<<" "<<t[i][j]+t[i][p]<<" "<<i<<endl;
				add(a1,a2,t[i][p]+t[i][j]),add(a2,a1,t[i][j]+t[i][p]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dijstla(x,y)+w[x]+w[y]<<endl;
	}
	return 0;
}
