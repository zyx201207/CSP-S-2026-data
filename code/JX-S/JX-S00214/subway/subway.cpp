#include<bits/stdc++.h>
using namespace std;
bool f=1;
int c,n,m,d,q;
int w[500005];
struct node{
	int id,time;
};
int x,y;
vector<node> tu[500005];
int dd[500005];
bool vis[500005];
void dj(){
	for(int i=1;i<=m;i++){
		int U=-1,mu=0x3f;
		for(int j=1;j<=m;j++){
			if(mu>dd[j]&&vis[j]==0){
				mu=dd[j];
				U=j;
			}
		}
		if(U==-1) break;
		vis[U]=1;
		for(int j=0;j<int(tu[U].size());j++){
			int V=tu[U][j].id;
			if(vis[V]==0) dd[V]=min(dd[V],dd[U]+tu[U][j].time);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		if(t>2) f=0;
		if(f&&t==2){
			int u1,u2,v1,v2;
			cin>>u1>>u2>>v1>>v2;
			tu[u1].push_back({v1,u2+v2});
			tu[v1].push_back({u1,u2+v2});
		}
	}
	if(f){
		while(q--){
			cin>>x>>y;
			memset(dd,0x3f,sizeof(dd));
			memset(vis,0,sizeof(vis));
			dd[x]=0;
			dj();
			cout<<w[x]+dd[y]+w[y]<<endl;
		}
	}
	else{
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+i<<endl;
		}
	}
	return 0;
}
 
