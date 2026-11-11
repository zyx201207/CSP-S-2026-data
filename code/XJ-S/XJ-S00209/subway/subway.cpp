#include<bits/stdc++.h>
using namespace std;
const int N=3e6+5;
const long long inf=1e17+8;
int to[N],net[N],head[N],p,c,n,m,d,q,ci[N],pc[N],used[N];
long long dis[N];
struct node{
	long long b,c;
};
priority_queue<node> qq;
bool operator <(node x,node y){
	return x.c>y.c;
}
void djsktra(int s){
	for(int i=1;i<=m+n;i++){
		dis[i]=inf;
		used[i]=0;
	}
	qq.push((node){s,0});
	used[s]=1;
	dis[s]=0;
	while(!qq.empty()){
		node u=qq.top();
		qq.pop();
		for(int i=head[u.b];i;i=net[i]){
			int v=to[i];
			if(!used[v]){
				dis[v]=min(dis[v],dis[u.b]+ci[i]);
				qq.push((node){v,ci[i]});
				used[v]=1;
			}
		}
	}
}
void addedge(int a,int b,int cc){
	to[++p]=b;
	net[p]=head[a];
	head[a]=p;
	ci[p]=cc;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>pc[i];
	}
	for(int i=1;i<=n;i++){
		int k,cc,x;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>cc;
			addedge(m+i,x,cc);
			addedge(x,m+i,cc);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		djsktra(x);
		cout<<pc[x]+pc[y]+dis[y]<<endl;
	}
	return 0;
} 
