#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int c,n,m,d,q;
long long w[500010];
vector<int> a[10000];
vector<long long> t[10000];
vector<pair<int,long long> > g[500010];
long long dist[5010][5010];
bool vis[5010][5010];
vector<int> id[500010];
long long ddist[500010];
bool vvis[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	
	swap(n,m);
	
	for(int i=1;i<=n;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=m;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x;
			long long y;
			scanf("%d%lld",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
			id[x].push_back(i);
		}
	}
	if(c>=12&&c<=19){
		
		long long T=t[1][0];
		while(q--){
			for(int i=1;i<=n;i++){
				vvis[i]=0;
			}
			int x,y;
			scanf("%d%d",&x,&y);

			queue<int> q;
			q.push(x);
			ddist[x]=0;
			vvis[x]=1;
			while(!q.empty()){
				int p=q.front();
				//cout<<"!"<<p<<endl;
				q.pop();
				if(p==y){
					printf("%lld\n",w[x]+w[y]+ddist[y]*T*2);
					break;
				}
				for(int k=0;k<id[p].size();k++){
					int pid=id[p][k];
					//cout<<"#"<<pid<<endl;
					for(int i=0;i<a[pid].size();i++){
						
						int v=a[pid][i];
						//cout<<vvis[v]<<endl;
						
						if(!vvis[v]){
							//cout<<"##"<<v<<endl;
							vvis[v]=1;
							ddist[v]=ddist[p]+1;
							q.push(v);
							
						}
					}
				}
			}
			
		}
		return 0;
	}
	
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=n;i++){
		dist[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			int u=a[i][j];
			for(int k=j+1;k<a[i].size();k++){
				int v=a[i][k];
				g[u].push_back({v,t[i][j]+t[i][k]});
				g[v].push_back({u,t[i][j]+t[i][k]});
				//dist[u][v]=dist[v][u]=t[i][j]+t[i][k];
				//cout<<"!"<<u<<" "<<v<<" "<<t[i][j]+t[i][k]<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++){
		//cout<<"###"<<i<<endl;
		priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
		q.push({0,i});
		dist[i][i]=0;
		while(!q.empty()){
			pair<long long,int> p=q.top();
			//cout<<"##"<<p.second<<endl;
			q.pop();
			if(vis[i][p.second]){
				continue;
			}
			vis[i][p.second]=1;
			for(int j=0;j<g[p.second].size();j++){
				
				int v=g[p.second][j].first;
				
				long long w=g[p.second][j].second;
				if(dist[i][v]>dist[i][p.second]+w){
					//cout<<"#"<<v<<" "<<vis[i][v]<<endl;
					dist[i][v]=dist[i][p.second]+w;
					if(!vis[i][v]){
						q.push({dist[i][v],v});
					}
				}
			}
		}
	}
	while(q--){
		int x,y;

		scanf("%d%d",&x,&y);
		printf("%lld\n",dist[x][y]+w[x]+w[y]);
	}
	return 0;
}
