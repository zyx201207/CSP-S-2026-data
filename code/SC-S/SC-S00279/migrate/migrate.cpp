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
const int maxn=2e6+10;
int c,T,n,d,a[maxn],pos[maxn],nxt[maxn],sum[maxn],dis[maxn];
std::vector<int> vec[maxn];
std::queue<int> q;
inline void bfs(int x){
	f(i,1,n) dis[i]=-1,sum[i]=0;
	sum[x]=1; dis[x]=0; q.push(x);
	while(!q.empty()){
		int p=q.front(); q.pop();
		for(auto y:vec[p]){
			if(dis[y]==-1) dis[y]=dis[p]+1,sum[y]=sum[p],q.push(y);
			else if(dis[y]==dis[p]+1) sum[y]+=sum[p];
		}
	}
}
inline void solve(){
	n=read(); d=read();
	f(i,1,n) a[i]=read(),pos[i]=a[i];
	std::stable_sort(pos+1,pos+1+n);
	int tot=std::unique(pos+1,pos+1+n)-pos-1;
	f(i,1,n) nxt[i]=std::upper_bound(pos+1,pos+1+tot,a[i]+d)-pos-1;
	f(i,1,n) vec[i].clear();
	f(i,1,n) f(j,i+1,n) if(a[j]-a[i]<=d) vec[i].push_back(j);
	int ans=0;
	f(i,1,n){
		bfs(i);
		f(j,i+1,n) if(sum[j]==2) ++ans;
	}
	write(ans); putchar('\n');
}
inline void work(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(); T=read(); while(T--) solve();
}
signed main(){work();return 0;}