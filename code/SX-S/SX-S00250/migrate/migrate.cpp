#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
struct node{
	int to,nxt;
}e[90009];
int n,cnt,tot,head[N],C[N];
ll d,a[N],dist[N];
bool vis[N];
void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void dij(int st){
	fill(dist+1,dist+n+1,LLONG_MAX);
	fill(vis+1,vis+n+1,0);
	priority_queue<pair<ll,int> > q;
	dist[st]=0;
	vis[st]=1;
	q.push({0,st});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(!vis[v]&&dist[v]>dist[u]+1){
				dist[v]=dist[u]+1;
				vis[v]=1;
				q.push({-dist[v],v});
			}
		}
	}
}
void Clear(){
	memset(e,0,sizeof e);
	memset(head,0,sizeof head);
	cnt=0;
}
void dfs(int u,int now,int ed,int goal,int fa){
	if(tot>2) return;
	if(now>goal) return;
	if(u==ed){
		tot++;
		return;
	}
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,now+1,ed,goal,u);
	}
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
//	freopen("migrate3.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		Clear();
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
//			for(int j=i-1;j>=1;j--)
//				if(a[i]-a[j]<=d) add(i,j),add(j,i);
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d){
//					if(i==1&&j==2) cout<<"!!!!";
					add(i,j),add(j,i);
				}
		}
//		cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<'\n';
		int ans=0;
		for(int i=1;i<n;i++){
			dij(i);
			for(int j=i+1;j<=n;j++){
				if(dist[j]==LLONG_MAX) break;//¶ÏÁª
//				fill(C+1,C+n+1,0);
				tot=0;
				dfs(i,0,j,dist[j],0);
				if(tot==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4

5 2
1 2 3 4 5

ans:
1
2

*/