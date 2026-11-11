#include<bits/stdc++.h>
using namespace std;
#define fre(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define pb push_back
typedef pair<int,int> pii;
const int N=519,M=5e5+19,inf=0x3f3f3f3f;
int c,n,m,dd,q,w[N],k[N];
vector<int> a[N],t[N];
vector<pii> bl[M],g[M];
int d[M],vis[M];
signed main(){
	fre(subway);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int ai,ti;cin>>ai>>ti;
			a[i].pb(ai);t[i].pb(ti);
			bl[ai].pb({i,ti});
		}
	}
	//cout<<bl[5].size()<<'!';
	for(int i=1;i<=m;i++){
		if(bl[i].size()>1){
			for(int j=0;j<(int)bl[i].size()-1;j++){
				for(int k=j+1;k<(int)bl[i].size();k++){
					int wr=bl[i][j].second+bl[i][k].second;
					int jj=bl[i][j].first,kk=bl[i][k].first;
					g[jj].pb({kk,wr});g[kk].pb({jj,wr});
				}
			}
		}
	}
	//for(int i=0;i<g[2].size();i++)cout<<g[2][i].first<<' '<<g[2][i].second<<'\n'; 
	while(q--){
		int x,y;cin>>x>>y;
		if(x<y)swap(x,y);
		//s:bl[x] t:bl[y]
//		if(16<=c&&c<=19){
//			queue<int> q;
//			memset(vis,0,sizeof(0));
//			memset(d,0x3f3f3f3f,sizeof(d));
//			for(int j=0;j<(int)bl[x].size();j++){
//				int i=bl[x][j].first;
//				q.push(i);
//				vis[i]=1;
//			}
//			while(q.size()){
//				int u=q.front();q.pop();
//				for(int i=0;i<(int)g[u].size();i++){
//					int v=g[u][i].first;
//					if(!vis[v]){
//						d[v]=d[u]+1;
//						q.push(v);
//					}
//				}
//			}
//			int minn=inf;
//			for(int j=0;j<(int)bl[y].size();j++){
//				int i=bl[y][j].first,ti=bl[y][j].second;
//				minn=min(minn,2*d[i]*t[1][1]+ti);
//			}
//			cout<<minn+w[x]+w[y]<<'\n';
//		}
		priority_queue<pii,vector<pii>,greater<pii>> q;
		memset(d,0x3f3f3f3f,sizeof(d));
		for(int j=0;j<(int)bl[x].size();j++){
			int i=bl[x][j].first,ti=bl[x][j].second;
			q.push({ti,i});
			d[i]=ti;
		}
		while(q.size()){
			int dis=q.top().first;
			int u=q.top().second;q.pop();
			if(d[u]!=dis)continue;
			for(int i=0;i<(int)g[u].size();i++){
				int v=g[u][i].first,w=g[u][i].second;
				if(d[v]>d[u]+w){
					d[v]=d[u]+w;
					q.push({d[v],v});
				}
			}
		}
		int minn=inf;
		for(int j=0;j<(int)bl[y].size();j++){
			int i=bl[y][j].first,ti=bl[y][j].second;
			minn=min(minn,d[i]+ti);
		}
		cout<<minn+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
