#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar_unlocked();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar_unlocked();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar_unlocked();
	}
	return x*f;
}
int n,c,t,k,ans=LONG_LONG_MAX,a[1000005],fa[1000005];
vector<int> v[1000005];
inline int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int sum=0;
int dis[1005][1005];
inline void merge(int a,int b){
	int x=find(a),y=find(b);
	if(x!=y){
		sum--;
		fa[x]=y;
	}
}
bool vis[1000005];
inline void get_dis(int st,int x,int fa){
	for(int y:v[x]){
		if(y==fa) continue;
		dis[st][y]=dis[st][x]+1;
		get_dis(st,y,x);
	}
}
inline int work(){
	for(int i=1;i<=n;i++){
		vis[i]=0,fa[i]=i;
		dis[i][i]=0;
	}
	sum=k;
	for(int i=1;i<=k;i++){
		vis[a[i]]=1;
	}
	for(int i=1;i<=k;i++){
		int x=a[i];
		for(int y:v[x]){
			if(vis[y]) merge(x,y);
		}
	}
	if(sum>2) return LONG_LONG_MAX;
	for(int i=1;i<=n;i++){
		get_dis(i,i,0);
	}
	int maxn=0;
	for(int x=1;x<=n;x++){
		int minn=LONG_LONG_MAX;
		for(int j=1;j<=k;j++){
			int y=a[j];
			minn=min(minn,dis[x][y]);
		}
		maxn=max(maxn,minn);
	}
	return maxn;
}
inline void dfs(int x,int cnt){
	if(x==n+1){
		if(cnt==k+1) ans=min(ans,work());
		return ;
	}
	if(cnt<=k){
		a[cnt]=x;
		dfs(x+1,cnt+1);
	}
	dfs(x+1,cnt);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		ans=LONG_LONG_MAX;
		n=read(),k=read();
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<n;i++){
			int x,y;
			x=read(),y=read();
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,1);
		cout<<ans<<"\n";
	}
	return 0;
}
