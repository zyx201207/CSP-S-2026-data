#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,INF=1e9+5;
int c,n,m,d,Q,a[N],k,U[N],V[N],dis[N],last_point,ans[N];
bool vis[N];
struct edge{
	int u,v,w;
	bool operator<(const edge &i)const{
		return w>i.w;
	}
}q[N];
priority_queue<edge> que;
vector<edge> e[N];
bool cmp_query(edge i,edge j){return i.u<j.u;}
void init(){
	for(int i=1;i<=m;i++) vis[i]=0;
	for(int i=1;i<=m;i++) dis[i]=INF;
}
void dijkstra(int x){
	priority_queue<edge> que;
	dis[x]=0;
	vis[x]=1;
	for(edge i:e[x]){
		int v=i.v,w=i.w;
		dis[v]=dis[x]+w;
		que.push(i);
	}
	while(!que.empty()){
		int u=que.top().v;
		que.pop();
		if(vis[u]) continue;
		vis[u]=1;
		//cout<<u<<' ';
		for(edge i:e[u]){
			int v=i.v,w=i.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				que.push(i);
			}
		}
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
    	cin>>k;
    	for(int j=1;j<=k;j++) cin>>U[j]>>V[j];
    	for(int p=1;p<k;p++){
    		for(int q=p+1;q<=k;q++){
    			int st1=U[p],st2=U[q];
    			int cost=V[p]+V[q];
    			e[st1].push_back({st1,st2,cost});
    			e[st2].push_back({st2,st1,cost});
			}
		}
	}
	for(int i=1;i<=Q;i++){
		cin>>q[i].u>>q[i].v;
		q[i].w=i;
	}
	sort(q+1,q+Q+1,cmp_query);
	for(int question_id=1;question_id<=Q;question_id++){
		int x=q[question_id].u,y=q[question_id].v,id=q[question_id].w;
		if(x!=last_point){
			init();
			dijkstra(x);
			last_point=x;
			//for(int i=1;i<=m;i++) cout<<dis[i]<<' ';cout<<endl;
		}
		ans[id]=a[x]+a[y]+dis[y];
	}
	for(int i=1;i<=Q;i++) cout<<ans[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
