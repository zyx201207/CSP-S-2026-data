#include<bits/stdc++.h>
using namespace std;
namespace Hoks
{
	#define int long long
	#define ls (p<<1)
	#define rs (ls|1)
	#define mid ((l+r)>>1)
	namespace Fast_IO
	{
		static char buf[1000000],ot[1000000],*paa=buf,*pd=buf;int length=0;
		#define getchar() paa==pd&&(pd=(paa=buf)+fread(buf,1,1000000,stdin),paa==pd)?EOF:*paa++
		inline int read()
		{
			char c(getchar());int x(0),t(1);
			while(!isdigit(c)){if(c=='-') t=-t;c=getchar();}
			while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
			return x*t;
		}
		inline void flush(){fwrite(ot,1,length,stdout);length=0;}
		inline void put(char c){if(length==999999) flush();ot[length++]=c;}
		inline void put(string s){for(char c:s) put(c);}
		inline void print(int x)
		{
			if(x<0) put('-'),x=-x;
			if(x>9) print(x/10);
			put((char)(x%10+(int)'0'));
		}
	}
	using namespace Fast_IO;
	const int N=2e6+10,INF=0x3f3f3f3f3f3f3f3f;
	int n,d,ans,a[N],r[N],f[N][6];//0:1 1:11 2:11x 3:1x(x>1) 4:2x 5:2
	inline int solve(int x,int s)
	{
		if(f[x][s]!=-1) return f[x][s];
		if(r[x]==x) return f[x][s]=0;
		if(s==0)
		{
			if(r[x]-x>=3) return f[x][s]=solve(r[x],2);
			if(r[x]-x>=2) return f[x][s]=solve(r[x],1);
			return f[x][s]=solve(r[x],0);
		}
		if(s==1)
		{
			int r1=r[x-1],r2=r[x];
			if(r1==r2&&r1-x==1) return f[x][s]=r1-x+solve(r2,5); 
			if(r1==r2) return f[x][s]=r1-x+solve(r2,4);
			if(r2-r1==1&&r1>x) return f[x][s]=r1-x+solve(r2,3);
			if(r2-max(x+1,r1)>=2) return f[x][s]=r1-x+solve(r2,2);
			if(r2-x==2&&r1==x) return f[x][s]=r1-x+solve(r2,1);
			return f[x][s]=r1-x+solve(r2,0);
		}
		if(s==2)
		{
			int r1=r[x-2],r2=r[x-1],r3=r[x];
			if(r1==r2&&r2==r3) return f[x][s]=0;
			if(r2==r3&&r2-x==1&&r1==x) return f[x][s]=r2-r1+solve(r3,5); 
			if(r2==r3&&r2>r1) return f[x][s]=r2-r1+solve(r3,4);
			if(r3-r2==1&&r2>x) return f[x][s]=r2-r1+solve(r3,3);
			if(r3-max(r2,x+1)>=2) return f[x][s]=r2-r1+solve(r3,2);
			if(r3-x==2&&r2==x) return f[x][s]=r2-r1+solve(r3,1);
			return f[x][s]=r2-r1+solve(r3,0);
		}
		if(s==3)
		{
			int r1=r[x-1],r2=r[x];
			if(r2==r1) return f[x][s]=0;
			if(r2-r1==1&&r1>x) return f[x][s]=solve(r2,3);
			if(r2-max(r1,x+1)>=2) return f[x][s]=solve(r2,2);
			if(r2-x==2&&r1==x) return f[x][s]=solve(r2,1);
			return f[x][s]=solve(r2,0);
		}
		if(s==4)
		{
			int r1=r[x-1],r2=r[x];
			if(r2==r1) return f[x][s]=0;
			if(r2==x+1) return f[x][s]=r2-r1+solve(r2,5);
			return f[x][s]=r2-r1+solve(r2,4);
		}
		if(s==5)
		{
			if(r[x]-x>1) return f[x][s]=r[x]-x+solve(r[x],4);
			return f[x][s]=r[x]-x+solve(r[x],5);
		}
		cout<<"why here";return f[x][s]=114514;
	}
	inline void solve()
	{
		n=read(),d=read();
		for(int i=1;i<=n;i++) f[i][0]=f[i][1]=f[i][2]=f[i][3]=f[i][4]=f[i][5]=-1;
		for(int i=1;i<=n;i++) a[i]=read();ans=0;
		for(int i=n,x=n;i>=1;i--)
		{
			while(a[x]-a[i]>d) x--;
			r[i]=x;
		}
//		for(int i=1;i<=n;i++) cout<<r[i]<<" ";
		for(int i=1;i<=n;i++) ans+=solve(i,0),a[i]=0
			;
//			,cout<<solve(i,0)<<" ";cout<<endl;
//		cout<<solve(4,5)<<" ";
//		for(int i=n;i>=1;i--) ans-=a[r[i]],a[i]=a[r[i]]+1;
//		cout<<f[4][1]<<" ";
		print(ans);put('\n');
	}
	inline void main()
	{
		int T=1;
//		cout<<(sizeof(f)+sizeof(a))/1024.0/1024<<" ";
		read();
		T=read();
		while(T--) solve();
		flush();return;
	}
}
signed main()
{
//	system("fc migrate5.ans migrate.out");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	Hoks::main();
	genshin:;return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
/*
0 1
10 160
15 44 47 195 223 281 382 511 556 853 
*/
/*
0 1
8 326
62 118 308 422 670 679 802 857 
*/
/*
调不出来写对拍是对的！！！！！！！！！！！！！！
哎这把唐了，本来可以 5:00 前过的 
*/
