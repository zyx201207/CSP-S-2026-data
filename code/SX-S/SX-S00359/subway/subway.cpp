#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int N=600,M=5e5+10;
int t,n,m,d,qq;
ll w[N];
struct Node{
	int from,to,next;
	ll len;
}a[N*M];
int k,pre[N*M];
void add(int u,int v,ll len){
	a[++k]={u,v,pre[u],len};
	pre[u]=k;
}
ll dis[N*M];
bool f[N*M];
priority_queue<PII,vector<PII>,greater<PII>> q;
void djstl(int x){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(f,false,sizeof(f));
	while(!q.empty()) q.pop();
	q.push({0,x});
	dis[x]=0;
	while(!q.empty()){
		PII h=q.top();
		q.pop();
		int p=h.second;
		if(f[p]) continue;
		f[p]=true;
		for(int i=pre[p];i;i=a[i].next){
			int to=a[i].to,len=a[i].len;
			if(dis[p]+len<dis[to]&&!f[to]){
				dis[to]=dis[p]+len;
				q.push({dis[to],to});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&t,&n,&m,&d,&qq);
	if(t==0) t++;
	int kk,x;
	ll y;
	while(t--){
		k=0;
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=m;i++){
			scanf("%lld",&w[i]);
		}
		int last;
		for(int i=1;i<=n;i++){
			scanf("%d",&kk);
			last=0;
			for(int j=1;j<=kk;j++){
				scanf("%d%lld",&x,&y);
				add(x,i*m+x,y);
				add(i*m+x,x,y);
				if(j>1){
					add(last,i*m+x,0);
					add(i*m+x,last,0);
				}
				last=i*m+x;
			}
		}
		int x1,y1;
		while(qq--){
			scanf("%d%d",&x1,&y1);
			djstl(x1);
			printf("%lld\n",dis[y1]+w[x]+w[y]);
		}
	}
	return 0;
}
