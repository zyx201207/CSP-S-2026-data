#include<bits/stdc++.h>
using namespace std;
struct node1{
	int x,dis;
	bool operator <(const node1 a)const{
		return a.dis<dis;
	}
};
struct node{
	int to,nxt,w1,w2,fa;
}a[5000010]; 
priority_queue<node1>q;
int c,n,m,d,T;
int t[500010];
int head[500010];
int k=0;
int ans;
long long dis[500010];
bool v[500010];
int pre[500010];
void add(int x,int y,int w1,int w2,int i){
	a[++k].to=y;
	a[k].nxt=head[x];
	a[k].w1=w1;
	a[k].w2=w2;
	a[k].fa=i;
	head[x]=k;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>T;
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
	}
	for(int i=1;i<=m;i++){
		int k; 
		scanf("%d",&k);
		int x,t0;
		scanf("%d%d",&x,&t0);
		for(int j=2;j<=k;j++){
			int prex=x,pret=t0;
			scanf("%d%d",&x,&t0);
			add(x,prex,t0,pret,i);
			add(prex,x,pret,t0,i);
		}
	}
	a[0].fa=0;
	while(T--){
		memset(dis,0x7f,sizeof(dis));
		memset(v,0,sizeof(v));
		memset(pre,0,sizeof(pre));
		int s,e;
		cin>>s>>e;
		node1 tmp;
		tmp.x=s;
		dis[s]=0;
		tmp.dis=dis[s];
		q.push(tmp);
		ans=t[s]+t[e];
		while(!q.empty()){
			node1 h=q.top();
			q.pop();
			int x=h.x;
			v[x]=1;
			for(int i=head[x];i!=0;i=a[i].nxt){
				int y=a[i].to;
				if(v[y]==0){
					if(a[i].fa==a[pre[x]].fa){
						if(dis[y]>dis[x]-a[pre[x]].w2+a[i].w2){
							dis[y]=dis[x]-a[pre[x]].w2+a[i].w2;
							node1 tmp;
							tmp.x=y;
							tmp.dis=dis[y];
							q.push(tmp);
							pre[y]=i;
						}
					}else{
						if(dis[y]>dis[x]+a[i].w1+a[i].w2){
							dis[y]=dis[x]+a[i].w1+a[i].w2;
							pre[y]=i;
							node1 tmp;
							tmp.x=y;
							tmp.dis=dis[y];
							q.push(tmp);
						}
						for(int j=head[y];j!=0;j=a[j].nxt){
							if(v[a[j].to]==0&&a[j].fa==a[i].fa&&dis[y]+a[j].w1>dis[x]+a[i].w1){
								pre[y]=i;
								dis[a[j].to]=dis[x]+a[i].w1+a[j].w2;
								node1 tmp;
								tmp.x=a[j].to;
								tmp.dis=dis[a[j].to];
								q.push(tmp);
								pre[a[j].to]=j;
							}
						}
					}
				}
			}
		}
		printf("%lld\n",dis[e]+ans);
	}
	return 0;
}
