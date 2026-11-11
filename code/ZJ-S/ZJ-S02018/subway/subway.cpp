#include<bits/stdc++.h> 
using namespace std;
const int M=500005;
const int N=505;
const long long oo=1e18+5;
struct node{
	long long w;
	int v;
};
long long dis[M+N],W[M];
vector<node>vec[M+N];
int c,m,n,d,Q,ans;
int k[N];
bool used[M];
priority_queue<int> q; 
void Dijkstra(int x){
	for(int i=1;i<=m+n;i++)dis[i]=oo,used[i]=false;
	dis[x]=0;q.push(x);used[x]=true;
	while(!q.empty()){
		int u=q.top();q.pop();used[u]=false;
		for(node e:vec[u]){
			int v=e.v;
			long long ww=e.w;
			if(dis[v]>dis[u]+ww){
				dis[v]=dis[u]+ww;
				if(!used[v]){
					q.push(v);
					used[v]=true;
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++)scanf("%lld",&W[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int a,t;
			scanf("%d%d",&a,&t);
			vec[m+i].push_back({t,a});
			vec[a].push_back({t,m+i});
		}
	}
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		Dijkstra(x);
		printf("%lld\n",dis[y]+W[x]+W[y]);
	}
	return 0;
}
