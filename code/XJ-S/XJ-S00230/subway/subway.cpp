#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int c,n,m,d,q,st,ed,w[N],dis[N],vis[N];
struct node{
	int v,w;
};
vector<node>e[N];
vector<int>p[N];
void dfs(int now,int Dis){
	if(dis[now]<=Dis)return;
	dis[now]=Dis;
	int len=p[now].size();
	for(int x=0;x<len;x++){
		int pos=p[now][x];
		int Len=e[pos].size();
		for(int j=0;j<Len;j++){
			int v=e[pos][j].v,w=e[pos][j].w+e[pos][now].w;
			if(v==now)continue;
			dfs(v,Dis+w);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			e[i].push_back({a,t});
			p[a].push_back(i);
		}
	}
	while(q--){
		cin>>st>>ed;
		for(int i=1;i<=m;i++)dis[i]=1e9;
		dfs(st,0);
		cout<<dis[ed]+w[st]+w[ed]<<'\n';
	}
	return 0;
} 
