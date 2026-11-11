#include<bits/stdc++.h>
#define int long long
#define inf (1e18+7)
#define pii pair<int,int>
using namespace std;
int c,n,m,d,Q,dis[505][505],t[505][505],w[505],k[505],vis[505][505];
set<int> s[505];
queue<pii > q;
void bfs(int st,int ed,int tim){
//	cout<<"bfs:"<<tim<<endl;
	for(auto num:s[st]){
		dis[st][num]=w[st]+t[st][num];
		q.push({st,num});
	}
	while(q.size()){
		int u=q.front().first,lst=q.front().second;
		q.pop();
		if(vis[u][lst]==tim)continue;
		vis[u][lst]=tim;
//		cout<<u<<" "<<lst<<" "<<dis[u][lst]<<endl; 
		if(u==ed)continue;
		for(int v=1;v<=m;v++){
			if(s[v].find(lst)==s[v].end())continue;
			for(auto now:s[v]){
				if(now==lst){
					if(dis[v][now]>dis[u][lst]){
						dis[v][now]=dis[u][lst];
						q.push({v,now});
					}
				}
				else{
					if(dis[v][now]>dis[u][lst]+t[v][lst]+t[v][now]){
						dis[v][now]=dis[u][lst]+t[v][lst]+t[v][now];
						q.push({v,now});
					}
				}
				
			}
		}
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			s[x].insert(i);
			t[x][i]=y;
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<":\n";
//		for(auto num:s[i]){
//			cout<<num<<" "<<t[i][num]<<endl;
//		}
//	}
	int tim=0;
	while(Q--){
		int st,ed;
		tim++;
		memset(dis,0x3f,sizeof dis);
		cin>>st>>ed;
		bfs(st,ed,tim);
		int ans=inf;
		for(auto num:s[ed]){
			ans=min(ans,dis[ed][num]+t[ed][num]+w[ed]);
		}
		cout<<ans<<'\n';
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
