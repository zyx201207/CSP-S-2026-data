#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void out(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)out(x/10),putchar((x%10)+'0');
	else putchar(x+'0');
}
ll c,n,m,D,Q;
struct edge{
	ll v,w;
};
vector<edge>e[500505];
ll val[500505];
bool vis[500505];
ll d[500505];
struct node{
	ll u,d;
};
bool operator<(node x,node y){
	return x.d>y.d;
}
priority_queue<node>q;
ll ask(ll x,ll y){
	while(q.size())q.pop();
	for(int i=1;i<=n+m;i++)d[i]=(1ll<<60),vis[i]=0;
	d[x]=0;
	q.push((node){x,0});
	while(q.size()){
		ll u=q.top().u;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			ll v=e[u][i].v,w=e[u][i].w;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				if(v==y)return d[y];
				q.push((node){v,d[v]});
			}
		}
	}
	return d[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	D=read();
	Q=read();
	for(int i=1;i<=m;i++)val[i]=read();
	for(int x=1;x<=n;x++){
		ll k=read();
		for(int i=1;i<=k;i++){
			ll a=read(),t=read();
			e[a].push_back((edge){x+m,t});
			e[x+m].push_back((edge){a,t});
		}
	}
	while(Q--){
		ll x=read(),y=read();
		out(ask(x,y)+val[x]+val[y]);
		putchar('\n');
	}
	return 0;
}
