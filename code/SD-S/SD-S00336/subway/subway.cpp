#include<bits/stdc++.h>
using namespace std;
bool vis[500010];
int w[500010],a[510][50010],t[510][50010],k[510],dis[500010];
vector <int> ve[500010];
int p(int u,int v,int f){
	priority_queue <pair<int,int>,vector <pair<int,int>>,greater <pair<int,int>>> q;
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	dis[u]=0;
	q.push({0,u});
	while(!q.empty()){
		auto h=q.top().second;
		q.pop();
		if(vis[h]) continue;
		vis[h]=1;
		for(int i=0;i<ve[h].size();i++){
			if(dis[ve[h][i]]>dis[h]+1){
				dis[ve[h][i]]=dis[h]+1;
				q.push({dis[ve[h][i]],ve[h][i]});
			}
		}
	}
	return (dis[v]-1);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,u,v,f,flag=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(j!=1){
				ve[a[i][j-1]].push_back(a[i][j]);
				ve[a[i][j]].push_back(a[i][j-1]);
			}
		}
	}
	f=t[1][1];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			if(t[i][j]!=f){
				break;
				flag=1;
			}
		}
	}
	while(q--){
		cin>>u>>v;
		if(flag==0) cout<<p(u,v,f)<<"\n";
	}
	return 0;
}

