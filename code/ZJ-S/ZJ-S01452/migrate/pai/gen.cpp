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
	int p,a[N];
	inline int get(int l,int r)
	{
		int len=r-l+1;
		return rand()%len+l;
	}
	inline void solve()
	{
		mt19937_64 rng(p);
		int n=8,d=get(1,1000);
		put("0 1\n");
		print(n);put(' ');print(d);put('\n');
		for(int i=1;i<=n;i++) a[i]=get(1,1000);sort(a+1,a+1+n); 
		for(int i=1;i<=n;i++) print(a[i]),put(' ');put('\n');
	}
	inline void main()
	{
		int T=1;
//		cout<<(sizeof(f)+sizeof(a))/1024.0/1024<<" ";
		srand(read());
//		T=read();
		while(T--) solve();
		flush();return;
	}
}
signed main()
{
//	system("fc migrate6.ans migrate.out");
	freopen("x.in","r",stdin);
	freopen("rand.in","w",stdout);
	Hoks::main();
	genshin:;return 0;
}
