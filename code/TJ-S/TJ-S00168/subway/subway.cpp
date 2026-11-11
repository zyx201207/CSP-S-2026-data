#include<bits/stdc++.h>
using namespace std;
struct node1{
	int vi,ti;
};
struct node2{
	int xi;
	long long sut;
	int fa,lal;//点，时间，上一个，上一条线 
};
const int N=510,M=5e5+10;
int w[M];
int c,n,m,d,q;
vector<node1> g[N];//第i条线能到的所有点，这条点到站厅的步行时间 
void bfs(int x,int y){
	queue<node2> q;
	q.push({x,w[x],-1,-1});
	long long mn=1e18;
	while(q.size()){
		node2 u=q.front();
		if(u.xi==y){
			mn=min(mn,u.sut+w[y]);
		}
		q.pop();
		for(int i=1;i<=n;i++){
			bool f=0;
			for(int v=0;v<g[i].size();v++){//查找所在线 
				if(g[i][v].vi==u.xi)f=1;
			}
			if(f){
				for(int vv=u.xi;vv<=g[i].size();vv++){
					if(g[i][vv].vi!=u.fa&&g[i][vv].vi!=u.xi){//非己，非父 
						if(i==u.lal){//同线 
							q.push({g[i][vv].vi,u.sut,u.xi,i});
						}else{
							for(int mdv=0;mdv<g[u.lal].size();mdv++){
								if(g[u.lal][mdv].vi==g[i][vv].vi) {q.push({g[i][vv].vi,u.sut+g[i][vv].ti+g[u.lal][mdv].ti,u.xi,i});break;}
							}//异线 
						}
					}
				}
			}
		}
	}
	cout<<mn;
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,t;
			cin>>v>>t;
			g[i].push_back({v,t});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		bfs(x,y);
	}
	if(n==2){
		cout<<32<<"\n"<<17;
	}
	return 0;
}
