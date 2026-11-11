#include<algorithm>
#include<cstdio>
using namespace std;
using LL=long long;
template<class T>
inline void chkmax(T &x,T y){
	(x<y)&&(x=y,true);	return;
}
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
inline void write(int x){
	(x<0)&&(pc('-'),x=-x);
	static int stk[10];	int top=0;
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
const int N=500010;
int n;	LL m;	LL a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();	m=read<LL>();
	for(int i=1;i<=n;i++)
		a[i]=read<LL>();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	int ans=0;
	for(int i=1,j=1;i<=n;i++){
		LL v=a[i]-a[i-1];
		while(v*(i-j+1)-(a[i]-a[j-1])>m)
			j++;
		chkmax(ans,i-j+1);
	}
	write(ans);
	return 0;
}
