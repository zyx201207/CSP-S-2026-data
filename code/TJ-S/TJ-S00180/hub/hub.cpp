#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000005
int c,T,n,k;
vector <int> g[N];
int a[N],vis[N];
int s[N],sz[N];
int find(int x){
	if (x!=s[x]) s[x]=find(s[x]);
	return s[x];
}
void merge(int x,int y){
	if (sz[x]<sz[y]) swap(x,y);
	sz[x]+=sz[y];
	s[y]=x;
}
set <int> ss;
struct node{int id,dis;};
queue <node> q;
void work(){
	scanf("%lld %lld",&n,&k);
	for (int i=1;i<=n;i++) g[i].clear();
	for (int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	} 
	if (c==13 || c==14){
		int m=n/2;
		if (k==n) printf("0\n");
		else if (k>=m) printf("1\n");
		else printf("%lld",(((m+1)/2)-(k/2)+1)/2+1);
	}
	else{
		int ans=4e18;
		for (int p=0;p<(1<<n);p++){
			int cnt=0,x=p;
			for (int i=1;i<=n;i++){
				a[i]=x&1;
				x>>=1;
				cnt+=a[i];
			}
			if (cnt!=k) continue;
			for (int i=1;i<=n;i++) s[i]=i,sz[i]=1;
			for (int i=1;i<=n;i++){
				for (int j=0;j<g[i].size();j++){
					int t=g[i][j];
					if (a[i] && a[t]) merge(find(i),find(t));
				}
			}
			ss.clear();
			for (int i=1;i<=n;i++) if (a[i]) ss.insert(find(i));
			if (ss.size()>2) continue;
			int mx=0;
			for (int i=1;i<=n;i++) vis[i]=0;
			for (int i=1;i<=n;i++) if (a[i]) q.push(node{i,0}),vis[i]=1;
			while (q.size()){
				int x=q.front().id,v=q.front().dis;
				q.pop();
				mx=max(mx,v);
				for (int i=0;i<g[x].size();i++){
					int t=g[x][i];
					if (vis[t]) continue;
					vis[t]=1;
					q.push(node{t,v+1});
				}
			}
			ans=min(ans,mx);
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	scanf("%lld %lld",&c,&T);
	while (T--) work();
	return 0;
}
