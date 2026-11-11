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
		ofstream fi_res("final_result.txt");
		inline void judge(int data)
		{
			string problem;
			ifstream pro("problem.txt");
			pro>>problem;
			pro.close();
			ofstream dat("data.txt");
			dat<<data;
			dat.close();
			system("cp.exe");
			system((problem+".exe").c_str());
			system("fc.exe");
			ifstream res("result.txt");
			string result;
			res>>result;
			res.close();
			fi_res<<data<<result<<endl;
		}
		inline void main()
		{
			for(int i=1;i<=7;++i) judge(i);
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
	//cout<<((string)"SH-S00952huletian"=="SH-S00952huletian")<<endl;
	SH_S00952huletian::main();
	return 0;
}
