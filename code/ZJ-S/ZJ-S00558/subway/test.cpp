#include<bits/stdc++.h>
using namespace std;
namespace gza{
	#define int long long
	#define R read()
	#define fo(i,a,b) for(int i=a;i<=b;i++)
	#define rep(i,a,b) for(int i=a;i>=b;i--)
	#define pc putchar
	#define pb push_back
	#define m1(a,b) memset(a,b,sizeof a)
	namespace IO{
		inline int read()
		{
			int x=0,flg=0;
			char ch=getchar();
			while(!isdigit(ch)){if(ch=='-') flg=1;ch=getchar();}
			while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
			if(flg) return -x;
			return x; 
		}
		template<typename T> inline void write(T x)
		{
			if(x<0) pc('-'),x=-x;
			if(x>9) write(x/10);
			pc(x%10+'0'); 
		}
	}
	using namespace IO;
	
	
	void main(){
		system("copy subway1.in subway.in");
		system("subway.exe");
		system("fc subway1.ans subway.out");
		system("copy subway2.in subway.in");
		system("subway.exe");
		system("fc subway2.ans subway.out");
		system("copy subway3.in subway.in");
		system("subway.exe");
		system("fc subway3.ans subway.out");
		system("copy subway4.in subway.in");
		system("subway.exe");
		system("fc subway4.ans subway.out");
	}
}
signed main(){
	gza::main();
}
