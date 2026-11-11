#include<bits/stdc++.h>

using namespace std;
#define cute_fzj_kuai_ruarua ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
namespace IO
{
	#define isdight(x) ('0'<=(x)&&(x)<='9')
	#define SIZE (1<<20)
	char buf[SIZE],out[SIZE],*p1=buf,*p2=buf,*p3=out;
	#define getchar() (p1==p2&&(p1=buf,p2=buf+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++)
	#define flush() (fwrite(out,1,p3-out,stdout),p3=out)
	#define putchar(ch) (p3==out+SIZE&&flush(),*p3++=(ch))
	class Flush{public:~Flush(){flush();}}_;
	inline int read()
	{
		int x=0,f=1;
		char ch=getchar();
		for(;!isdight(ch);ch=getchar()) if(ch=='-') f=-1;
		for(;isdight(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
		return x*f;
	 } 
	inline void write(long long x)
	{
		if(x<0)x=-x,putchar('-'); 
		static short Stack[70],top(0);
		do{Stack[++top]=x%10,x/=10;}while(x);
		while(top)putchar(Stack[top--]^48);
		putchar('\n');
	}
	#undef SIZE
	#undef putchar
	#undef flush
	#undef getchar
}using IO::read;using IO::write;
const int N=5e5+10,M=510;
const long long INF=0x3f3f3f3f3f3f3f3f;
int n,m,q;
int w[N];
vector<pair<int,int> > have[N];
long long f[M][M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cute_fzj_kuai_ruarua;
	int C,D;
//	cin>>C>>n>>m>>D>>q;
	C=read(),D=read(),n=read(),m=read(),D=read(),q=read(); 
//	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int k=read();
//		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u=read(),v=read();
//			cin>>u>>v;
			have[u].push_back(make_pair(i,v));
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++)
		for(auto e1:have[i])
			for(auto e2:have[i])
				f[e1.first][e2.first]=min(f[e1.first][e2.first],(long long)e1.second+e2.second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x=read(),y=read();
//		cin>>x>>y;
		long long ans=INF;
		for(auto e1:have[x])
			for(auto e2:have[y])
				ans=min(ans,f[e1.first][e2.first]+e1.second+e2.second);
//		cout<<ans+w[x]+w[y]<<endl;
		write(ans+w[x]+w[y]);
	}
	return 0;
 }
