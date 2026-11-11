#include<bits/stdc++.h>
typedef long long LLLLLLLL;
#define int LLLLLLLL
using namespace std;
namespace SH_S00952huletian
{
	//我是洛谷封禁用户，诚恳请求洛谷管理员解除对我洛谷账户的封禁。 
	//解压密码：Oct31==Dec25?
	namespace fastIO
	{
		const int BUFFER_SIZE=1e6+1,STACK_SIZE=1e2+1;
		int top;
		char stack[STACK_SIZE];
		char in_buf[BUFFER_SIZE],out_buf[BUFFER_SIZE];
		int in_len=0,in_pos=0,out_pos=0;
		inline char getchar()
		{
			if(in_pos==in_len){
				in_pos=0;
				in_len=fread(in_buf,1,BUFFER_SIZE,stdin);
				if(in_len==0) return EOF;
			}
			return in_buf[in_pos++];
		}
		inline void flush()
		{
			fwrite(out_buf,1,out_pos,stdout);
			out_pos=0;
		}
		inline void putchar(char ch)
		{
			if(out_pos==BUFFER_SIZE) flush();
			out_buf[out_pos++]=ch;
		}
		inline char get_char()
		{
			char ch=getchar();
			for(;ch<=32;ch=getchar());
			return ch;
		}
		inline int read()
		{
			int x=0,f=1;
			char ch=getchar();
			for(;ch<'0'||ch>'9';ch=getchar()){
				if(ch=='-') f=-1;
				if(ch==EOF) return EOF;
			}
			for(;ch>='0'&&ch<='9';ch=getchar()){
				x=x*10+ch-'0';
			}
			return x*f;
		}
		inline void write(int x)
		{
			if(x==0){
				putchar('0');
				return;
			}
			if(x<0){
				putchar('-');
				x=-x;
			}
			for(top=0;x!=0;x/=10)
				stack[++top]=x%10+'0';
			for(;top>0;--top)
				putchar(stack[top]);
		}
	}
	using fastIO::get_char;
	using fastIO::read;
	using fastIO::write;
	using fastIO::getchar;
	using fastIO::putchar;
	using fastIO::flush;
	namespace My_Code_Namespace
	{
		//Trick||Treat!
		//2026 CCF 非专业级软件能力认证CSP-J/S 2026 第二轮
		const int N=1e6+1,INF=1e18;
		int c,n,m,d,q;
		//bool st;
		int w[N],k[N];
		vector<int> a[N],t[N];
		int x[N],y[N];
		//bool ed;
		int answer[N];
		namespace My_Solution1
		{
			//往返耗时相同 
			//SH-S0001yanxuefeng
			//SH-S0001yangxuefeng
			//galaxy,game,holiday,transmit
			//q次手动执行get_transfer函数（非递归） 
			//vector<vector<int> > edge;
			map<int,map<int,int> > dp;
			//，B市的地铁网络是连通的，
			//即任意两个地铁站都可以通过若干条线路互相到达
			inline int get_transfer(int x,int y)
			{
				if(x==y) return 0;
				//if(x>y) swap(x,y);
				if(dp[x].count(y)) return dp[x][y];
				int answer=INF;
				dp[x][y]=answer;
				for(int line=1;line<=n;++line)
					for(int i=1;i<=k[line];++i)
						if(a[line][i]==x){
							//坐线路line
							for(int j=1;j<=k[line];++j)
								if(x!=a[line][j])
									answer=min(answer,t[line][i]+t[line][j]+get_transfer(a[line][j],y));
						}
				return dp[x][y]=answer;
			}
			inline void main()
			{
				for(int i=1;i<=q;++i){
					dp.clear();
					answer[i]=w[x[i]]+w[y[i]]+get_transfer(x[i],y[i]);
				}
				//每个出行计划的总步行时间为进出站和换乘的步行时间之和
				return ;
			}
		}
		inline void solve()
		{
			My_Solution1::main();
			return;
		}
		inline void main()
		{
			//空间限制：1024MB 
			//cerr<<(int(&st-&ed)/1024/1024)<<"MB"<<endl;
			c=read();n=read();m=read();d=read();q=read();
			for(int i=1;i<=m;++i) w[i]=read();
			for(int i=1;i<=n;++i){
				k[i]=read();
				a[i]=vector<int>(k[i]+1,0);
				t[i]=vector<int>(k[i]+1,0);
				for(int j=1;j<=k[i];++j){
					a[i][j]=read();
					t[i][j]=read();
				}
			}
			for(int i=1;i<=q;++i){
				x[i]=read();
				y[i]=read();
			}
			solve();
			for(int i=1;i<=q;++i){
				write(answer[i]);
				putchar('\n');
			}
			return;
		}
	}
	inline void main()
	{
		//int x=read();while(x!=EOF){write(x);putchar(' ');x=read();}
		My_Code_Namespace::main();
		flush();
		return;
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cout<<((string)"SH-S00952huletian"=="SH-S00952huletian")<<endl;
	SH_S00952huletian::main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
