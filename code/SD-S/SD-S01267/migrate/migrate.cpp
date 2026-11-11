#include<bits/stdc++.h>
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define ROF(i,r,l) for(int i=r;i>=l;i--)
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-48;
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int N = 2e6+10;
int x[N],pre[N],nxt[N],f[N],g[N];
void solve(){
	int n=read(),d=read();
	FOR(i,1,n)x[i]=read();
	int p=1;
	FOR(i,1,n){
		while(x[i]-x[p]>d)p++;
		pre[i]=p;
	}
	p=n;
	ROF(i,n,1){
		while(x[p]-x[i]>d)p--;
		nxt[i]=p;
	}
	nxt[0]=pre[0]=0,nxt[n+1]=pre[n+1]=n+1;
	ROF(i,n,1){
		f[i]=1;
		if(nxt[i]>nxt[i-1]){
			int l=max(i+1,nxt[i-1]+1);
			f[i]+=f[nxt[i]]+nxt[i]-l;
		}
	}
	FOR(i,1,n){
		g[i]=1;
		if(pre[i]<pre[i+1]){
			int r=min(i-1,pre[i+1]-1);
			g[i]+=r-pre[i]+g[pre[i]];
		}
	}
	int ans=0;
	FOR(i,1,n-1){
		int R=nxt[i],r=max(i+1,nxt[i-1])+1,L=pre[i+1],l=min(i,pre[i+2])-1;
		if(r<=R&&l>=L){
			ans+=(R-r+1+(f[R]-1)*(nxt[i+1]==R))*(l-L+1+(g[L]-1)*(pre[i]==L));
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();while(t--)solve();
	return 0;
}

