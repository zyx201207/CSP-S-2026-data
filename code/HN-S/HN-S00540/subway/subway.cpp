#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005],t[500005],vv[500005],x,y,k,vis[500005];
vector<int> ve[500005],wi[500005];
void spfa(int x,int s){
	memset(vis,0x3f,sizeof(vis));
	vis[x]=0;
	queue<int> q;
	q.push(x);
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=0;i<ve[u].size();i++){
			int v=ve[u][i];
			int w=wi[u][i];
			if(vis[v]>vis[u]+w){
				q.push(v);
				vis[v]=vis[u]+w;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			scanf("%d%d",&vv[j],&t[j]);
		}
		for(int j=1;j<k;j++){
			for(int o=j+1;o<=k;o++){
				ve[vv[j]].push_back(vv[o]);
				ve[vv[o]].push_back(vv[j]);
				wi[vv[j]].push_back(t[j]+t[o]);
				wi[vv[o]].push_back(t[o]+t[j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int ans=0;
		spfa(x,0);
		cout<<vis[y]+a[x]+a[y]<<'\n';
	}
	return 0;
}
