#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505,M=5e5+5,inf=LLONG_MAX/3;
int c,n,m,o,T,x,y,l[N],a[M],t[M],d[N],dis[10][10];
ll w[N],ans,mn=inf;
struct edge{int v,w;};
vector<edge>g[N];
//priority_queue<<pair<int,int>,vector<pair<int,int>>,greater<>>q;
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>o>>T;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		cin>>l[i];
		for(int j=1;j<=l[i];j++){
			cin>>a[j]>>t[j];
		}
		//if(l[i]>1)mn=min(mn,t[1]+t[2]);
		if(n==3){
			if(l[i]==2)
	dis[a[1]][a[2]]=dis[a[2]][a[1]]=min(dis[a[1]][a[2]],t[1]+t[2]);
			if(l[i]==3){
	dis[a[1]][a[2]]=dis[a[2]][a[1]]=min(dis[a[1]][a[2]],t[1]+t[2]);
	dis[a[1]][a[3]]=dis[a[3]][a[1]]=min(dis[a[1]][a[3]],t[1]+t[3]);
	dis[a[2]][a[3]]=dis[a[3]][a[2]]=min(dis[a[2]][a[3]],t[2]+t[3]);			
			}
		}
		else if(7<=c&&c<=11&&l[i]>1){
			g[a[1]].push_back({a[2],t[1]+t[2]});
			g[a[2]].push_back({a[1],t[1]+t[2]});
		}else{
			for(int u=1;u<=l[i];u++){
			for(int v=1;v<=l[i];v++){
				int uu=a[u],vv=a[v];
				g[uu].push_back({vv,t[u]+t[v]});
				g[vv].push_back({uu,t[u]+t[v]});
			}
		}
		}
	}
	while(T--){
		cin>>x>>y;
		if(n==2){
			cout<<w[x]+w[y]+mn<<'\n';
			continue;
		}
		if(n==3){
			int z=1;
			if(x==1&&y==2||x==2&&y==1)z=3;
			if(x==1&&y==3||x==3&&y==1)z=2;
			cout<<w[x]+w[y]+min(dis[x][y],dis[x][z]+dis[z][y])<<'\n';
			continue;
		}
			for(int i=1;i<=n;i++)d[i]=inf;
			cout<<w[x]+w[y]+d[y]<<'\n';
	}
	return 0;
}
