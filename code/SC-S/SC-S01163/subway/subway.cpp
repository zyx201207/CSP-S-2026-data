#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500010],dis[510][510];
vector<int> tr[510],tim[510];vector<pair<int,int> > sta[500010]; 
inline void getmin(int &u,int v){u=min(u,v);}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)cin>>w[i];
	for(int i = 1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int ai,ti;cin>>ai>>ti;
			tr[i].push_back(ai);tim[i].push_back(ti);
			sta[ai].push_back(make_pair(i,tr[i].size()-1));
		}
	}
	memset(dis,0x3f,sizeof(dis));for(int i = 1;i<=n;i++)dis[i][i]=0; 
	for(int i = 1;i<=m;i++){
		for(auto p1:sta[i])
			for(auto p2:sta[i]){
				int u=p1.first,v=p2.first;
				getmin(dis[u][v],tim[u][p1.second]+tim[v][p2.second]);
				getmin(dis[v][u],tim[u][p1.second]+tim[v][p2.second]);
			}
	}
	for(int k = 1;k<=n;k++)
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(auto p1:sta[x])
			for(auto p2:sta[y]){
				int u=p1.first,v=p2.first;
				ans=min(ans,w[x]+w[y]+tim[u][p1.second]+tim[v][p2.second]+dis[u][v]);
			}	
		cout<<ans<<"\n";	
	}
} 
/*
思路伪了一次，但是这不重要
15:16开写！ 
15:42过小样例
floyd一定是kij!! 
*/