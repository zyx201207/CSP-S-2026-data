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
	int n,d,ans,a[N],r[N],b[15],c[15];
	inline bool check(int x,int y)
	{
		memset(b,0,sizeof b);b[x]=1;
		memset(c,0x3f,sizeof c);c[x]=0;
		for(int i=x;i<=y;i++)
		{
			for(int j=i+1;j<=y;j++)
			{
				if(a[j]-a[i]>d) break;
				if(c[j]>c[i]+1) c[j]=c[i]+1,b[j]=0;
				if(c[j]==c[i]+1) b[j]+=b[i];
			}
		}return b[y]==2;
	}
	inline void solve()
	{
		for(int i=1;;i++)
		{
			freopen("x.in","w",stdout);
			cout<<i<<endl;
			fclose(0);
			system("gen.exe");
			system("force.exe");
			system("std.exe");
			freopen("std.out","r",stdin);
			int x=read();
			freopen("force.out","r",stdin);
			int y=read();
			if(x!=y) break;
			cout<<i<<" ok\n";
		}
	}
	inline void main()
	{
		int T=1;
//		cout<<(sizeof(f)+sizeof(a))/1024.0/1024<<" ";
		while(T--) solve();
		flush();return;
	}
}
signed main()
{
//	system("fc migrate6.ans migrate.out");
	
	Hoks::main();
	genshin:;return 0;
}
