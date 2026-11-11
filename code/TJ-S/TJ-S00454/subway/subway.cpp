#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e6+10,NN=600;

int c,n,m,d,q;
int nxt[N*2],head[N*2],cnt,arr[N],dis[NN][NN],tmp[N],len[N];

struct Edge{
	int u,v,val;
}e[N*2];


void add(int u,int v,int val){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].val=val;
	nxt[cnt]=head[u];
	head[u]=cnt;
	return ;
}

//
//int Dijsktra(int s,int to){
//	priority_queue<P,vector<P>,greater<P> >q;
//	memset(dist,0x3f,sizeof dist);
//	memset(st,0,sizeof st);
//	dist[s]=0;
//	q.push(P{0,s});
//	while(!q.empty()){
//		int x=q.top().second;
//		q.pop();
//		if(st[x])continue;
//		st[x]=1;
//		for(int i=head[x];i;i=nxt[i]){
//			int v=e[i].v,val=e[i].val;
//			if(dist[v]>dist[x]+val){
//				dist[v]=dist[x]+val;
//				q.push(P{dist[v],v});
//			}
//		}
//	}
//	return dist[to];
//}

/*
 0 3 5 20 5 
 4 1 9 2 5 
 3 1 5 2 7 4 6 
 3 2 3 3 4 5 7 
 3 3 1 4 1 5 1
 1 3 
 1 2 
 1 5 
 2 3 
 4 2 
 */
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	memset(dis,0x3f,sizeof dis);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	//cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		scanf("%lld",arr+i);
		//cin>>arr[i];
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int sta=m+1;sta<=m+n;sta++){
		int x;
		scanf("%lld",&x);
		//cin>>x;
		for(int i=1;i<=x;i++){
			int a,t;
			scanf("%lld %lld",&a,&t);
			//cin>>a>>t;
			add(a,sta,t);
			add(sta,a,t);
		}
	}
	for(int j=1;j<=m;j++){
		int tot=0;
		for(int i=head[j];i;i=nxt[i]){
			tmp[++tot]=e[i].v;
			len[tot]=e[i].val;
		}
		for(int i=1;i<=tot;i++){
			for(int k=1;k<=tot;k++){
				int u=tmp[i]-m,v=tmp[k]-m;
				if(u==v)continue;
				else dis[u][v]=dis[v][u]=min(dis[u][v],len[i]+len[k]);
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				//if(dis[u][l]==0x3f3f3f3f3f3f3f3f || dis[l][v]==0x3f3f3f3f3f3f3f3f)continue;
				dis[v][u]=dis[u][v]=min(dis[u][v],dis[u][l]+dis[l][v]);
			}
		}
	}
	while(q--){
		int s,t;
		scanf("%lld %lld",&s,&t);
		//cin>>s>>t;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=head[s];i;i=nxt[i]){
			for(int j=head[t];j;j=nxt[j]){
				int u=e[i].v-m,v=e[j].v-m;
				//cout<<u<<' '<<v<<' '<<dis[u][v]<<' '<<e[i].val<<' '<<e[j].val<<endl;
				ans=min(ans,dis[u][v]+e[i].val+e[j].val);
			}
		}
		printf("%lld\n",ans+arr[s]+arr[t]);
		//cout<<ans+arr[s]+arr[t]<<endl;
	}
	
	
	return 0;
}

