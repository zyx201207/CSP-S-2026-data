#include <bits/stdc++.h>
using namespace std;
#define il inline
#define lld int64_t
namespace DYC{
namespace FastIO{
	const int LEN=1<<20;
	char ibuf[LEN],obuf[LEN],tbuf[20],*p1=ibuf,*p2=ibuf,*p3=obuf;
	il char gc(){return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,LEN,stdin),p1==p2)?EOF:*p1++;}
	il void flush(){fwrite(obuf,1,p3-obuf,stdout),p3=obuf;}
	il void pc(char x){p3-obuf==LEN?flush():void(),*p3++=x;}
	il void read(auto &x){
		char ch=gc();bool fl=0;x=0;
		while(ch< '0'||ch> '9')fl=ch=='-',ch=gc();
		while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=gc();
		fl?x=-x:x;
	}
	il void read(auto &x,auto &...y){read(x),read(y...);}
	il void write(lld x){
		short top=0;
		do tbuf[top++]=x%10;while(x/=10);
		while(top)pc(tbuf[--top]|48);
		pc('\n');
	}
}
using namespace FastIO;

const int N=2e6+5;

int n,pre[N],nxt[N],lp[N],rp[N],ln[N],rn[N],f[N],g[N];
lld d,ans,x[N];
il void Run(){
	read(n,d),ans=0;
	for(int i=1;i<=n;i++){
		read(x[i]),f[i]=g[i]=1;
		lp[i]=ln[i]=n+1;
		rp[i]=rn[i]=1-1;
	}
	for(int l=1,r=1;l<n;l++){
		while(r<=n&&x[r]-x[l]<=d)r++;
		nxt[l]=r-1;
		ln[r-1]=min(ln[r-1],l);
		rn[r-1]=max(rn[r-1],l);
	}
	for(int l=n,r=n;r>1;r--){
		while(l>=1&&x[r]-x[l]<=d)l--;
		pre[r]=l+1;
		lp[l+1]=min(lp[l+1],r);
		rp[l+1]=max(rp[l+1],r);
	}
	for(int i=1;i<=n;i++){
		int L=ln[i],R=rn[i],j=pre[i];
		if(L<=n)f[i]+=f[j]+R-L;
	}
	for(int i=n;i>=1;i--){
		int L=lp[i],R=rp[i],j=nxt[i];
		if(R>=1)g[i]+=g[j]+R-L;
	}
	for(int i=2,j=3;j<n;i++,j++){
		int A=ln[j],B=rp[i];
		if(A>=i||B<=j)continue;
		int cntl=rn[j]-A+(pre[i]==A?f[A]:1);
		int cntr=B-lp[i]+(nxt[j]==B?g[B]:1);
		ans+=(lld)cntl*cntr;
	}
	write(ans);
}

int o,t;
il void main(){
	freopen("migrate.in" ,"r",stdin );
	freopen("migrate.out","w",stdout);
	for(read(o,t);t;t--)Run();
}}
int main(){DYC::main(),DYC::flush();}
