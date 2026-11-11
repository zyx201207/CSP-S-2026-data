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
			//migrate
			//C:\Users\Administrator\Desktop\SH-S00952huletian\migrate\migrate.exe
			//-O2 -std=c++14 -static -Wl,-stack=1073741824
			const int N=2e6+1,INF=1e18;
			int n,d,x[N];
			namespace My_Solution1
			{
				/*
				vector<int> distance;
				struct node{
					int u,distance;
					node()
					{
						u=0;
						distance=0;
					}
					node(int hlt1,int hlt2)
					{
						u=hlt1;
						distance=hlt2;
					}
				};
				inline node new_node(int u)
				{
					return node(u,distance[u]);
				}
				inline bool operator<(node a,node b)
				{
					return a.distance>b.distance;
				}
				*/
				vector<vector<int> > edge;
				inline int abs(int x)
				{
					if(x<0) return -x;
					return x;
				}
				int tag,*visit;
				int *count;
				//int *distance;
				vector<int> distance;
				/*
				inline void Dijkstra(int u)
				{
					priority_queue<node> q;
					distance=vector<int>(n+1,INF);
					distance[u]=0;
					++tag;
					//visit[u]=tag;
					q.push(new_node(u));
					while(!q.empty()){
						u=q.top().u;
						q.pop();
						if(visit[u]==tag) continue;
						visit[u]=tag;
						for(int v : edge[u]){
							if(distance[v]<distance[u]+1) continue;
							if(distance[v]==distance[u]+1) ++count[v];
							else{
								count[v]=1;
								distance[v]=distance[u]+1;
							}
							q.push(new_node(v));
						}
					}
				}
				*/
				inline void BFS(int u)
				{
					queue<int> q;
					q.push(u);
					distance=vector<int>(n+1,INF);
					distance[u]=0;
					//++tag;
					//visit[u]=tag;
					count[u]=1;
					for(;!q.empty();){
						u=q.front();
						q.pop();
						for(int v : edge[u]){
							if(distance[v]<distance[u]+1) continue;
							if(distance[v]==distance[u]+1) ++count[v];
							else{
								distance[v]=distance[u]+1;
								count[v]=1;
							}
							q.push(v);
						}
					}
				}
				int answer;
				inline void main()
				{
					//visit=new int[N];
					count=new int[n+1];
					//distance = new int[N];
					edge=vector<vector<int> >(n+1,vector<int>());
					for(int i=1;i<n;++i)
						for(int j=i+1;j<=n;++j){
							if(x[j]-x[i]<=d){
								edge[i].push_back(j);
								edge[j].push_back(i);
							}else{
								break;
							}
						}
					answer=0;//双径岛屿对的数量
					for(int u=1;u<n;++u){
						for(int v=1;v<=n;++v)
							count[v]=0;
						//Dijkstra(u);
						BFS(u);
						for(int v=u+1;v<=n;++v)
							if(count[v]==2) ++answer;
					}
					write(answer);
					return;
				}
			}
			inline void solve_migrate()
			{
				My_Solution1::main();
				return;
			}
			inline void main()
			{
				n=read();d=read();
				for(int i=1;i<=n;++i) x[i]=read();
				solve_migrate();
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
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//cout<<((string)"SH-S00952huletian"=="SH-S00952huletian")<<endl;
	SH_S00952huletian::main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
