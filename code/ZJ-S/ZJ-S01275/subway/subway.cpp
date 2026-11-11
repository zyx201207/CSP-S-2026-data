#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int M=5e5+5,inf=0x3f3f3f3f3f3f3f3f/2;
struct node{
	int x;
	int y;
	bool operator <(const node &a)const{
		return y<a.y;
	}
};
int c,n,m,d,T;
bool vis[N];
int dis[N],ans[N][N],ed[N][N];
int tim[M];
vector<node>wh[M],e[N];
priority_queue<node>q;
void dijstra(int st){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[st]=0;
	q.push(node{st,0});
	while(!q.empty()){
		int now=q.top().x;
		q.pop();
		if(vis[now]){
			continue;
		}
		vis[now]=1;
		for(node i:e[now]){
			if(dis[i.x]>dis[now]+i.y){
				dis[i.x]=dis[now]+i.y;
				q.push(node{i.x,dis[i.x]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans[st][i]=dis[i];
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>tim[i];
	}
	for(int i=1;i<=n;i++){
		int fu;
		cin>>fu;
		for(int j=1;j<=fu;j++){
			int x,y;
			cin>>x>>y;
			node now={i,y};
			wh[x].push_back(now);
		}
	}
	memset(ed,0x3f,sizeof ed);
	memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=m;i++){
		for(node j:wh[i]){
			for(node k:wh[i]){
				ed[j.x][k.x]=min(ed[j.x][k.x],j.y+k.y);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			if(ed[i][j]<inf){
				node now={j,ed[i][j]};
				e[i].push_back(now);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dijstra(i);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<ans[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	while(T--){
		int st,en;
		cin>>st>>en;
		int res=inf;
		for(node j:wh[st]){
			for(node k:wh[en]){
				res=min(res,ans[j.x][k.x]+j.y+k.y);
			}
		}
		cout<<res+tim[st]+tim[en]<<'\n';
	}
	return 0;
}
