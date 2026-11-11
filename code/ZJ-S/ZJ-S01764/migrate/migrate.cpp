#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5010,MAXM=3e7+10,INF=1e18;
int c,t,n,d,a[MAXN],dis[MAXN],vis[MAXN],ans[MAXN],cnt; 
int head[MAXN],tot;
struct edge{
	int to,nxt;
}e[MAXM<<1];
void add(int u,int v){
	e[++tot].to=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}
void clear(){
	for(int i=1;i<=tot;i++){
		e[i]={0,0};
	}
	tot=0;cnt=0;
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
}
void solve(int x){
	for(int i=1;i<=n;i++){
		dis[i]=INF;
		vis[i]=ans[i]=0;
	}
	dis[x]=0;
	ans[x]=1;
	priority_queue<pair<int,int> >q;
	q.push({0,x});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(vis[v]||v<u)continue;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				ans[v]=ans[u];
				q.push({-dis[v],v});
			}
			else if(dis[v]=dis[u]+1){
				ans[v]+=ans[u];
			}
		}
	} 
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	while(t--){
		clear();
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]+d>=a[j]){
					add(i,j);
					add(j,i);
				}
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			int root=i;
			solve(i);
			for(int j=i+1;j<=n;j++){
				if(ans[j]==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

out:
1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

out:
0
1
*/
