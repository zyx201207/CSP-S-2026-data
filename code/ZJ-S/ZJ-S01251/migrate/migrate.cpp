#include<bits/stdc++.h>
namespace chuazen{
	#define ufor(i,x,y) for(int i=x;i<=y;i++)
	#define dfor(i,x,y) for(int i=x;i>=y;i--)
	#define N 2000005
	char out[100],ch; int tp;
	#define int long long
	#define getchar() (p1==p2&&(p2=(p1=in)+fread(in,1,1<<21,stdin),p1==p2)?EOF:*p1++)
	char in[1<<21],*p1,*p2;
	inline int read(){
		int x=0,f=1; ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
		while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
		return x*f;
	}
	inline void write(int x){
		if(x<0)putchar('-'),x=-x;
		tp=0;
		do out[++tp]=x%10+'0', x/=10; while(x);
		while(tp)putchar(out[tp--]);
	}
}
using namespace std;
using namespace chuazen;

int c,T,n,d,x[N];
int tmpx, tmpy;
int mf,num,ans;

inline void pian1(){
	int m=d/x[1];
	if(m<2){puts("0"); return;}
	write(max(0ll,n-m*2+1)),putchar('\n');
}

inline void dfs(int nw,int ed,int fly){
	if(nw==ed){
		if(fly<mf)mf=fly, num=0;
		if(fly==mf)num++;
		return;
	}
	int dis=0;
	ufor(i,nw+1,ed){
		dis+=x[i];
		if(dis>d)break;
		dfs(i,ed,fly+1);
	}
}

inline void brute(){
	ans=0;
	ufor(st,0,n-2)ufor(ed,st+1,n-1){
		mf=0x3f3f3f3f3f3f3f3f, num=0;
		dfs(st,ed,0);
		if(num==2)ans++;
	}
	write(ans),putchar('\n');
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	c=read(), T=read();
	while(T--){
		n=read(), d=read(), tmpx=read();
		ufor(i,1,n-1)tmpy=read(), x[i]=tmpy-tmpx, tmpx=tmpy;
		if(c==11||c==12)pian1();
		else brute();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
