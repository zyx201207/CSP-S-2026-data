#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005],vis[2000005],dis[2000005],hd[4000005],ct,to[4000005],nx[4000005];
void add(int u,int v){
	to[++ct]=v;
	nx[ct]=hd[u];
	hd[u]=ct;
}
struct node{
	int v,w;
	bool operator <(const node &B)const{
		return w>B.w;
	}
};
void dij(int s){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	priority_queue<node> q;
	q.push((node){s,0});
	while(!q.empty()){
		int x=q.top().v;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=hd[x];i;i=nx[i]){
			int y=to[i];
			if(vis[y]) continue;
			if(dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				q.push((node){y,dis[y]});
			}
		}
	}
}
int dfs(int s,int e){
	if(s==e) return 1;
	int res=0;
	for(int i=s;i<e;i++){
		if(dis[i]+1==dis[e]&&a[e]-a[i]<=d) res+=dfs(s,i);
	}
	return res;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	while(cin>>c){
		cin>>t;
		while(t--){
			ct=0;
			memset(hd,0,sizeof hd);
			memset(nx,0,sizeof nx);
			memset(to,0,sizeof to);
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=1;i<=n;i++){
				for(int j=i+1;a[j]-a[i]<=d&&j<=n;j++) add(i,j);
			}
			long long ans=0;
			for(int i=1;i<n;i++){
				dij(i);
				for(int j=i+1;j<=n;j++){
					if(dfs(i,j)==2) ans++;
				}
			}
			printf("%lld\n",ans);
		}
	}
    return 0;
}
