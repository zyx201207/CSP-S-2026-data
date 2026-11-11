#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int N=5e5+10;
int c,n,m,d,qus,pre[N],k;
ll w[N],t[510][1010];
ll dis[1010][1010];
struct node{
	int from,to,next;
	ll len;
}a[4*N];
void add(int u,int v,ll l){
	k++;
	a[k].from=u;
	a[k].to=v;
	a[k].len=l;
	a[k].next=pre[u];
	pre[u]=k;
}
void dijkstra(int s){
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({0,s});dis[s][s]=0;
	while(!q.empty()){
		PII h=q.top();q.pop();
		int u=h.second;
		for(int i=pre[u];i;i=a[i].next){
			int to=a[i].to;
			if(dis[s][to]>dis[s][u]+a[i].len){
				dis[s][to]=dis[s][u]+a[i].len;
				q.push({dis[s][to],to});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=1005;i++){
		for(int j=1;j<=1005;j++)dis[i][j]=1e18;
	}
	memset(t,-1,sizeof(t));
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&qus);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
    	int ki,xi;ll ti;
    	scanf("%d",&ki);
    	for(int j=1;j<=ki;j++){
    		scanf("%d%lld",&xi,&ti);
    		t[i][xi]=ti;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int p=1;p<=m;p++){
				if(t[j][i]!=-1&&t[j][p]!=-1&&i!=p){
					add(i,p,t[j][i]+t[j][p]);
					add(p,i,t[j][i]+t[j][p]);
				}
			}
		}
	}
	for(int i=1;i<=m;i++)dijkstra(i);
	while(qus--){
		int ui,vi;
		scanf("%d%d",&ui,&vi);
		printf("%lld\n",dis[ui][vi]+w[ui]+w[vi]);
	}
	return 0;
}

