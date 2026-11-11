#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+3;
const int INF=1e18;
int c,n,m,d,q;
ll w[N];
ll t[503][N];
int x,y;
ll ans=INF;
int vis[N];
struct Road{
	int k;
	set<int> e;
}r[503];
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline void dfs(int x,int y,int sum){
	if(x==y){
		if(sum<ans) ans=sum;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(t[i][x]==0) continue;
		for(auto j:r[i].e){
			if(vis[j]==1) continue;
			vis[j]=1;
			dfs(j,y,sum+t[i][x]+t[i][j]);
			vis[j]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		r[i].k=read();
		int a;
		for(int j=1;j<=r[i].k;j++){
			a=read();
			r[i].e.insert(a);
			t[i][a]=read();
		}
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		vis[x]=1;vis[y]=1;
		x=read();y=read();
		dfs(x,y,0);
		ans+=w[x]+w[y];
		write(ans);putchar('\n');
	}
	return 0;
}