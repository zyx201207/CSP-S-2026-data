#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
int n;
long long d;
long long a[N];
int dis[N][3];
void bfs(int s){
	for(int i=1;i<=n;i++){
		dis[i][0]=dis[i][1]=dis[i][2]=N;
	}
	queue<pair<int,int>> q;
	q.push({s,0});
	dis[s][0]=0;
	while(!q.empty()){
		auto it=q.front();q.pop();
		int u=it.first,id=it.second;
		for(int i=u+1;i<=n;i++)if(a[i]-a[u]<=d){
			if(dis[u][id]+1<dis[i][0]){
				dis[i][2]=dis[i][1];
				dis[i][1]=dis[i][0];
				dis[i][0]=dis[u][id]+1;
				q.push({i,0});
			}else if(dis[u][id]+1<dis[i][1]){
				dis[i][2]=dis[i][1];
				dis[i][1]=dis[u][id]+1;
				q.push({i,1});
			}else if(dis[u][id]+1<dis[i][2]){
				dis[i][2]=dis[u][id]+1;
				q.push({i,2});
			}
		}
	}
}
void solve(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++)if(dis[j][0]==dis[j][1]&&dis[j][1]!=dis[j][2]){
//			printf("%d %d\n",i,j);
			ans++;
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		solve();
	}
	return 0;
}
