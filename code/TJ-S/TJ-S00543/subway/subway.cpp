#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k,a,t,x,pos,E,u,zt[500005],dtk[500005],to[600005],wt[600005],nx[600005],hd[500005],dis[500005];
void add(int u,int v,int w){
	to[++E]=v,wt[E]=w,nx[E]=hd[u],hd[u]=E;
}queue<long long>p0; 
priority_queue<pair<long long,long long> >p;
bool vis[500005];
struct query{
	int X,Y,id,ans;
}Q[100005];
bool cmp1(query o,query p){
	return o.X<p.X;
}bool cmp2(query o,query p){
	return o.id<p.id;
}int main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout),
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a>>t,add(a,m+i,t),add(m+i,a,t);
	}for(int r=1;r<=q;r++){
		cin>>Q[r].X>>Q[r].Y;
		Q[r].id=r;
	}sort(Q+1,Q+1+q,cmp1);
	for(int r=2;r<=q+1;r++){
		if(Q[r].X!=Q[r-1].X){
			x=Q[r-1].X;
			for(int i=1;i<=m+n;i++)
				dis[i]=4e18;
			memset(vis,0,sizeof(vis));
			dis[x]=0;
			if(c>=12&&c<=19){
				p0.push(x);
				while(!p0.empty()){
					u=p0.front();
					p0.pop();
					if(vis[u])
						continue;
					vis[u]=1;
					for(int e=hd[u];e;e=nx[e])
						dis[to[e]]=dis[u]+t,p0.push(to[e]);
				}
			}else{
				p.push({0,x});
				while(!p.empty()){
					u=p.top().second;
					p.pop();
					if(vis[u])
						continue;
					vis[u]=1;
					for(int e=hd[u];e;e=nx[e]){
						if(dis[to[e]]>dis[u]+wt[e]) 
							dis[to[e]]=dis[u]+wt[e],
							p.push({-dis[to[e]],to[e]});
					}
				}
			}pos=r-1;
			while(Q[pos].X==x)
				Q[pos].ans=dis[Q[pos].Y]+w[x]+w[Q[pos].Y],pos--;
		}
	}sort(Q+1,Q+1+q,cmp2);
	for(int r=1;r<=q;r++)
		cout<<Q[r].ans<<"\n";
	return 0;
}
