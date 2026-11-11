#include<bits/stdc++.h>
using namespace std;
int c,t,n,head[2000005],tot,dis[2000005],cnt[2000005],ans;
long long d,x[2000005];
struct Num{
	int to,nxt;
}a[50000005];
void add(int u,int v){
	a[++tot].to=v;
	a[tot].nxt=head[u];
	head[u]=tot;
}
void bfs(int s){
	for(int i=1;i<=n;i++){
		cnt[i]=0;
		dis[i]=1e9;
	}
	queue<int> q;
	dis[s]=0;
	cnt[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=a[i].nxt){
			int to=a[i].to;
			if(dis[to]>=dis[x]+1){
				dis[to]=dis[x]+1;
				cnt[to]++;
				q.push(to);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		tot=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(abs(x[i]-x[j])<=d){
					add(i,j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(cnt[j]==2){
					ans++;
				} 
			}
		}
		printf("%d\n",ans/2);
	}
	return 0;
}
