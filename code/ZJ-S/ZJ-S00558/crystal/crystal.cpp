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
	
	const int N=5e5+10;
	int n,m,ans;
	int a[N];
	void main(){
		n=R,m=R;
		int l=1;
		fo(i,1,n) a[i]=R;
		sort(a+1,a+n+1);
		int sum=0;
		fo(r,1,n)
		{
			sum+=a[r];
			while((r-l+1)*a[r]-sum>m) sum-=a[l],l++;
			ans=max(ans,r-l+1);
		}
		write(ans);
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	gza::main();
}
