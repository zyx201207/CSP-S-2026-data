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
	const int N=5e2+10,M=5e5+10,NM=22,INF=0x3f3f3f3f3f3f3f3f;
	int n,m,q,a[N][N],b[M],c[M];vector<int>d[N],bl[M],t[M];
	inline void solve()
	{
		memset(a,0x3f,sizeof a);
		n=read(),m=read();read();q=read();
		for(int i=1;i<=m;i++) b[i]=read();
		for(int i=1,y;i<=n;i++)
		{
			y=read();a[i][i]=0;
			for(int j=1,x;j<=y;j++)
				d[i].emplace_back(x=read()),bl[x].emplace_back(i),t[x].emplace_back(read());
		}
		for(int i=1;i<=m;i++) c[i]=bl[i].size();
		for(int i=1;i<=n;i++) for(int j:d[i])
		{
			int s=0;for(int l=0;l<c[j];l++) if(bl[j][l]==i) s=t[j][l];
			for(int l=0;l<c[j];l++) if(bl[j][l]!=i)
				a[bl[j][l]][i]=a[i][bl[j][l]]=min(a[i][bl[j][l]],s+t[j][l]);
		}
		for(int k=1;k<=n;k++) for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";
//			cout<<endl;
//		}
		for(int i=1,x,y;i<=q;i++)
		{
			x=read(),y=read();int s=INF;
//			s=0;
			for(int j=0;j<c[x];j++) for(int l=0;l<c[y];l++)
			{
				s=min(s,t[x][j]+t[y][l]+a[bl[x][j]][bl[y][l]]);
//				if(i==1) cout<<t[x][j]+t[y][l]+a[bl[x][j]][bl[y][l]]<<" "<<j<<" "<<l<<" "<<x<<" "<<y<<endl;
			}
				
			print(s+b[x]+b[y]);put('\n');
		}
	}
	inline void main()
	{
		int T=1;
//		T=read();
		read();
		while(T--) solve();
		flush();return;
	}
}
signed main()
{
//	system("fc subway6.ans subway.out");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Hoks::main();
	genshin:;return 0;
}
