#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
inline int read(){
	int w=0,f=1;
	char ch=getchar();
	while(ch<'0' || '9'<ch){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch && ch<='9'){
		w=(w<<3)+(w<<1)+(ch^48);
		ch=getchar();
	}
	return f*w;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int c,t,n,k,dep[N],maxdep[N];
vector<int> g[N];
bool vis[N],vis1[N],vis2[N];
int dis[N];
inline void bfs(int s,int mid){
	queue<int> q;
	for(int i=1;i<=n;i++) dis[i]=1e9,vis1[i]=0;
	q.push(s);
	dis[s]=0;vis1[s]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(auto to:g[now]){
			if(vis1[to]) continue;
			vis1[to]=1;
			dis[to]=dis[now]+1;
			if(dis[to]<mid) q.push(to); 
		}
	}
	for(int i=1;i<=n;i++) if(dis[i]<=mid) vis[i]=1;
	return;
}
bool f=0;
int fa[N];
inline int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
map<int,bool> mp;
inline void check(int now,int mid){
	if(f) return;
	if(now==k+1){
		for(int i=1;i<=n;i++) fa[i]=i,vis[i]=0;
		for(int i=1;i<=n;i++){
			if(vis2[i]){
				bfs(i,mid);
				for(auto to:g[i]){
					if(vis2[to]){
						fa[find(to)]=find(i);
					}
				}
			} 
		}
		bool ok=1;
		for(int i=1;i<=n;i++) if(!vis[i]){
			ok=0;
			break;
		}
		int cnt=0;
		mp.clear();
		for(int i=1;i<=n;i++){
			if(vis2[i] && !mp[find(i)]){
				cnt++;
				mp[find(i)]=1;
			}
		}
		if(cnt<=2 && ok) f=1;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis2[i]) continue;
		vis2[i]=1;
		check(now+1,mid);
		vis2[i]=0;
	}
}
int du[N];
signed main(){
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();k=read();
		for(int i=1;i<=n;i++) g[i].clear(),dep[i]=maxdep[i]=0,du[i]=0;
		for(int i=1,u,v;i<=n-1;i++){
			u=read();v=read();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int l=1,r=n,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			f=0;
			for(int j=1;j<=n;j++) vis2[j]=0;
			check(1,mid);
			if(f) ans=mid,r=mid-1;
			else l=mid+1;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
