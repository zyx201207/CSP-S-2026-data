#include<bits/stdc++.h>
using namespace std;
inline long long rd(){long long f=1,x=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return f*x;}
inline void wt(long long x,int opt){int top=0;char a[105];if(x<0)putchar('-'),x=-x;do{a[++top]=x%10+'0';x/=10;}while(x);for(int i=top;i>=1;i--)putchar(a[i]);if(opt==1)putchar(' ');if(opt==2)putchar('\n');}
int c,t;
int n,k;
int u[1000005],v[1000005];
vector<int>V[1000005];
int dis[1000005],d[1000005];
int f[1000005];
bool vis[1000005];
void dfs(int u,int fa){
	dis[u]=0;f[u]=fa;
	if(fa)dis[u]=dis[fa]+1;
	for(auto to:V[u]){
		if(to==fa)continue;
		dfs(to,u);
	}
}
void dfss(int u,int fa,int g){
	dis[u]=0;
	if(fa)dis[u]=dis[fa]+1;
	d[g]=max(d[g],dis[u]);
	for(auto to:V[u]){
		if(to==fa||vis[to])continue;
		dfss(to,u,g);
	}
}
bool vis1[1000005],vis2[1000005];
vector<int>arr;
bool check(int len){
	int maxx=-0x3f3f3f3f;
	int siz=arr.size();
	int l=0,r=0;
	for(int i=0;i<siz;i++){
		int nw=arr[i];
		maxx=max(maxx,d[nw]-i);
		if(maxx+i>len)break;
		vis1[i]=1;
		l=i;
	}
	for(int i=siz-1;i>=0;i--){
		int nw=arr[i];
		maxx=max(maxx,d[nw]+i);
		if(maxx-i>len)break;
		vis2[i]=1;
		r=i;
	}
	for(int i=l;i<=r;i++){
		int nw=arr[i];
		int chang=min(d[nw]+i-l,d[nw]+r-i);
		if(chang>len)return 0;
	}
	return 1;
}
void _15pts(){
	if(n==2){
		wt(0,2);
		return;
	}
	dis[1]=0;
	dfs(1,0);
	int x=0,y=0;
	for(int i=1;i<=n;i++)if(dis[x]<dis[i])x=i;
	dis[x]=0;
	dfs(x,0);
	for(int i=1;i<=n;i++)if(dis[y]<dis[i])y=i;
	dfs(y,0);
	int u=x;
	arr.clear();
	while(u!=0){
		vis[u]=1;
		arr.push_back(u);
		u=f[u];
	}
	for(int i=1;i<=n;i++){
		if(vis[i])dfss(i,0,i);
	}
	int siz=arr.size();
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	wt(ans,2);
}
int fa[1000005];
int findfa(int u){
	if(fa[u]==u)return u;
	return fa[u]=findfa(fa[u]);
}
void merge(int x,int y){
	x=findfa(x);y=findfa(y);
	if(x==y)return;
	fa[x]=y;
}

int ans;
void _30pts(){
	ans=n;
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k)continue;
		vector<int>s;s.clear();
		for(int j=0;j<n;j++)vis[j+1]=0,fa[j+1]=j+1;
		for(int j=0;j<n;j++)if(i&(1<<j))vis[j+1]=1;
		for(int j=1;j<n;j++)if(vis[u[j]]&&vis[v[j]])merge(u[j],v[j]);
		set<int>dcc;dcc.clear();
		for(int j=1;j<=n;j++)if(vis[j])dcc.insert(findfa(fa[j]));
		if(dcc.size()>2)continue;
		queue<int>q;while(!q.empty())q.pop();
		for(int j=1;j<=n;j++)dis[j]=0x3f3f3f3f;
		for(int j=0;j<n;j++)if(i&(1<<j))q.push(j+1),dis[j+1]=0;
		int maxx=0;
		while(!q.empty()){
			int u=q.front();q.pop();
			maxx=max(maxx,dis[u]);
			for(auto to:V[u]){
				if(dis[to]>dis[u]+1){
					dis[to]=dis[u]+1;
					q.push(to);
				}
			}
		}
		ans=min(ans,maxx);
	}
	wt(ans,2);
}
bool checkk(int mid,int len){
	int l=0,r=0,ll=0,rr=0;
	l=mid;rr=len-mid;
	r=l+(k-2)/2;
	ll=rr-(k-2-(k-2)/2);
	//cout<<mid<<' '<<len<<' '<<r<<' '<<ll<<endl;
	for(int i=r;i<=ll;i++){
		int chang=min(i-r+1,ll-i+1);
		if(chang>mid)return 0;
	}
	return 1;
}
void _10pts(){
	if(n==k){
		wt(0,2);
		return;
	}
	int len=(n+1)/2+1;
	if(k>=len-2){
		wt(1,2);
		return;
	}
	int l=2,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(checkk(mid,len))ans=mid,r=mid-1;
		else l=mid+1;
	}
	wt(ans,2);
}
void init(){
	for(int i=1;i<=n;i++)V[i].clear(),dis[i]=0,vis[i]=0,fa[i]=0,d[i]=0,vis1[i]=0,vis2[i]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=rd();t=rd();
	while(t--){
		n=rd();k=rd();
		for(int i=1;i<n;i++)u[i]=rd(),v[i]=rd(),V[u[i]].push_back(v[i]),V[v[i]].push_back(u[i]);
		if(c==7||c==11||c==12)_15pts();
		else if(c==13||c==14)_10pts();
		else _30pts();
		init();
	}

}

