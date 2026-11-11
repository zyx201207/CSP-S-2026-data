#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500,M=500000;
int c,n,m,d,q;
int w[M+5];
int k[N+5];
map<int,int> dian[M+5];//站厅到站台 
vector<int> dianxian[M+5];//站有哪些路线
struct bian{
	int v,c;
};
vector<bian> xian[N+5];//线线之间的时间 
bool vis[N+5];
int dis[N+5];
void bfs(int x,int y){
	queue<int> q;
	memset(vis,0,sizeof vis);
	memset(dis,0x7f,sizeof dis);
	q.push(x);
	vis[x]=1;
	dis[x]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=1;
//		cout<<u<<" "<<dis[u]<<"\n";
		for(int i=0;i<xian[u].size();i++){
			int v=xian[u][i].v;
			if(vis[v]==0){
				q.push(v);
				dis[v]=min(dis[v],dis[u]+xian[u][i].c);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,a,t;j<=k[i];j++){
			cin>>a>>t;
			dian[a][i]=t;
			dianxian[a].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
//		cout<<dian[i].size()<<"\n";
		if(dian[i].size()>1){
			for(auto it1=dian[i].begin();it1!=dian[i].end();it1++){
				for(auto it2=dian[i].begin();it2!=dian[i].end();it2++){
					if(it1==it2)continue;
//					cout<<(*it).first/*xianlu*/<<" "<<(*it).second/*huafei*/<<"\n";
					xian[(*it1).first].push_back({(*it2).first,(*it1).second+(*it2).second});
				}
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
//		bfs(x,y);
		int minn=0x3fffffff;
		for(int i=0;i<dianxian[y].size();i++){
			minn=min(minn,dis[dianxian[y][i]]);
		}
		cout<<minn+w[x]+w[y]<<"\n";
	}
	return 0;
}
