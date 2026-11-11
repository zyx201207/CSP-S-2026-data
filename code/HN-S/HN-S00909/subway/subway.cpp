#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int,pair<int,int> >
const int maxn=510;
const int maxm=5e5+10;
int c,n,m,d,q;
vector<int>a[maxn],t[maxn];
int w[maxm];
int k[maxn];
struct node{
	int v,w;
};
vector<node>b[maxm];
bool vis[maxm];
int dis[maxm];

void dij(int s){
	for(int i=1;i<=m;i++){
		dis[i]=1e18;
		vis[i]=0;
	}
	priority_queue<pll,vector<pll>,greater<pll> >q;
	q.push({0,{s,0}});
	dis[s]=0;
	while(q.size()){
		int u=q.top().second.first;
		int pos=q.top().second.second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<b[u].size();i++){
			int pp=b[u][i].v;
			int w1=b[u][i].w;
			for(int j=1;j<=k[pp];j++){
				int v=a[pp][j];
				int w2=t[pp][j];
				if(pos!=pp){
					if(dis[u]+w1+w2<dis[v]){
						dis[v]=dis[u]+w1+w2;
						q.push({dis[v],{v,pp}});
					}
				}else{
					if(dis[u]+w2<dis[v]){
						dis[v]=dis[u]+w2;
						q.push({dis[v],{v,pp}});
					}
				}
			}
		}
	}
}

int dd[1010][1010];
void solve1(){
	for(int i=1;i<=m;i++){
		dij(i);
		for(int j=1;j<=m;j++){
			dd[i][j]=dis[j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dd[x][y]<<"\n";
	}
}
void solve2(){
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<w[x]+w[y]+dis[y]<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+2);
		t[i].resize(k[i]+2);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			b[a[i][j]].push_back({i,t[i][j]});
		}
	}
	if(c<=11){
		solve1();
	}else{
		solve2();
	}
	return 0;
}

