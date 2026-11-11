#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int N=2e4,inf=0x3f3f3f3f;
long long a[N];

struct Edge{
	int v;
	int pre;
}edge[2*N+10];
int head[N];
int node=0;

void add_edge(int u,int v){
	edge[++node].v=v;
	edge[node].pre=head[u];
	head[u]=node;
}
int t,c;
long long n,d;

long long dist[N];
long long sum[N];
bool st[N];
long long bfs(int s){
	memset(sum,0,sizeof sum);
	memset(dist,inf,sizeof dist);
	long long ans=0;
	queue<int> q;
	dist[s]=0;
	q.emplace(s);
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
	
		for(int i=head[u];i;i=edge[i].pre){
			int v=edge[i].v;
			if(dist[u]+1==dist[v]){
				sum[v]++;
				q.emplace(v);
			}else if(dist[u]+1<dist[v]){
				sum[v]=1;
				dist[v]=dist[u]+1;
				q.emplace(v);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		if(sum[i]==2){
			ans++;
		}
	}
	
	return ans;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
		node=0;
		for(int i=1;i<=n;i++){
			head[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					add_edge(i,j);
				}
			}
		}
		
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=bfs(i);
		}
		cout<<ans/2<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
