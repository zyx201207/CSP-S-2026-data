#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=1e6+5;
int n,k,ans;
int p[N],dis[N];
bool vis[N];
int e[N<<1],ne[N<<1],h[N],idx;
inline void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int find(int x){
	if(p[x]!=x) return p[x]=find(p[x]);
	return x;
}
void dfs(int x,int num){
	if(num==k){
		for(int i=1;i<=n;i++) p[i]=i;
		int cnt=0;
		for(int t=1;t<=n;t++){
			if(vis[t]){
				for(int i=h[t];~i;i=ne[i]){
					int j=e[i];
					if(!vis[j]) continue;
					int fx=find(t),fy=find(j);
					if(fx!=fy){
						p[fx]=fy;
						cnt++;
					}
				}
			}
		}
		cnt=k-cnt;
		if(cnt<=2){
			queue<int> q;
			for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f;
			for(int i=1;i<=n;i++){
				if(vis[i]){
					q.emplace(i);
					dis[i]=0;
				}
			}
			int ma=0;
			while(!q.empty()){
				int x=q.front(); q.pop();
				for(int i=h[x];~i;i=ne[i]){
					int j=e[i];
					if(dis[j]>dis[x]+1){
						dis[j]=dis[x]+1;
						ma=max(ma,dis[j]);
						q.emplace(j);
					}
				}
			}
			ans=min(ans,ma);
		}
		return;
	}
	if(x>n) return;
	vis[x]=true;
	dfs(x+1,num+1);
	vis[x]=false;
	dfs(x+1,num);
}
inline void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) h[i]=-1;
	idx=0,ans=2e9;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,T=1;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
