#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long dist[1510][1510];
int w[20510];
int a,t;
int k;
priority_queue<pair<long long,int>>pq;
vector<pair<int,long long>>e[500010];
long long dis[20510];
queue<int>qe;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=m+1;i<=m+n;++i){
		cin>>k;
		while(k--){
			cin>>a>>t;
			e[i].push_back({a,t});
			e[a].push_back({i,t});
		}
	}
    if(c<=11){
        memset(dist,0x3f,sizeof dist);
        for(int i=1;i<=n+m;++i){
            dist[i][i]=0;
            pq.push({-dist[i][i],i});
            while(!pq.empty()){
                while(!pq.empty()&&pq.top().first!=-1*dist[i][pq.top().second])pq.pop();
				if(pq.empty())break;
				int u=pq.top().second;
				long long d=pq.top().first*-1;
				pq.pop();
				for(pair<int,long long> tmp:e[u]){
					int v=tmp.first;
					long long l=tmp.second;
					if(d+l<dist[i][v]){
						dist[i][v]=d+l;
						pq.push({-dist[i][v],v});
					}
				}
            }
        }
		while(q--){
			int u,v;
			cin>>u>>v;
			cout<<w[u]+w[v]+dist[u][v]<<'\n';
		}

    }else if(c<=15){
		while(q--){
			int u,v;
			cin>>u>>v;
			memset(dis,-1,sizeof dis);
			qe.push(u);
			dis[u]=0;
			while(!qe.empty()){
				int a=qe.front();
				qe.pop();
				for(auto b:e[a]){
					if(dis[b.first]==-1){
						dis[b.first]=dis[a]+b.second;
						qe.push(b.first);
					}
				}
			}
			cout<<w[u]+w[v]+dis[v]<<'\n';
		}
	}
    return 0;
}
