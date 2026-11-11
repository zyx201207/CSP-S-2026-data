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
	
	const int N=2e6+10;
	int c,T;
	int n,d,ans;
	int x[N],a[N];
	int lft[N],rgt[N];
	int f[N],g[N],res[N],mul[N],ac[N];
	bool chk(int x,int y)
	{
		vector<int> v1,v2;
		v1.pb(x);
		int t=x;
		while(rgt[t]<y) t=rgt[t],v1.pb(t);
		v1.pb(y);
		v2.pb(y);
		t=y;
		while(lft[t]>x) t=lft[t],v2.pb(t);
		v2.pb(x);
		reverse(v2.begin(),v2.end());
		int sum=0;
		if(v1.size()!=v2.size()){puts("???");return 0;}
		fo(i,0,(int)v1.size()-1) sum+=v1[i]-v2[i];
		return sum==1;
	}
	void work(int l,int r)
	{
//		cout<<l<<' '<<r<<endl;
		fo(i,l,r) a[i-l+1]=x[i];
		int n=r-l+1;
		fo(i,0,n+1) lft[i]=rgt[i]=f[i]=res[i]=mul[i]=ac[i]=g[i]=0;
		fo(i,1,n)
		{
			if(i==1) rgt[i]=1;
			else rgt[i]=rgt[i-1];
			while(rgt[i]<n&&a[rgt[i]+1]-a[i]<=d) rgt[i]++;
		}
		rep(i,n,1)
		{
			if(i==n) lft[i]=n;
			else lft[i]=lft[i+1];
			while(lft[i]>1&&a[i]-a[lft[i]-1]<=d) lft[i]--;
		}
		int j=n;
		rep(i,n,1)
		{
			mul[i]=1;
			if(i!=n&&lft[rgt[i]]==i)
			{
				j=min(j,rgt[i]-1);
				while(j>i&&lft[j-1]==i) j--;
//				if(i==5) cout<<i<<' '<<rgt[i]<<' '<<j<<endl;
				mul[i]+=mul[rgt[i]];
				if(lft[j]==i) mul[i]+=max(0ll,rgt[i]-1-j+1);
			}
		}//双还能延续多少
		fo(i,1,n) fo(j,i+1,n) if(chk(i,j)) ac[i]++;
		fo(i,1,n) ans+=ac[i];
	}
	void solve(int _)
	{
		n=R,d=R;
		fo(i,1,n) x[i]=R;
//		if(_==4)
//		{
//			cout<<"0 1\n";
////			cout<<"OOOK\n";
//			cout<<n<<' '<<d<<endl;
//			fo(i,1,n) cout<<x[i]<<' ';
//			cout<<endl;
//			return;
//		}
		ans=0;
		fo(i,1,n)
		{
			int j=i;
			while(j<n&&x[j+1]-x[j]<=d) j++;
			work(i,j),i=j;
		}
//		cout<<"ans:\n";
		write(ans),puts("");
	}
	void main(){
		c=R,T=R;
//		T=1;
		fo(_,1,T) solve(_);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("std.out","w",stdout);
	gza::main();
}
