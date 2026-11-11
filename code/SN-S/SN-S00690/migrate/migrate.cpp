#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=2e6+10,L=5010;
int c,T,n,f[N],u,mx[N],I,q[N];
ll d,x[N],g[N],p[N],ans;
bool prp;
int num,h,stk[20],tp;
ll nll;
char ch;
inline int read(){
	num=0,ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
	return num;
}
inline ll rll(){
	nll=0,h=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')h=-1,ch=getchar();
	while(isdigit(ch))nll=(nll<<3ll)+(nll<<1ll)+ch-'0',ch=getchar();
	return 1ll*h*nll;
}
void write(ll x){
	if(!x){
		putchar('0'),putchar('\n');
		return;
	}
	tp=0;
	while(x)stk[tp]=x%10,tp++,x/=10;
	for(int i=tp-1;i>=0;i--)putchar(stk[i]+'0');
	putchar('\n');
	return;
}
inline ll queryl(int l,int r){
	return p[l]-(r==I?0:p[r+1]);
}
inline ll queryr(int l,int r){
	return p[r]-(l==I?0:p[l-1]);
}
inline void solve1(){
	for(int i=0;i<n;i++){
    	I=i;
    	f[i]=0,g[i]=1,p[i]=1,mx[0]=i;
    	for(int j=i-1;j>=0;j--){
    		u=upper_bound(x,x+n,x[j]+d)-x-1,u=min(u,i),f[j]=f[u]+1;
    		if(u==j)break;
			g[j]=queryl(mx[f[u]],u),mx[f[j]]=j,p[j]=p[j+1]+g[j];
		}
		f[i]=0,g[i]=1,p[i]=1,mx[i]=0;
		for(int j=i+1;j<n;j++){
			u=lower_bound(x,x+n,x[j]-d)-x  ,u=max(u,i),f[j]=f[u]+1;
			if(u==j)break;
			g[j]=queryr(u,mx[f[u]]),mx[f[j]]=j,p[j]=p[j-1]+g[j];
		}
		for(int j=0;j<n;j++)ans+=(g[j]==2),g[j]=0,p[j]=0,mx[j]=-1;
	}
	write(ans>>1ll);
	return;
}
inline void solve2(){
	f[0]=0,g[0]=1,p[0]=1,mx[0]=0;
	for(int i=1;i<n;i++){
		u=lower_bound(x,x+n,x[i]-d)-x,f[i]=f[u]+1;
		if(u==i)break;
		g[i]=queryr(u,mx[f[u]]),mx[f[i]]=i,p[i]=p[i-1]+g[i];
	}
	for(int i=0;i<n;i++)q[i]=(i?q[i-1]:0)+(g[i]==2);
	for(int i=0;i<n;i++)ans+=(i?q[i-1]:0)+(i==n-1?0:q[n-i]);
	write((ans+1ll)>>1ll);
	return;
}
inline void solve(){
    n=read(),d=rll(),ans=0,prp=1;
    for(int i=0;i<n;i++)x[i]=rll();
    if(n<L){
    	solve1();
    	return;
	}
    for(int i=1;i<n;i++)prp&=(x[i]-x[i-1]==x[1]-x[0]);
    if(prp){
    	solve2();
    	return;
	}
	puts("0");
	return;
}
int main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--)solve();
	return 0;
}
