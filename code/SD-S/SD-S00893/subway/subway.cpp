#include<bits/stdc++.h>
using namespace std;
#define P pair<int,int>
#define int long long
int c,n,m,d,q,w1[500005],k,b,cnt,t,h[500005],idx,l,r,dis[500005],fa[500005]; 
bool flag[200005];
priority_queue<P,vector<P>,greater<P> >p;
struct node{
	int v,w,ne;
}e[500005];
void add(int u,int v,int w){
	e[++idx]={v,w,h[u]};
	h[u]=idx;
}
void dij(int x){
	memset(dis,0x3f,sizeof(dis));
	memset(flag,0,sizeof(flag));
	dis[x]=0;
	p.push(P(x,dis[x]));
	while(!p.empty()){
		int op=p.top().first;
		p.pop();
		if(flag[op]==1)continue;
		flag[op]=1;
		for(int i=h[op];i;i=e[i].ne){
			int v=e[i].v,w=e[i].w;
			if(fa[op]==v)continue;
			if(dis[op]+w<dis[v]){
				dis[v]=dis[op]+w;
				if(!flag[v]){
					fa[v]=op;
					p.push(P(v,dis[v]));
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w1[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		cnt++;
		for(int j=1;j<=k;j++){
			cin>>b>>t;
			add(100000LL+cnt,b,t);
			add(b,100000LL+cnt,t);
		}
		add(100000LL+cnt,100000LL+n+1,100005);
		add(100000LL+n+1,100000LL+cnt,-100005);
	}
	
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		dij(l);
		cout<<dis[r]+w1[l]+w1[r]<<endl;
	}
	return 0;
}

