#include<bits/stdc++.h>
using namespace std;
const int N=508,M=1e3+8;
int c,n,m,d,q,w[M],t[N][M];
bool flag[M][28];
vector<int> g[M];
int sx,sy;
struct node{
	int v,line,preline,cost;
};
bool vis[M];
int bfs(int sline){
	memset(vis,0,sizeof vis);
	int pre=w[sx]+t[sline][sline];
	//cout<<"t[sline][sline]"<<t[sline][sline]<<"\n"<<"pre "<<pre<<"\n";
	int res=1e9;
	queue<node> q;
	q.push(node{sx,sline,sline,0});
	while(!q.empty()){
		node u=q.front();q.pop();
		int v=u.v,line=u.line,cost=u.cost,preline=u.preline;
		if(v==sy){
//			cout<<"preline"<<preline<<"  line"<<line<<"\n";
			int suf=t[preline][line]+w[v];
//			cout<<"w[2]"<<w[2]<<"\n";
//			cout<<"pre"<<pre<<"  suf"<<suf<<"\n";
			//cout<<"w[ev]"<<w[v]<<"\n"<<"ev"<<v<<"\n";
//			cout<<"cost"<<cost<<"t[1][2]"<<t[1][2];
//			if(line==preline)suf=t[preline][line]+w[v];
//			else suf=w[v];
			res=min(res,pre+cost+suf);
		}
		if(vis[v])continue;
		vis[v]=true;
		for(int i=0;i<g[v].size();i++){
			int cur=g[v][i];
			if(flag[cur][line]){
				q.push(node{cur,line,line,cost});
			}else{
				for(int j=1;j<=n;j++){
					if(flag[cur][j]&&j!=line){
						q.push(node{cur,j,line,cost+t[line][j]+t[j][line]});
						//cout<<"exchange"<<line<<"to"<<j<<"\n";
					}
				}
			}
		}
	}
	return res;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,u,v;
		cin>>k>>u>>t[i][1];
		//t[1][i]=t[i][1];
		flag[u][i]=1;
		for(int j=2;j<=k;j++){
			cin>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			flag[v][i]=1;
			cin>>t[i][j];
			//t[j][i]=t[i][j];
			u=v;
		}
	}
//	cout<<"t[1][1]"<<t[1][1]<<"t[1][2]"<<
//	t[1][2]<<"t[2][2]"<<t[2][2]<<"t[2][3]"<<t[2][3]<<"\n";
	while(q--){
		cin>>sx>>sy;
		int ans=1e9;
		for(int j=1;j<=n;j++){
			if(flag[sx][j]){
				ans=min(ans,bfs(j));
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
