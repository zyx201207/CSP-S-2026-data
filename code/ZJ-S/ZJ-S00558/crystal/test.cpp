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
		system("copy crystal1.in crystal.in");
		system("crystal.exe");
		system("fc crystal1.ans crystal.out");
		system("copy crystal2.in crystal.in");
		system("crystal.exe");
		system("fc crystal2.ans crystal.out");
		system("copy crystal3.in crystal.in");
		system("crystal.exe");
		system("fc crystal3.ans crystal.out");
		system("copy crystal4.in crystal.in");
		system("crystal.exe");
		system("fc crystal4.ans crystal.out");
	}
}
signed main(){
	gza::main();
}
