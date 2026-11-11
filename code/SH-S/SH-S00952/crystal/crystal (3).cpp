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
		//代码长度限制50KB=50000B，即50000字符 
		//O(n)或O(nlogn)
		//小R有n颗能量水晶，其中第i(1≤i≤n)颗的能量值为整数ai。
		//小R想用其中若干颗能量水晶合成一颗大水晶，用于合成的水晶必须具有相同的
		//能量值。小R希望参与合成的水晶尽可能多。他可以进行.至.多m次操作。每次操作可
		//以任选一颗水晶，将其能量值增加1；同一颗水晶可以被重复选择。
		//你需要帮助小R求出，进行至多m次操作后，他最多能用多少颗能量水晶合成一
		//颗大水晶。
		const int N=1e6+1;
		int n,m,a[N]; 
		namespace My_Solution1
		{
			inline void main()
			{
				sort(a+1,a+n+1);
				int answer=0;
				for(int i=1;i<=n;++i){
					int mm=m;
					int combine=0;
					for(int j=i;j>=1;--j){
						int cost=a[i]-a[j];
						if(mm<cost) break;
						mm-=cost;
						++combine;
					}
					answer=max(answer,combine);
				}
				write(answer);
				return;
			}
		}
		namespace My_Solution2
		{
			inline void main()
			{
				sort(a+1,a+n+1);
				int answer=0;
				for(int i=1;i<=n;++i){
					int total_cost=0;
					int combine=0;
					for(int j=i;j>=1;--j){
						int cost=a[i]-a[j];
						if(total_cost+cost>m) break;
						total_cost+=cost;
						++combine;
					}
					answer=max(answer,combine);
				}
				write(answer);
				return;
			}
		}
		namespace My_Solution3
		{
			int *sum;
			inline void main()
			{
				sum=new int[N];
				sort(a+1,a+n+1);
				int answer=0;
				sum[0]=0;
				for(int i=1;i<=n;++i){
					sum[i]=sum[i-1]+a[i];
				}
				for(int i=1;i<=n;++i){
					//int total_cost=0;
					//int combine=0;
					for(int j=i;j>=1;--j){
						//a[i]次数：i-j+1
						//a[j]范围：j~i 
						//int cost=a[i]-a[j];
						//if(total_cost+cost>m) break;
						//total_cost+=cost;
						int total_cost=a[i]*(i-j+1)-(sum[i]-sum[j-1]);
						if(total_cost>m) break;
						//combine=i-j+1;
						answer=max(answer,i-j+1);
					}
					//answer=max(answer,combine);
				}
				write(answer);
				return;
			}
		}
		namespace My_Solution4
		{
			int *sum;
			inline void main()
			{
				sum=new int[N];
				sort(a+1,a+n+1);
				int answer=0;
				sum[0]=0;
				for(int i=1;i<=n;++i){
					sum[i]=sum[i-1]+a[i];
				}
				for(int i=1;i<=n;++i){
					for(int j=i;j>=1;--j){
						int total_cost=(a[i]*(i+1)-sum[i]);
						total_cost+=(sum[j-1]-a[i]*j);
						if(total_cost>m) break;
						answer=max(answer,i-j+1);
					}
				}
				write(answer);
				return;
			}
		}
		namespace My_Solution5
		{
			int *sum;
			inline void main()
			{
				sum=new int[N];
				sort(a+1,a+n+1);
				int answer=0;
				sum[0]=0;
				for(int i=1;i<=n;++i){
					sum[i]=sum[i-1]+a[i];
				}
				for(int i=1;i<=n;++i){
					int init_total_cost=(a[i]*(i+1)-sum[i]);
					int max_total_cost=m-init_total_cost;
					for(int j=i;j>=1;--j){
						//j越小，total_cost越大 
						int total_cost=(sum[j-1]-a[i]*j);
						if(total_cost>max_total_cost) break;
						answer=max(answer,i-j+1);
					}
				}
				write(answer);
				return;
			}
		}
		namespace My_Solution6
		{
			int *sum;
			//int *cost_pre;
			//sum[j-1]=a[1]+a[2]+...+a[j-1]，不包括a[i] 
			inline void main()
			{
				sum=new int[N];
				//cost_pre=new int[N];
				
				sort(a+1,a+n+1);
				int answer=0;
				sum[0]=0;
				for(int i=1;i<=n;++i){
					sum[i]=sum[i-1]+a[i];
				}
				for(int i=1;i<=n;++i){
					int init_total_cost=(a[i]*(i+1)-sum[i]);
					int max_total_cost=m-init_total_cost;
					//for(int j=i;j>=1;--j){
					//	int total_cost=(sum[j-1]-a[i]*j);
					//	if(total_cost>max_total_cost) break;
					//	answer=max(answer,i-j+1);
					//}
					int left=1,right=i;
					//要求的是： (sum[j-1]-a[i]*j)<=max_total_cost的最大j值
					//然后 answer=max(answer,i-j+1);
					auto check=[&](int j)
					{
						//随j的减小而增大 
						return (sum[j-1]-a[i]*j)<=max_total_cost;
					};
					int j=1;
					for(;left<=right;){
						int mid=(left+right)/2;
						if(check(mid)){
							j=mid;
							right=mid-1;
						}else{
							left=mid+1;
						}
					}
					answer=max(answer,i-j+1);
				}
				write(answer);
				return;
			}
		}
		inline void main()
		{
			n=read();m=read();
			for(int i=1;i<=n;++i) a[i]=read();
			if(n<=5000) My_Solution2::main();
			else My_Solution6::main();
			return;
		}
	}
	inline void main()
	{
		My_Code_Namespace::main();
		flush();
		return;
	}
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	SH_S00952huletian::main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
