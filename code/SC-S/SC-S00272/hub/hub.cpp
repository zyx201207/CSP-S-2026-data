#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005,M=3005;
int head[N],nxt[M],to[M],tot,cnt;ll edge[M];
int dist[N],st[N],ans=0x3f3f3f3f;
bool v1[N],v[N],dfn[N];
int c,t,n,k,num;
priority_queue <pair <int,int> > q;
inline int in(){
	int f=1,k=0;
	char c=getchar();
	while(c>'9' || c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
inline out(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
}
void dfs(int x){
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(!v1[y] || dfn[y]) continue;
		dfn[y]=1;
		dfs(y);
	}
}

void dij(int s){
	for(int i=1;i<=n;i++) v[i]=0;
	dist[s]=0;
	q.push(make_pair(0,s));
	while(q.size()){
		int x=q.top().second;q.pop();
		if(v[x]) continue;
		v[x]=1;
		for(int i=head[x];i;i=nxt[i]){
			int y=to[i],z=1;
			if(dist[y]>dist[x]+z){
				dist[y]=dist[x]+z;
				q.push(make_pair(-dist[y],y));
			}
		}
	}
}
void init(){
	for(int i=1;i<=n;i++) head[i]=0;
	tot=0;ans=0x3f3f3f3f;
//	cout<<'\n';
}
void add(int x,int y){
	to[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int a,b;scanf("%d%d",&a,&b);
			add(a,b);add(b,a); 
		}
		for(int i=0;i<(1<<n);i++){
			if(__builtin_popcount(i)==k){
//				cout<<i<<'\n';
				for(int j=1;j<=n;j++){
					dfn[j]=0;
					if((i>>(j-1))&1) v1[j]=1;
					else v1[j]=0;
//					cout<<v1[j]<<" "<<j<<endl;
				}
				int ret=0;
				for(int j=1;j<=n;j++){
					if(v1[j]&&(!dfn[j])){
						dfn[j]=1;
						dfs(j);
						ret++;st[ret]=j;
					}
				}
				if(ret>2||ret==0) continue;
				num=0;
				for(int j=1;j<=n;j++) dist[j]=0x3f3f3f3f;
				for(int j=1;j<=n;j++){
					if(v1[j]) dij(j);
				}
				for(int j=1;j<=n;j++){
//					cout<<dist[j]<<'\n';
					num=max(num,dist[j]);
				}
//				cout<<num<<" ";
				ans=min(ans,num); 
			}
		}
		printf("%d\n",ans);
		init();
	}
	return 0;
}
