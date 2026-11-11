#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
		x=(x<<3)+(x<<1)+(c^48),
		c=getchar();
	return x*f;
}
const int N=2000006;
int n,d,tong[N],x[N];
void dfs(int u,int cost,int r){
	if(u==r){
		tong[cost]++;
		return ;
	}
	if(u>r) return ;
	int pos=u;
	while(x[u]+d>=x[++pos]&&pos<=r)
		dfs(pos,cost+1,r);
}
void solve(){
	n=read(),d=read();
	for(int i=1;i<=n;i++)
		x[i]=read();
	long long ans=0;
	for(int l=1;l<=n;l++){
		for(int r=l+3;r<=n;r++){
			memset(tong,0,sizeof(tong));
			dfs(l,0,r);
			for(int k=1;k<=r-l;k++)if(tong[k]){
				if(tong[k]==2) ans++;
				break;
			}
		}
	}printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c=read(),t=read();
	while(t--) solve();
	return 0; 
}
