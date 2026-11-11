#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=5005;
int c,t,n,d,a[N],cnt[N][N],dis[N][N],vis[N];
queue<int> q;
struct Edge{
	int to,nxt;
}edge[N<<1];
int head[N],tot;
void add(int u,int v){
	edge[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}
void bfs(int s,int tim){
	dis[s][s]=0;
	cnt[s][s]=1;
	q.push(s);
	while(q.size()){
		int u=q.front();
		q.pop();
		if(vis[u]==tim)continue;
		vis[u]=tim;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[s][v]>dis[s][u]+1){
				dis[s][v]=dis[s][u]+1;
				cnt[s][v]=cnt[s][u];
				q.push(v);
			}
			else if(dis[s][v]==dis[s][u]+1){
				cnt[s][v]+=cnt[s][u];
			}
		}
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	memset(dis,0x3f,sizeof dis);
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					add(i,j);
					add(j,i);
				}
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i,i);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				cout<<i<<" "<<j<<" "<<dis[i][j]<<" "<<cnt[i][j]<<endl;
				if(cnt[i][j]==2){
//					cout<<i<<" "<<j<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
		fill(cnt[0],cnt[n+1],0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=inf;
			}
		}
		tot=0;
		memset(head,0,sizeof head);
		memset(vis,0,sizeof vis);
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
