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
		int c,t;
		namespace My_Solution
		{
			const int N=2e6+1,INF=1e18;
			int n,k,u[N],v[N];
			namespace My_Solution1
			{
				//多测清空 
				int *city;
				set<int> city_set;
				int answer;
				//n座城市中，选择恰好k座城市
				vector<vector<int> > edge; 
				inline void add_edge(int u,int v)
				{
					edge[u].push_back(v);
					edge[v].push_back(u);
				}
				int tag,*visit;
				int block;
				inline void dfs_block(int x)
				{
					if(visit[x]==tag) return;
					visit[x]=tag;
					for(int y : edge[x]){
						if(city_set.count(y)){
							dfs_block(y);
						}
					}
				}
				inline bool check()
				{
					//检查：S 在T 中形成的连通块数量不超过2
					//len(S)=k已经保证
					 ++tag;
					 block=0;
					 city_set.clear();
					 for(int i=1;i<=k;++i){
					 	city_set.insert(city[i]);
					 }
					 for(int i=1;i<=k&&block<=2;++i)
					 	if(visit[city[i]]!=tag){
						 	dfs_block(city[i]);
							++block;
						 }
					if(block<=2) return true;
					return false;
				}
				vector<int> distance;
				inline void BFS(int u)
				{
					queue<int> q;
					q.push(u);
					distance=vector<int>(n+1,INF);
					distance[u]=0;
					for(;!q.empty();){
						u=q.front();
						q.pop();
						for(int v : edge[u]){
							if(distance[v]<=distance[u]+1) continue;
							distance[v]=distance[u]+1;
							q.push(v);
						}
					}
				}
				inline int d_work(int u)
				{
					//.通 .勤 .距 .离
					BFS(u);
					int result=INF;
					for(int i=1;i<=k;++i)
						result=min(result,distance[city[i]]);
					return result;
				}
				inline int r_work()
				{
					//定义该建造方案的 .通 .勤 .半 .径为所有城市通勤距离的最大值
					int result=0;
					for(int i=1;i<=n;++i)
						if(!city_set.count(i)) result=max(result,d_work(i));
					return result;
				}
				inline void work()
				{
					//city[1~k]
					//所有合理的建造方案的通勤半径的最小值
					answer=min(answer,r_work());
					return;
				}
				inline void dfs(int x)
				{
					if(x>k){
						if(check()) work();
						return;
					}
					for(int i=city[x-1]+1;i<=n;++i){
						city[x]=i;
						dfs(x+1);
					}
				}
				inline void main()
				{
					city=new int[n+1];
					visit=new int[n+1];
					edge=vector<vector<int> >(n+1,vector<int>());
					for(int i=1;i<n;++i){
						add_edge(u[i],v[i]);
					}
					city[0]=0;
					answer=INF;
					dfs(1);
					write(answer);
					return;
				}
			}
			inline void solve_the_problem()
			{
				My_Solution1::main();
				return;
			}
			inline void main()
			{
				n=read();k=read();
				for(int i=1;i<n;++i){
					u[i]=read();
					v[i]=read();
				}
				solve_the_problem();
				putchar('\n');
				return;
			}
		}
		inline void main()
		{
			c=read();t=read();
			for(int i=1;i<=t;++i) My_Solution::main();
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
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//cout<<((string)"SH-S00952huletian"=="SH-S00952huletian")<<endl;
	SH_S00952huletian::main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
