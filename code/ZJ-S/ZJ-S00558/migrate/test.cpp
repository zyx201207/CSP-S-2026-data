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
		system("copy migrate1.in migrate.in");
		system("migrate.exe");
		system("fc migrate1.ans migrate.out");
		system("copy migrate2.in migrate.in");
		system("migrate.exe");
		system("fc migrate2.ans migrate.out");
		system("copy migrate3.in migrate.in");
		system("migrate.exe");
		system("fc migrate3.ans migrate.out");
		system("copy migrate4.in migrate.in");
		system("migrate.exe");
		system("fc migrate4.ans migrate.out");
		system("copy migrate5.in migrate.in");
		system("migrate.exe");
		system("fc migrate5.ans migrate.out");
		system("copy migrate6.in migrate.in");
		system("migrate.exe");
		system("fc migrate6.ans migrate.out");
	}
}
signed main(){
	gza::main();
}
