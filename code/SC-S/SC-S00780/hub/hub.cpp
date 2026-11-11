#include<bits/stdc++.h>
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=31;
int n,m,a[N],res,vis[N],dis[N],tg[N],c,T,k;
vector<int> g[N];
void dfs(int u){
	if(vis[u]||tg[u]==0) return;
	vis[u]=1;
	for(int v:g[u]){
		dfs(v);
	} 
}
void dfs1(int u,int fa){
	if(tg[u]==1) dis[u]=0;
	dis[u]=min(dis[u],dis[fa]+1);
	for(int v:g[u]){
		if(v==fa) continue;
		dfs1(v,u);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
    	cin>>n>>k;
    	int ans=INT_MAX;
        rep(i,1,n) g[i].clear();
    	rep(i,1,n-1){
    		int x,y;
    		cin>>x>>y;
    		g[x].pb(y);g[y].pb(x);
		}rep(i,1,(1<<n)-1){
			memset(vis,0,sizeof(vis));
			memset(dis,0x3f,sizeof(dis));
			int x=0;int scc=0;res=0;
			rep(j,0,n-1){
				if((i>>j)%2==1) tg[j+1]=1,x++;
				else tg[j+1]=0;
			}
            if(x!=k) continue;
			rep(j,1,n){
				if(tg[j]){
					if(vis[j]==0) scc++;
					dfs(j);dfs1(j,0);
				}
			}
			rep(j,1,n) res=max(res,dis[j]);
			if(scc<=2) ans=min(ans,res);
		}cout<<ans<<'\n';
	}
	return 0;
}
/*
好像是一个很板的dp

先不考虑联通块的要求 

然后做 dp 虽然我已经忘了咋写的了 好像是一个紫

大概是先二分 然后搞一个 f 一个 g 来转移那些点被选了 

然后 dfs 来求出最小的可行联通块大小 

感觉上没啥问题 nlogn 不知道行不行

我的代码已经写不出来了:((

感觉劣于 flash 模式的任何模型 

原题大赛? 

虽然感觉打的依托 但是毕竟相当于完全没复习来考的

所以还好吧 

希望大家万事如意 祝我高考加油 我们 NOIP2026/XCPC 赛场见 
*/ 