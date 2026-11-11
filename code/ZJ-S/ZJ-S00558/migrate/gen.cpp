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
		srand(time(0));
		cout<<"0 10\n";
		fo(_,1,10)
		{
		int n=rand()%97+3;
		int a[101];
		m1(a,0);
		fo(i,1,100) a[i]=rand()%2001-1000;
		sort(a+1,a+101);
		n=unique(a+1,a+101)-a-1;
		cout<<n<<' '<<rand()%50+1<<endl; 
		fo(i,1,n) cout<<a[i]<<' ';
		cout<<endl;
		}
	}
}
signed main(){
	freopen("migrate.in","w",stdout);
	gza::main();
}
