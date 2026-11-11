#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN=5e5+5;

struct node{
	int v,id;
};
struct edge{
	int u,w,l;
};

int cw[MAXN];
int c,n,m,d,q;
vector<node> G[MAXN];
int ct[20000][500],dis[20000][500],vis[20000][500];

void spfa(int s,int ed){
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)	dis[i][j]=1e18;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)	vis[i][j]=0;
	queue<edge> q;
	for(int i=1;i<=n;i++){
		if(ct[s][i]!=0){
			q.push({s,ct[s][i],i});
			dis[s][i]=ct[s][i];
			vis[s][i]=1;
		}
	}
	while(q.size()){
		auto crt=q.front();
		q.pop();
		int u=crt.u,w=crt.w,line=crt.l;
		for(auto i:G[u]){
			int v=i.v,newline=i.id;
			if(!vis[v][newline]){
				if(v!=ed&&w+ct[v][line]+ct[v][newline]<dis[v][newline]){
					dis[v][newline]=w+ct[v][line]+ct[v][newline];
					vis[v][newline]=1;
					q.push({v,dis[v][newline],newline});
				}else if(v==ed&&w+ct[v][line]<dis[v][newline]){
					dis[v][newline]=w+ct[v][line];
					vis[v][newline]=1;
					q.push({v,dis[v][newline],newline});
				}
			}
		}
	}
}

void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>cw[i];
	bool Speacial_Tasks_B=true;
	int Speacial_Tasks_B_T;
	for(int i=1;i<=n;i++){
		vector<int> line;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,t;
			cin>>v>>t;
			if(i==1&&j==1)	Speacial_Tasks_B_T=t;
			else if(Speacial_Tasks_B_T!=t)	Speacial_Tasks_B=false;
			ct[v][i]=t;
			for(int u:line){
				G[v].push_back({u,i});
				G[u].push_back({v,i});
			}
			line.push_back(v);
		}
	}
	
	if(Speacial_Tasks_B){
		while(q--){
			int x,y;
			cin>>x>>y;
			for(int i=1;i<=m;i++)
				for(int j=1;j<=n;j++)	vis[i][j]=0;
			queue<edge> q;
			for(int i=1;i<=n;i++){
				if(ct[x][i]!=0){
					q.push({x,1,i});
					vis[x][i]=1;
				}
			}
			while(q.size()){
				auto crt=q.front();
				q.pop();
				int u=crt.u,w=crt.w,line=crt.l;
				if(u==y){
					cout<<cw[x]+cw[y]+Speacial_Tasks_B_T*w<<'\n';
					break;
				}
				for(auto i:G[u]){
					int v=i.v,newline=i.id;
					if(!vis[v][newline]){
						if(newline!=line)	q.push({v,w+1,newline});
						else	q.push({v,w,newline});
						vis[v][newline]=1;
					}
				}
			}
		}
		return ;
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		spfa(x,y);
		int ans=1e18;
		for(int i=1;i<=n;i++)
			ans=min(ans,dis[y][i]);
		cout<<cw[x]+cw[y]+ans<<'\n';
	}
	
	
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	solve();

	return 0;
}