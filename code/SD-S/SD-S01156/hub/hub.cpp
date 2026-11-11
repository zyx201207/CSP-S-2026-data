//
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rop(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define por(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double ld;
using namespace std;
int c,t,n,k,u,v,tot,head[1000005];
struct edge{
	int to,nxt;
}e[2000005];
void add(int u,int v){
	e[++tot].to=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}
struct{
	int dep[100005],maxd[100005],f[100005],dis1[100005],dis2[100005];
	bool vis[100005];
	struct node{
		int id,val;
		bool operator<(node x)const{
			return val<x.val;
		}
	};
	void dfs(int u,int fa){
		dep[u]=dep[fa]+1;
		f[u]=fa;
		maxd[u]=0;
		for(int i=head[u];i;i=e[i].nxt){
			int to=e[i].to;
			if(to==fa)
				continue;
			dfs(to,u);
			maxd[u]=max(maxd[u],maxd[to]+1);
		}
	}
	void dfs2(int u,int fa){
		if(vis[u])
			dis1[u]=0;
		else
			dis1[u]=dis1[fa]+1;
		for(int i=head[u];i;i=e[i].nxt){
			int to=e[i].to;
			if(to==fa)
				continue;
			dfs2(to,u);
		}
	}
	void dfs3(int u,int fa){
		dis2[u]=dis2[fa]+1;
		for(int i=head[u];i;i=e[i].nxt){
			int to=e[i].to;
			if(to==fa)
				continue;
			dfs3(to,u);
		}
	}
	void solve(){
		int ans=n;
		rep(i,1,n){
			dfs(i,0);
			rep(j,1,n){
				if(i==j)
					continue;
				rep(u,1,n)
					vis[u]=0;
				vis[i]=vis[j]=1;
				priority_queue<node>q;
				int now=j;
				while(f[now]!=i)
					now=f[now];
				for(int tmp=head[i];tmp;tmp=e[tmp].nxt){
					int to=e[tmp].to;
					if(to==now)
						continue;
					q.push({to,maxd[to]});
				}
				for(int tmp=head[j];tmp;tmp=e[tmp].nxt){
					int to=e[tmp].to;
					if(to==f[j])
						continue;
					q.push({to,maxd[to]});
				}
				rep(lsbl,1,k-2){
					if(!q.size())
						break;
					int u=q.top().id;
					vis[u]=1;
					q.pop();
					for(int tmp=head[u];tmp;tmp=e[tmp].nxt){
						int to=e[tmp].to;
						if(to==f[u])
							continue;
						q.push({to,maxd[to]});
					}
				}
				dfs2(i,0);
				dfs3(j,0);
				int res=0;
				rep(u,1,n)
					res=max(res,min(dis1[u],dis2[u]));
				ans=min(ans,res);
			}
		}
		cout<<ans<<endl;
	}
}solve1;
//struct{
//	int dep[1005],f[1005],maxd[1005],dis[1005];
//	void dfs(int u,int fa){
//		dep[u]=dep[fa]+1;
//		f[u]=fa;
//		maxd[u]=0;
//		for(int i=head[u];i;i=e[i].nxt){
//			int to=e[i].to;
//			if(to==fa)
//				continue;
//			dfs(to,u);
//			maxd[u]=max(maxd[u],maxd[to]+1);
//		}
//	}
//	void dfs2(int u,int fa){
//		for(int i=head[u];i;i=e[i].nxt){
//			int to=e[i].to;
//			
//		}
//	}
//	void solve(){
//		int ans=n;
//		rep(rt,1,n){
//			dfs(rt,0);
//			dfs2(rt,0);
//			int res=0;
//			rep(u,1,n)
//				res=max(res,dep[u]);
//			res=min(res,)
//			ans=min(ans,res);
//		}
//		cout<<ans;
//	}
//}solve2;
struct{
	void solve(){
		if(k==n){
			cout<<"0\n";
			return;
		}
		if(k>=n/2){
			cout<<"1\n";
			return;
		}
		cout<<(n/2-k-1)/4+2<<endl;
	}
}solve3;
void solve(){
	cin>>n>>k;
	tot=0;
	rep(i,1,n)
		head[i]=0;
	rop(i,1,n){
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	if(c>=13&&c<=14){
		solve3.solve();
		return;
	}
//	if(c==7){
//		solve2.solve();
//		return;
//	}
//	if(c<=6){
		solve1.solve();
		return;
//	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}
/*
n^2(n+klogn) 
40 18:20
*/

