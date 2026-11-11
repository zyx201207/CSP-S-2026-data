#include<algorithm>
#include<cstdio>
using namespace std;
using LL=long long;
const int SIZI=(1<<16)-1;
char bufi[SIZI];	char *Si=bufi,*Ti=bufi;
#define load() (Ti=bufi+fread(Si=bufi,1,SIZI,stdin))
#define gc() (((Si==Ti)&&(load(),Si==Ti))?EOF:(*Si++))
template<class T=int>
inline T read(){
	T x=0;	int f=1;	char ch=gc();
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
const int N=2000010;
int n;	LL d;	LL x[N];
inline int getprev(int i){
	return ((i>=1)&&(i<=n))?(lower_bound(x+1,x+n+1,x[i]-d)-x):-1;
}
inline int getnext(int i){
	return ((i>=1)&&(i<=n))?(upper_bound(x+1,x+n+1,x[i]+d)-1-x):-1;
}
namespace A{
inline bool check(){
	LL d=x[2]-x[1];
	for(int i=3;i<=n;i++)
		if(d!=x[i]-x[i-1])
			return false;
	return true;
}
inline void solve(){
	d/=x[2]-x[1];
	if(d<=1)
		write(0);
	else
		write(max(n-2*d+1,0ll));
	return;
}
}
namespace B{
inline bool check(){
	for(int i=1;i<=n;i++)
		if((x[i]-x[1]<=d)&&(x[n]-x[i]<=d))
			return true;
	return false;
}
inline void solve(){
	int c;
	for(c=1;c<=n;c++)
		if((x[c]-x[1]<=d)&&(x[n]-x[c]<=d))
			break;
	int ll1=getprev(c-1),lr1=getnext(c-1);
	int ll2=getprev(c-2),lr2=getnext(c-2);
	int rl1=getprev(c+1),rr1=getnext(c+1);
	int rl2=getprev(c+2),rr2=getnext(c+2);
	return;
}
}
int pre[N],nex[N];
struct Node{
	int v,c;
}f[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read();
	for(int _=read();_;_--){
		n=read();	d=read<LL>();
		for(int i=1;i<=n;i++)
			x[i]=read<LL>();
		if(n==1){
			write(0);
			continue;
		}
		if(A::check()){
			A::solve();
			continue;
		}
		/*if(B::check()){
			B::solve();
			continue;
		}*/
		for(int i=1;i<=n;i++)
			pre[i]=getprev(i);
		for(int i=1;i<=n;i++)
			nex[i]=getnext(i);
		LL ans=0;
		for(int i=1;i<=n;i++){
			f[i]=(Node){0,1};
			for(int j=i+1,pj,pv;j<=n;j++){
				if((pj=max(i,pre[j]))==j)
					break;
				f[j].v=(pv=f[pj].v)+1;
				f[j].c=f[pj].c;
				if((pj+1<j)&&(pv==f[pj+1].v)){
					f[j].c+=f[pj+1].c;
					if((pj+2<j)&&(pv==f[pj+2].v))
						f[j].c+=f[pj+2].c;
				}
				ans+=(f[j].c==2);
			}
		}
		write(ans);
	}
	return 0;
}
