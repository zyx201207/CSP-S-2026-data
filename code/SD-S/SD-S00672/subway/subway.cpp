#include<bits/stdc++.h>
using namespace std;
struct node{
	int v;
	long long w;
};
struct edge{
	long long dis;
	int id;
	bool operator<(const edge &x)const{
		return dis>x.dis;
	}
};
struct qt{
	int x,y,id;
}que[100005];
bool cmp(qt a,qt b){
	return a.x<b.x;
}
const int N=5e5+5,INF=0x3f3f3f3f;
int c,n,m,d,q,a,k[505];
long long dist[N],w[N],t;
vector<node> to[N];
priority_queue<edge> qu;
long long ans[100005];
void di(int x){
	memset(dist,INF,sizeof(dist));
	dist[x]=0;
	qu.push(edge{dist[x],x});
	while (qu.size()){
		long long dis=qu.top().dis,id=qu.top().id;
		qu.pop();
		for (node next:to[id])
			if (dist[next.v]>dis+next.w){
				dist[next.v]=dis+next.w;
				qu.push(edge{dist[next.v],next.v});
			}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for (int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for (int j=1;j<=k[i];j++){
			scanf("%d%lld",&a,&t);
			to[a].emplace_back(node{i+m,t});
			to[i+m].emplace_back(node{a,t});
		}
	}
	for (int i=1;i<=q;i++){
		scanf("%d%d",&que[i].x,&que[i].y);
		que[i].id=i;
	}
	sort(que+1,que+1+q,cmp);
	int l=1;
	while (l<=q){
		di(que[l].x);
		ans[que[l].id]=dist[que[l].y]+w[que[l].x]+w[que[l].y];
		l++;
		while (que[l].x==que[l-1].x&&l<=q){
			ans[que[l].id]=dist[que[l].y]+w[que[l].x]+w[que[l].y];
			l++;
		}
	}
	for (int i=1;i<=q;i++)
		printf("%lld\n",ans[i]);
	return 0;
}
