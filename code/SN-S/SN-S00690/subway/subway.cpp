#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int M=5e5+10,N=510;
constexpr ll inf=1e18;
int cc,n,m,d,q,k,a,h[M],to[M<<1],nxt[M<<1],ec,x,y;
ll w[M],t,c[M<<1],f[N][N],ans; 
inline void add(int u,int v,ll C){
	to[ec]=v,c[ec]=C,nxt[ec]=h[u],h[u]=ec,ec++;
	return;
}
int num,stk[20],tp;
ll nll;
char ch;
int read(){
	num=0,ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
	return num;
}
ll rll(){
	nll=0,ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))nll=(nll<<3ll)+(nll<<1ll)+ch-'0',ch=getchar();
	return nll;
}
void write(ll x){
	tp=0;
	while(x)stk[tp]=x%10,tp++,x/=10;
	for(int i=tp-1;i>=0;i--)putchar(stk[i]+'0');
	putchar('\n');
	return;
}
int main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	cc=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=0;i<m;i++)w[i]=rll(),h[i]=-1;
	for(int i=0;i<n;i++){
		k=read();
		for(int j=0;j<k;j++)a=read(),t=rll(),a--,add(a,i,t);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)f[i][j]=inf;
		f[i][i]=0;
	}
	for(int i=0;i<m;i++){
		for(int j=h[i];j>=0;j=nxt[j]){
			for(int k=h[i];k>=0;k=nxt[k]){
				f[to[j]][to[k]]=min(f[to[j]][to[k]],c[j]+c[k]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++)f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
		}
	}
	for(int i=0;i<q;i++){
		x=read(),y=read(),x--,y--,ans=inf;
		for(int j=h[x];j>=0;j=nxt[j]){
			for(int k=h[y];k>=0;k=nxt[k]){
				ans=min(ans,f[to[j]][to[k]]+c[j]+c[k]);
			}
		}
		write(ans+w[x]+w[y]);
	}
	return 0;
} 

//这跟 road 是一个难度吗就放 t2 ，秒了。 
