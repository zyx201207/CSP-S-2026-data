#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int head[N],tot,ans;
struct Edge{
	int to,nxt;
}edge[N<<2];
void add(int x,int y){
	edge[++tot]={y,head[x]};
	head[x]=tot;
}
struct Jj{
	int pair[N];
};
int a[N],d,c,t,n;
void Bfs(int *dist,int x){
	queue<int> q;
	q.push(x);
	dist[x]=1;
	while(!q.empty()){
		int te=q.front();q.pop();
		for(int t=head[te];~t;t=edge[t].nxt){
			int to=edge[t].to;
			dist[to]++;
			q.push(to);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		tot=0,ans=0;
		cin>>n>>d;
		vector<int> dist(n);
		memset(head,-1,4*(n+1));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d) add(a[i],a[j]);
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			dist.clear();
			Bfs(dist.data(),a[i]);
			for(int j=1;j<=n;j++){
				if(dist[j]==2){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
