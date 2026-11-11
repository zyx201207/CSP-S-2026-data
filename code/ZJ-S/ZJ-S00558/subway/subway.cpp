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
	
	const int N=510,M=5e5+10;
	int c,n,m,d,q;
	int w[M];
	vector<pair<int,int> > on[M];
	int dis[N][N]; 
	void main(){
		c=R,n=R,m=R,d=R,q=R;
		fo(i,1,m) w[i]=R;
		fo(i,1,n)
		{
			int k=R;
			fo(j,1,k)
			{
				int a=R,t=R;
				on[a].pb({i,t});
			}
		}
		m1(dis,0x3f);
		fo(i,1,n) dis[i][i]=0;
		fo(a,1,m)
		{
			for(auto i:on[a]) for(auto j:on[a]) dis[i.first][j.first]=min(dis[i.first][j.first],i.second+j.second);
		}
		fo(k,1,n) fo(i,1,n) fo(j,1,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		while(q--)
		{
			int x=R,y=R,pre=w[x]+w[y],ans=1e18;
			for(auto i:on[x]) for(auto j:on[y]) ans=min(ans,dis[i.first][j.first]+i.second+j.second);
			write(ans+pre),puts("");
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	gza::main();
}
