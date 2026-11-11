#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n,c,d,p,w[500010],k,dist[500010],vis[500010];
vector<pair<int,int>>e[500010];
priority_queue<int,vector<int>,greater<int>>q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		int qwq,QWQ;
		cin>>qwq>>QWQ;
		e[qwq].push_back({qwq,QWQ});
		for(int i=2;i<=k;i++){
			int a,t;
			cin>>a>>t;
			e[a].push_back({qwq,t+QWQ});
			e[qwq].push_back({a,t+QWQ});
			qwq=a;
			QWQ=t;
		}
	}
	while(p--){
		int x,y;
		cin>>x>>y;
		fill(dist+1,dist+1+n,LLONG_MAX);
		dist[x]=w[x];
		q.push(x);
		while(!q.empty()){
			int h1=q.top();
			q.pop();
			for(auto i:e[h1]){
				int node=i.first;
				int step=i.second;
				if(node==h1&&vis[node]==0)
					if(dist[node]>dist[h1]+step+w[node]){
						dist[node]=dist[h1]+step+w[node];
						q.push(node);
						vis[node]=1;
					}
				else
					if(dist[node]>dist[h1]+step){
						dist[node]=dist[h1]+step;
						q.push(node);
					}	
			}
		}
		cout<<dist[y];
	}
	return 0;
}
