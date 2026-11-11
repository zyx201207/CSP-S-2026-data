#include<bits/stdc++.h>
#define int long long
#define f(i,j,k) for(int i=j;i<=k;++i)
#define F(i,j,k) for(int i=j;i>=k;--i)
inline int read(){
	int x=0,type=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') type*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*type;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int maxn=1e6+10;
int c,T,n,k,u[maxn],v[maxn],dis[maxn],ans,fa[maxn],dep[maxn],dp[maxn];
std::vector<int> vec[maxn];
std::bitset<maxn> vis;
std::queue<int> q;
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){
	x=find(x); y=find(y);
	if(x==y) return ;
	fa[x]=y;
}
inline bool check(){
	f(i,1,n) fa[i]=i;
	f(i,1,n) if(vis[i]) for(auto y:vec[i]) if(vis[y]) merge(i,y);
	int cnt=0;
	f(i,1,n) if(find(i)==i&&vis[i]) ++cnt;
	return cnt<=2;
}
inline void bfs(){
	f(i,1,n) dis[i]=-1;
	f(i,1,n) if(vis[i]) q.push(i),dis[i]=0;
	while(!q.empty()){
		int p=q.front(); q.pop();
		for(auto y:vec[p]) if(dis[y]==-1) dis[y]=dis[p]+1,q.push(y);
	}
}
inline void dfs(int x,int sum){
	if(sum>k) return ;
	if(x==n+1){
		if(sum<2||!check()) return ;
		bfs(); int res=0;
		f(i,1,n) res=std::max(res,dis[i]);
		ans=std::min(ans,res); return ;
	}
	vis[x]=1; dfs(x+1,sum+1); vis[x]=0; dfs(x+1,sum);
}
inline void dfs(int x,int FA,int type){
	dep[x]=0; dp[x]=0; int ma=0,mi=0,sum=0;
	for(auto y:vec[x]) if(y!=FA){
		dfs(y,x,type); sum+=dp[y];
		dep[y]++; ma=std::max(ma,dep[y]);
		mi=std::min(mi,dep[y]);
	}
	if((-mi)>=ma) dep[x]=mi;
	else{
		if(ma<type) dep[x]=ma;
		else dep[x]=-type,dp[x]++;
	}
	dp[x]+=sum;
}
inline bool judge(int x){
	dfs(1,0,x); return dp[1]<=2;
}
inline void solve(){
	n=read(); k=read();
	f(i,1,n) vec[i].clear();
	f(i,1,n-1) u[i]=read(),v[i]=read(),vec[u[i]].push_back(v[i]),vec[v[i]].push_back(u[i]);
	if(n==k) return write(0),putchar('\n'),void();
	if(n<=10){
		ans=n+1; dfs(1,0); write(ans); putchar('\n');
		return ;
	}
	if(n&1){
		int m=n/2,flag=1;
		f(i,1,m) flag&=((u[i]==i&&v[i]==i+1)||(u[i]==i+1&&v[i]==i));
		f(i,m+1,n-1) flag&=((u[i]==i-m&&v[i]==i+1)||(u[i]==i+1&&v[i]==i-m));
		if(flag){
			if(k>=m) return write(1),putchar('\n'),void();
			write((m-k+3)/4+1); putchar('\n'); return ;
		}
	}
	if(k==2){
		int L=1,R=n+1,res=n+1;
		while(L<=R){
			int mid=(L+R)>>1;
			if(judge(mid)) R=mid-1,res=mid;
			else L=mid+1;
		}
		write(res),putchar('\n'); return ;
	}
}
inline void work(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(); T=read(); while(T--) solve();
}
signed main(){work();return 0;}