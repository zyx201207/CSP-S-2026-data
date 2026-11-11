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
		system("copy hub1.in hub.in");
		system("hub.exe");
		system("fc hub1.ans hub.out");
		system("copy hub2.in hub.in");
		system("hub.exe");
		system("fc hub2.ans hub.out");
		system("copy hub3.in hub.in");
		system("hub.exe");
		system("fc hub3.ans hub.out");
		system("copy hub4.in hub.in");
		system("hub.exe");
		system("fc hub4.ans hub.out");
		system("copy hub5.in hub.in");
		system("hub.exe");
		system("fc hub5.ans hub.out");
		system("copy hub6.in hub.in");
		system("hub.exe");
		system("fc hub6.ans hub.out");
	}
}
signed main(){
	gza::main();
}
