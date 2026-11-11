#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f;
const int inff=0x3f3f3f3f3f3f3f3f;
const int N=5e5+5;
const int M=505;
const int MM=M*2;
const int X=1e5+5;
const int mod=1e9+7;
int c,n,m,d,q,w[N],len[M],vis[M],dist[M][M],dis[M][M];
int head[M],ver[MM],Next[MM],edge[MM],tot=-1;
map<int,int> mp[M];
vector<pair<int,int> > v[N];
void add(int x,int y,int z){
	ver[++tot]=y;
	edge[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
struct node{
	int id;
	int x;
};
bool operator < (node a,node b){
	return a.x>b.x;
}
node aaa(int id,int x){
	node aa;
	aa.id=id;
	aa.x=x;
	return aa;
}
void Dij(int root){
	memset(vis,0,sizeof(vis));
	dist[root][root]=0;
	priority_queue<node> pq;
	pq.push(aaa(root,0));
	while(!pq.empty()){
		int y=pq.top().id;
		pq.pop();
		if(vis[y]){
			continue;
		}
		vis[y]=1;
		for(int i=head[y];~i;i=Next[i]){
			int z=ver[i];
			if(vis[z]){
				continue;
			}
			if(dist[root][y]+edge[i]<dist[root][z]){
				dist[root][z]=dist[root][y]+edge[i];
				pq.push(aaa(z,dist[root][z]));
			}
		}
	}
	return ;
}
void fast(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	fast();
	memset(head,-1,sizeof(head));
	memset(dist,0x3f,sizeof(dist));
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>len[i];
		for(int j=1;j<=len[i];j++){
			int A,T;
			cin>>A>>T;
			mp[i][A]=T;
			v[A].push_back({i,T});
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			int minn=inff;
//			for(auto it : mp[i]){
//				if(mp[j].count(it.first)){
//					minn=min(minn,mp[j][it.first]+it.second);
//				}
////				cout<<it.first<<' '<<it.second<<' '<<mp[j].count(it.first)<<'\n';
//			}
//			if(minn!=inff){
////				cout<<minn<<'\n';
//				add(i,j,minn);
//				add(j,i,minn);
//			}
//		}
//	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<v[i].size();k++){
				dis[v[i][j].first][v[i][k].first]=min(dis[v[i][j].first]
				[v[i][k].first],v[i][j].second+v[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]<inf&&i!=j){
				add(i,j,dis[i][j]);
			}
//			cout<<dis[i][j]<<' ';
		}
//		cout<<'\n';
	}
	for(int i=1;i<=n;i++){
		Dij(i);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dist[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int minn=inff;
		for(int xx=0;xx<v[x].size();xx++){
			for(int yy=0;yy<v[y].size();yy++){
				minn=min(minn,dist[v[x][xx].first][v[y][yy].first]+v[x][xx].second+v[y][yy].second);
//				cout<<v[x][xx]<<' '<< v[y][yy]<<'\n';
//				cout<<'a'<<st[v[x][xx]]<<' '<<ed[v[y][yy]]<<' '<<minn<<'\n';
			}
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 480 479521 20 90000
*/
