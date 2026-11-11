#include<bits/stdc++.h>
#define ll int
using namespace std;
const ll M=5e5+10,N=500+10;
ll c,m,n,d,q;
ll w[M],k[N];
vector<ll> a[N],t[N];
// belong: 第 i 个点属于 belong[i] 线路里面的站点
// belong_i: 第 i 线路中 belong_i[i] 站点的位置 
struct Edge{
	ll nxt,to,dis;
}edge[M+2*N];
struct Que{
	ll val,idd,u,v;
}que[M];
ll head[M+2*N],cnt;
void add(ll from,ll to,ll dis){
	cnt++;
	edge[cnt].nxt=head[from];
	edge[cnt].to=to,edge[cnt].dis=dis;
	head[from]=cnt;
	return;
}
bool vis[M+2*N];
ll dis[M+2*N];
#define pll pair<ll,ll> 
void dijskra(ll st){
	priority_queue<pll,vector<pll>,greater<pll> > q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	q.push(make_pair(0,st));
	dis[st]=0;
	while(q.size()){
		ll x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		for(ll i=head[x];i;i=edge[i].nxt){
			ll y=edge[i].to;
			ll d=edge[i].dis;
			if(dis[y]>dis[x]+d){
				dis[y]=dis[x]+d;
				q.push(make_pair(dis[y],y));
			}
		}
	}
	return;
}
// 1~n : n 条线路的缩点
// n+1~n+m : m 个虚拟点 (作为中转站，与含有点线路链接，为t)
bool cmp(Que a,Que b){
	return a.u<b.u;
}
bool cmp2(Que a,Que b){
	return a.idd<b.idd;
}
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0),cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(ll i=1;i<=m;i++) w[i]=read();
	for(ll i=1;i<=n;i++){
		ll aa,tt;
		k[i]=read();
		for(ll j=1;j<=k[i];j++){
			aa=read(),tt=read();
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	} 
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<k[i];j++){
			add(m+i,a[i][j],t[i][j]);
			add(a[i][j],m+i,t[i][j]);
			//cout<<"< "<<m+i<<" , "<<a[i][j]<<" >  "<<t[i][j]<<"\n";
		}
	}
	//cout<<"<\n";
	//dijskra(1);
	for(ll i=1;i<=q;i++){
		que[i].u=read(),que[i].v=read();
		que[i].idd=i;
	}
	sort(que+1,que+q+1,cmp);
	ll st=0;
	for(ll i=1;i<=q;i++){
		if(que[i].u>st){
			st=que[i].u;
			dijskra(st);
		}
		que[i].val=w[que[i].u]+w[que[i].v]+dis[que[i].v];
	}
	sort(que+1,que+q+1,cmp2);
	for(ll i=1;i<=q;i++) cout<<que[i].val<<"\n";
	return 0;
}