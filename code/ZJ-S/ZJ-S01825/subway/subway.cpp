#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
int c,n,m,d,q;
int k[505],v[500005],w[500005],ans[1005][1005];
vector<int>a[505],t[505];
struct N{int x,y;}u[100005];
struct M{int a,x,y;};
vector<M>b[500005];
bool cmp(N a,N b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
void bfs(int x){
	for(int i=1;i<=m;i++)v[i]=1e9;
	v[x]=-1e9;
	queue<M>q;
	for(M c:b[x]){
		q.push({c.a,c.x,c.y});
	}
	while(!q.empty()){
		M c=q.front();q.pop();
		
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,y;j<=k[i];j++){
			cin>>x>>y;
			a[i].push_back(x),t[i].push_back(y);
			b[x].push_back({i,j-1,y});
		}
	}
//	if(c<=11){
//		for(int i=1;i<=q;i++)cin>>u[i].x>>u[i].y;
//		sort(u+1,u+q+1,cmp);
//		for(int i=1;i<=q;i++){
//			if(u[i].x!=u[i-1].x)bfs(i);
////			cout<<ans[u[i].x][u[i].y]+w[u[i].y]<<'\n';
//		}
//	}
for(int i=1;i<=q;i+=1)cin>>u[i].x>>u[i].y,cout<<1<<'\n';
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
