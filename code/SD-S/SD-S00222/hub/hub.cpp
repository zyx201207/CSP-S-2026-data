#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e6+10;
vector<int>g[N];
int dep[N];
int mxd,md;
void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;
	if(dep[u]>mxd){
		md=u;mxd=dep[u];
	}
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs1(v,u);
	}
}
int mxxd,mmd;
void dfs2(int u,int fa){
	dep[u]=dep[fa]+1;
	if(dep[u]>mxxd){
		mmd=u;
		mxxd=dep[u];
	}
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs2(v,u);
	}
}
vector<int>zj;
bool fd;
void dfs3(int s,int t,int fa){
	if(s==t){
		zj.push_back(t);
		fd=1;
		return;
	}
	for(auto v:g[s]){
		if(fa==v)continue;
		dfs3(v,t,s);
		if(fd){
			zj.push_back(s);
			return;
		}
	}
}
int dis[N],k,n;
bool check(int x){
	if(zj.size()<=x)return 1;
	int cnt=max(0,(int)zj.size()-3*x);
	queue<int> q;
	for(int i=1;i<=n;i++)dis[i]=n+1;
	int p=max(((int)zj.size()-3*x+1)/2,1),pp=max(1,(int)zj.size()-3*x-p);
	for(int i=x;i<=p+x;i++)dis[i]=0,q.push(i);
	for(int i=p+x*2;i<p+2*x+pp;i++)dis[i]=0,q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:g[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		if(dis[i]>x)cnt+=(dis[i]-x);
	}
	return cnt<=k;
}
signed main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		fd=0;zj.clear();
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);g[v].push_back(u);
		}
		dfs1(1,0);dfs2(md,0);dfs3(md,mmd,0);
		
//		queue<int>q;
//		for(auto x:zj)dis[x]=0,q.push(x);
//		while(!q.empty()){
//			int u=q.front();q.pop();
//			for(auto v:g[u]){
//				if(dis[v]>dis[u]+1){
//					dis[v]=dis[u]+1;
//					q.push(v);
//				}
//			}
//		}
		int l=0,r=n,res=n+1;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid))r=mid-1,res=mid;
			else l=mid+1;
		}
		cout<<res;
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
