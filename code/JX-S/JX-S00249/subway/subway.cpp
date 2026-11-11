#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
};
const int N=20000;
int fa[N];
long long n,m,c,d,q;
long long w[N],t[505][100000];//
vector<int> g[100000];
vector<node> s[505];
long long vis[505],dis[505];
long long zdr[505][505];
bool is[502];
void dij(int k){
	is[k]=1;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		dis[i]=1e18;
	}
	dis[k]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,k});
	while(!q.empty()){
		int u=q.top().second;
		//cout<<u<<endl;
		//cout<<s[u].size();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		//cout<<s[u].size()<<endl;
		for(int i=0;i<s[u].size();i++){
			//cout<<1145;
			int v=s[u][i].v,val=s[u][i].w;
			//cout<<v<<" "<<val;
			if(dis[v]>dis[u]+val){
				dis[v]=dis[u]+val;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			zdr[i][j]=0x3f3f3f3f3f;
		}
	}
	for(int i=1;i<=n;i++){
		int ks;
		cin>>ks;
		for(int j=1;j<=ks;j++){
			int a,b;
			cin>>a>>b;
			t[i][a]=b;
			if(g[a].size()>0){
				for(int k=0;k<g[a].size();k++){
					int v=g[a][k];
					zdr[v][i]=min(zdr[v][i],t[i][a]+t[v][a]);
					zdr[i][v]=zdr[v][i];
				}
			}
			g[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(zdr[i][j]!=0x3f3f3f3f3f){
				s[i].push_back({j,zdr[i][j]});
				s[j].push_back({i,zdr[i][j]});				
			}

		}
	}
	/*
	for(int i=1;i<=n;i++){
		cout<<i<<endl;
		for(int j=0;j<s[i].size();i++){
			cout<<s[i][j].v<<" "<<s[i][j].w<<endl;
		}
	}
	* */
	//cout<<t[2][1]<<endl;
	for(int i=1;i<=q;i++){
		int st,ed,kt,kd;
		cin>>st>>ed;
			long long minx=1e18;
			for(int j=0;j<g[st].size();j++){
				dij(g[st][j]);
				for(int k=0;k<g[ed].size();k++){
					//cout<<g[ed][k]<<endl;
					if(minx>=dis[g[ed][k]]){
						kt=g[st][j];
						kd=g[ed][k];
						minx=dis[g[ed][k]];
					}
				}
			}
			//cout<<kt<<" "<<kd<<" "<<minx<<endl;
			cout<<w[st]+w[ed]+t[kt][st]+t[kd][ed]+minx<<endl;
	}
}
