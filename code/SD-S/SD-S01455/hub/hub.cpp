#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e2+5;
int c,t;
int n,k,ans;
int fa[N],app[N];
int use[N],vis[N];
int uu[N],vv[N],dis[N];
vector<int>e[N];
queue<int> q;
void cclear() {
	ans=n+1;
	for(int i=1; i<=n; i++) fa[i]=i,dis[i]=n+1,app[i]=vis[i]=use[i]=0;
	for(int i=1; i<=n; i++) e[i].clear();
	while(!q.empty()) q.pop();
}
int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int count1(int x) {
	int ret=0;
	while(x) {
		if(x&1) ret++;
		x=x/2;
	}
	return ret;
}
int get_uni(int st1) {
	int ret=0;
	for(int i=1; i<=n; i++) app[i]=use[i]=0,fa[i]=i;
	for(int i=1; i<=n; i++,st1/=2)
		if(st1&1) use[i]=1;
	for(int i=1; i<n; i++) {
		int u1=uu[i],v1=vv[i];
		if(use[u1]==0||use[v1]==0) continue;
		int fu=find(u1),fv=find(v1);
		fa[fu]=fv;
	}
	for(int i=1; i<=n; i++)
		if(use[i]) {
			int ff=find(i);
			app[ff]++;
			if(app[ff]==1) ret++;
		}
	return ret;
}
int bfs() {
	int ret=0;
	while(!q.empty())q.pop();
	for(int i=1; i<=n; i++) {
		if(use[i]) dis[i]=0,q.push(i),vis[i]=1;
		else dis[i]=n+1,vis[i]=0;
	}
	while(!q.empty()) {
		int u1=q.front(),len=e[u1].size();
		q.pop();
		for(int i=0; i<len; i++) {
			int v=e[u1][i];
			if(vis[v]) continue;
			dis[v]=dis[u1]+1;
			vis[v]=1,q.push(v);
		}
	}
	for(int i=1; i<=n; i++) ret=max(ret,dis[i]);
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		cclear();
		int lg=(1<<n)-1;
		for(int i=1; i<n; i++) cin>>uu[i]>>vv[i];
		for(int i=1; i<n; i++) e[uu[i]].push_back(vv[i]),e[vv[i]].push_back(uu[i]);
		for(int i=1; i<=lg; i++) {
			if(count1(i)!=k) continue;
			if(get_uni(i)>2) continue;
			int val=bfs();
			ans=min(ans,val);
		}
		cout<<ans<<endl;
	}
	return 0;
}
