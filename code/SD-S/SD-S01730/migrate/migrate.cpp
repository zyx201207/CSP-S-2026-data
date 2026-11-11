#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n;
long long d;
long long a[N];
int head[N],ver[N],nt[N],tot;
void add(int x,int y){
	ver[++tot]=y;
	nt[tot]=head[x];
	head[x]=tot;
}

int dist[N],vis[N],cnt[N];

long long djsk(int s){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	priority_queue <pair<int,int> > q;
	q.push({0,s});
	dist[s]=0;
	cnt[s]=1;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=nt[i]){
			int y=ver[i];
			if(vis[y]) continue;
			if(dist[y]>dist[x]+1){
				dist[y]=dist[x]+1;
				cnt[y]=cnt[x];
				q.push({-dist[y],y});
			}
			else if(dist[y]==dist[x]+1){
				cnt[y]+=cnt[x];
				q.push({-dist[y],y});
			}
			
		}
	}
	long long ans=0;
	for(int i=s+1;i<=n;i++){
		if(cnt[i]==2){
			ans++;
		} 
	}
	return ans;
}
int main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	scanf("%d%d",&C,&T);
	while(T--){
		tot=0;
		memset(head,0,sizeof(head));
		memset(nt,0,sizeof(nt));
		memset(ver,0,sizeof(ver));
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",a+i);
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d) break;
				add(i,j);
			}
		}
		long long aaa=0;
		for(int i=1;i<n;i++){
			aaa+=djsk(i);
		}
		printf("%lld\n",aaa);
	}
	return 0;
} 
