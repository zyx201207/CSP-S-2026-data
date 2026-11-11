#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,M=2e6+5;
int head[N],nxt[M],to[M],tot,cnt;ll edge[M];
ll dist[N];
bool v[N];
int c_,n,m,q_,d;
int a,b,o,k_,w;
priority_queue <pair <ll,int> > q;
inline int in(){
	int k=0;
	char c=getchar();
	while(c>='0' && c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k;
}
inline out(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
}
void dfs(int s,int op){
	for(int i=1;i<=cnt;i++) dist[i]=0x3f3f3f3f,v[i]=0;
	dist[s]=0;
	q.push(make_pair(0,s));
	while(q.size()){
		int x=q.top().second;q.pop();
		if(v[x]){
			if(x==op){
				return;
			}
			continue;
		}
		v[x]=1;
		for(int i=head[x];i;i=nxt[i]){
			int y=to[i],z=edge[i];
			if(dist[y]>dist[x]+z){
				dist[y]=dist[x]+z;
				q.push(make_pair(-dist[y],y));
			}
		}
	}
}
void add(int x,int y,ll z){
	to[++tot]=y;nxt[tot]=head[x];head[x]=tot;edge[tot]=z;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c_=in();n=in();m=in();d=in();q_=in();cnt=2*m;
	for(int i=1;i<=m;i++){
		w=in();
		add(i,i+m,(ll)w);add(i+m,i,(ll)w);
	}
	for(int i=1;i<=n;i++){
		k_=in();
		for(int j=1;j<=k_;j++){
			a=in();b=in();
			add(++cnt,a+m,(ll)b);
			add(a+m,cnt,(ll)b);
			if(j>=2){
				add(cnt,o,0ll);
				add(o,cnt,0ll);
			}
			o=cnt;
		}
	}
	for(int i=1;i<=q_;i++){
		a=in();b=in();
		dfs(a,b);
		out(dist[b]);puts("");
	}
	return 0;
}
