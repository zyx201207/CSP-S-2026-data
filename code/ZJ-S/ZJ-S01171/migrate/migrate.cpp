#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
inline int read(){
	int n=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')n=n*10+c-'0',c=getchar();
	return n*f;
}
inline void chkmax(int &a,int b){a=max(a,b);}
inline void chkmin(int &a,int b){a=min(a,b);}
const int N=2e6+5;
const int inf=9e18;
int n,d,x[N];
int f[N],g[N],suf[N],nxt[N];
int q[N],lt,rt,L[N],R[N],siz[N];
void work1(){
	n=read(),d=read();
	for(int i=1;i<=n;++i)x[i]=read();
	x[n+1]=inf;
	for(int i=1,j=1;i<=n;++i){
		while(x[j+1]-x[i]<=d)++j;
		nxt[i]=j;
	}
    int ans=0;
	for(int i=1;i<=n;++i){
	    lt=1;rt=0;suf[i]=0;
		for(int j=i-1;j>=1;--j){
			if(nxt[j]>=i)f[j]=g[j]=1;
			else{
				while(lt<=rt&&R[lt]>nxt[j]){
					if(L[lt]>nxt[j])++lt;
					else{
						siz[lt]-=suf[nxt[j]+1]-suf[R[lt]+1];
						R[lt]=nxt[j];
						break;
					}
				}
				if(lt>rt)f[j]=inf,g[j]=0;
				else{
					f[j]=f[nxt[j]]+1;
					g[j]=siz[lt];
				}
			}
			suf[j]=suf[j+1]+g[j];
			if(lt<=rt&&f[j]==q[rt])siz[rt]+=g[j],L[rt]=j;
			else siz[++rt]=g[j],q[rt]=f[j],L[rt]=R[rt]=j;
			if(g[j]==2)++ans;
		}
	}
	printf("%lld\n",ans);
}
void work2(){
	n=read(),d=read();
	for(int i=1;i<=n;++i)x[i]=read();
	int dt=0;
	for(int i=2;i<=n;++i){
		if(x[i]-x[1]<=d)++dt;
		else break;
	}
	if(dt<=1)puts("0");
	else printf("%lld\n",max(0ll,n-2*dt+1));
}
void work3(){
	n=read(),d=read();
	for(int i=1;i<=n;++i)x[i]=read();
	int pos;
	for(int i=1;i<=n;++i){
		if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
			pos=i;
			break;
		}
	}
	x[n+1]=inf;
	for(int i=1,j=1;i<=n;++i){
		while(x[j+1]-x[i]<=d)++j;
		nxt[i]=j;
	}
	int ans=0;
	for(int i=1;i<pos;++i){
		if(nxt[i]==pos){
			ans+=nxt[pos-1]-nxt[pos-2];
		}
		else if(nxt[i]==pos+1){
			ans+=nxt[pos]-nxt[pos-1];
		}
	}
	printf("%lld\n",ans);
}
void work4(){
	puts("0");
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C=read(),T=read();
	while(T--){
		if(C<=10)work1();
		else if(C<=12)work2();
		else if(C<=14)work3();
		else work4();
	}
	return 0;
}

