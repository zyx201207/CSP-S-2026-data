#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
const int N=5e5+5;
const int INF=1e18+9;
int C,n,m,d,q;
int w[N];
vector< pair<int,int> > edge[N];
int a[N],t[N];
int dis[N];
int p[N],cnt;
void diji(int x,int y){
	for(int i=1;i<=m;i++){
		dis[i]=INF;
	}
	dis[x]=0;
	cnt=0;
	int minn=INF;
	queue<int> q;
	for(int i=0;i<edge[x].size();i++){
		int yy=edge[x][i].first();
		int c=edge[x][i].second();
		dis[yy]=dis[x]+c;
		if(dis[yy]<minn){
			minn=dis[yy];
			p[++cnt]=yy;
		}
	}
	for(int i=1;i<=cnt;i++){
		q.push(p[i]);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		minn=INF;
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i].first();
			int c=edge[u][i].second();
			dis[v]=min(dis[v],dis[u]+c);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
				edge[a[j]].push_back({a[l],t[j]+t[l]});
				edge[a[l]].push_back({a[j],t[j]+t[l]});
			}
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		diji(x,y);
	}
	return 0;
}







//16:02 草啊，脑子里怎么会突然开始播放5980。。。
//16:07 后悔没有复习最短路。 
//16:16 可以退役了。 
//16:23 ok自由落体 
