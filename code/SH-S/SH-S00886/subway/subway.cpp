#include <bits/stdc++.h>
using namespace std;
priority_queue< pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int dis[500010],vis[500010],c,n,m,d,r,t[500010];
vector<pair<int,int> > v[500010],vv[500010];
void dij(int s,int e){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push({0,s});
	dis[s]=0;
	while(q.size()){
		int mi=q.top().second;
		q.pop();
		if(vis[mi])continue;
		vis[mi]=1;
		for(int i=0;i<v[mi].size();i++){
			int t=v[mi][i].first,w=v[mi][i].second;
			if(!vis[t] && dis[t]>dis[mi]+w){
				dis[t]=dis[mi]+w;
				if(t==e)return ;
				q.push({dis[t],t});
			}
		} 
	}
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			vv[i].push_back({a,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<vv[i].size();j++){
			for(int k=0;k<vv[i].size();k++){
				if(k==j)continue;
				v[vv[i][j].first].push_back({vv[i][k].second,vv[i][k].first});
				v[vv[i][k].first].push_back({vv[i][j].second,vv[i][j].first});
			}
		}
	}
	for(int i=1;i<=r;i++){
		int s,e;cin>>s>>e;
		dij(s,e);
		cout<<dis[e]+t[s]+t[e]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
