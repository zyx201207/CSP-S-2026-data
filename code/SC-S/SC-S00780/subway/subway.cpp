#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+10;
int c,n,m,d,q,ans[N],vis[N],dis[N],w[N],f[N];
vector<pii> e[N],qu[N];
pii qq[N];
struct node{
	int pos,dis;
	friend bool operator<(node a,node b){
		return a.dis>b.dis;
	}
};
priority_queue<node> qp;
void dfs(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;qp.push({s,0});
	while(!qp.empty()){
		node t=qp.top();qp.pop();
		int u=t.pos;
		if(vis[u]) continue;
		vis[u]=1;
		for(pii r:e[u]){
			int v=r.fi,w=r.se;
			if(dis[v]>=w+dis[u]){
				dis[v]=w+dis[u];
				qp.push({v,dis[v]}); 
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    rep(i,1,m) cin>>w[i];
    int cnt=m+1;
    rep(i,1,n){
    	int k;cin>>k;
    	int lst=0;
    	rep(j,1,k){
    		int x,y;cin>>x>>y;++cnt;	
    		e[cnt].pb({x,y});if(f[i]==0) f[i]=x;
    		e[x].pb({cnt,y});
    		if(lst!=0){
    			e[lst].pb({cnt,0});
    			e[cnt].pb({lst,0});
			}lst=cnt;	
		}
	}rep(i,1,q){
		int x,y;cin>>x>>y;
		qq[i]={x,y};
		qu[x].pb({y,i});
	}memset(ans,0x3f,sizeof(ans));
	if(c<=15){
		rep(i,1,m){
			if(qu[i].size()>0){
				dfs(i);
			    for(pii x:qu[i]){
				    ans[x.se]=dis[x.fi]+w[i]+w[x.fi];
			    }
			}
		}rep(i,1,q) cout<<ans[i]<<'\n';
	}else{
	    rep(i,1,min(50ll,n)){
			dfs(f[i]);
			rep(j,1,q){
				int x=qq[j].fi;
				int y=qq[j].se;
				ans[j]=min(ans[j],dis[x]+dis[y]+w[x]+w[y]);
			}
	    }
		rep(i,1,q) cout<<ans[i]<<'\n';
	}
	return 0;
}
/*
反正都已经退役了就随便写写了 

luogu :needma

t2以为只有300个地铁口 气死了 写了个 m^2logm 的

正解应该遍历铁路吧 不知道 反正是个 nmlogm 的应该 
*/ 