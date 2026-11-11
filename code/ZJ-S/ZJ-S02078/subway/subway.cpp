#include<bits/stdc++.h>
//#define int long long
#define PII pair<int,int>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,len;
int w[M],k[N],a[N][N],t[N][N];
int dis[M*10];
bool vis[M*10];
vector<PII>g[M*10];
void spfa(int st,int en){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(st);
	dis[st]=0;
	vis[st]=1;
	while(!q.empty()){
		int u=q.front();q.pop();vis[u]=0;
		for(auto t:g[u]){
			int v=t.first;
			int w=t.second;
			
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	cout<<dis[en]<<"\n";
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		g[i].push_back({i+m,w[i]});
		g[i+m].push_back({i,w[i]});
		
//		cout<<i<<" "<<i+m<<" "<<w[i]<<"\n";
	}
	len=2*m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			
			int ting=a[i][j]+m,tai= ++len,lstai=len-1;
			g[ting].push_back({tai,t[i][j]});
			g[tai].push_back({ting,t[i][j]});
			
//			cout<<ting<<" "<<tai<<" "<<t[i][j]<<"\n";
			
			if(j!=1){
				g[lstai].push_back({tai,0});
				g[tai].push_back({lstai,0});
//				cout<<lstai<<" "<<tai<<" "<<t[i][j]<<"\n";
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		spfa(x,y);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/