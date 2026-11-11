#include<cstring>
#include<cstdio>
using LL=long long;
template<class T>
inline void chkmin(T &x,T y){
	(x>y)&&(x=y,true);	return;
}
const int SIZI=(1<<16)-1;
char bufi[SIZI];	char *Si=bufi,*Ti=bufi;
#define load() (Ti=bufi+fread(Si=bufi,1,SIZI,stdin))
#define gc() (((Si==Ti)&&(load(),Si==Ti))?EOF:(*Si++))
inline int read(){
	int x=0,f=1;	char ch=gc();
	for(;(ch<'0')||(ch>'9');ch=gc())
		(ch=='-')&&(f=-1);
	for(;(ch>='0')&&(ch<='9');ch=gc())
		x=x*10+ch-'0';
	return x*f;
}
const int SIZO=(1<<16)-1;
char bufo[SIZO];	int bufoidx;
#define flush() (fwrite(bufo,1,bufoidx,stdout),bufoidx=0)
#define pc(c) ((bufoidx==SIZO)&&flush(),bufo[bufoidx++]=c)
inline void write(LL x){
	(x<0)&&(pc('-'),x=-x);
	static int stk[20];	int top=0;
	do{
		stk[top++]=x%10;	x/=10;
	}
	while(x);
	for(;top;pc('0'+stk[--top]));
	pc('\n');	return;
}
struct AutoFlusher{
	~AutoFlusher(){
		flush();	return;
	}
}AutoFlush;
const int N=510,M=500010,D=25;
int n,m,d,q;	int w[M];
struct Line{
	int i,t;
};
struct VecLine{
	Line ls[D];	int tot;
}vec[M];
LL g[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read();
	n=read();	m=read();
	d=read();	q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1,k,p,t;i<=n;i++){
		k=read();
		while(k--){
			p=read();	t=read();
			vec[p].ls[++vec[p].tot]=(Line){i,t};
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			g[i][j]=1e18;
		g[i][i]=0;
	}
	for(int i=1;i<=m;i++)
		for(int a=1;a<=vec[i].tot;a++){
			Line la=vec[i].ls[a];
			for(int b=1;b<=vec[i].tot;b++){
				Line lb=vec[i].ls[b];
				chkmin(g[la.i][lb.i],(LL)(la.t+lb.t));
				chkmin(g[lb.i][la.i],(LL)(lb.t+la.t));
			}
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				chkmin(g[i][j],g[i][k]+g[k][j]);
	int x,y;
	while(q--){
		x=read();	y=read();
		LL ans=1e18;
		for(int i=1;i<=vec[x].tot;i++){
			Line li=vec[x].ls[i];
			for(int j=1;j<=vec[y].tot;j++){
				Line lj=vec[y].ls[j];
				chkmin(ans,g[li.i][lj.i]+li.t+lj.t);
			}
		}
		ans+=w[x]+w[y];
		write(ans);
	}
	return 0;
}
