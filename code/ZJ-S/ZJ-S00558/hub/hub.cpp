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
	
	const int N=1e6+10;
	int c,T;
	int n,k;
	vector<int> g[N];
	bool vis[N];
	int ofa[N];
	int dep[N],fa[N],maxdep[N];
	void dfs1(int u,int fa)
	{
		ofa[u]=fa;
		for(auto j:g[u]) if(j!=fa) dfs1(j,u);
	}
	int num;
	void dfs2(int u,int fa)
	{
		num++;
		dep[u]=dep[fa]+1;
		gza::fa[u]=fa;
		for(auto j:g[u]) if(j!=fa&&!vis[j]) dfs2(j,u);
	}
	void dfs3(int u,int fa)
	{
//		cout<<"dfs3: "<<u<<' '<<fa<<endl;
		maxdep[u]=0;
		for(auto j:g[u]) if(j!=fa&&!vis[j]) dfs3(j,u),maxdep[u]=max(maxdep[u],maxdep[j]+1);
	}
	int calc(int u,int mid)
	{
//		cout<<vis[u]<<' ';
//		cout<<endl;
		vis[u]=0;
//		cout<<"calc: "<<u<<' '<<mid<<endl;
//		fo(i,1,n) cout<<vis[i]<<' ';
//		cout<<endl;
		fo(i,1,n) dep[i]=0,fa[i]=0;
		num=0;
		dfs2(u,0);
//		if(u==312) cout<<num<<endl;
		int a=max_element(dep+1,dep+n+1)-dep;
		fo(i,1,n) dep[i]=0,fa[i]=0;
		dfs2(a,0);
		int b=max_element(dep+1,dep+n+1)-dep;
//		if(u==312)
//		{
//		cout<<a<<' '<<b<<' '<<dep[b]<<endl;
//		fo(i,1,n)cout<<fa[i]<<' ';
//		cout<<endl;
//		}
		vector<int> vec;
		vec.pb(b);
		int t=b;
		while(t!=a) t=fa[t],vec.pb(t);
//		fo(i,1,n)cout<<fa[i]<<' ';
//		cout<<endl;
		int dia=vec.size()-1;
		if(mid>=(dia+1)/2){vis[u]=1;return 1;}
		int rt=vec[vec.size()/2];
		fo(i,1,n) maxdep[i]=0;
		dfs3(rt,0);
//		cout<<a<<' '<<b<<endl;
//		cout<<"rt="<<u<<' '<<mid<<' '<<rt<<endl;
//		if(u==312)
//		{
//		fo(i,1,n) cout<<maxdep[i]<<' ';
//		cout<<endl;
//		}
		int cnt=0;
		fo(i,1,n) if(maxdep[i]>=mid) cnt++;
		vis[u]=1;
//		cout<<cnt<<endl;
		return cnt;
	}
	bool chk(int mid)
	{
		int minx=calc(1,mid);
		vis[1]=0;
		fo(i,2,n)
		{
			vis[i]=1;
			vis[ofa[i]]=1;
			int t1=calc(i,mid);
			int t2=calc(ofa[i],mid);
			minx=min(minx,t1+t2);
//			if(i==22) cout<<ofa[i]<<endl;
//			if(i==22) cout<<i<<' '<<calc(i,mid)<<' '<<calc(ofa[i],mid)<<endl;
			vis[i]=0,vis[ofa[i]]=0;
		}
//		cout<<minx<<endl;
		return minx<=k;
	}
	void solve(int _)
	{
		n=R,k=R;
		fo(i,1,n) vis[i]=0;
		fo(i,1,n) g[i].clear();
		fo(i,1,n-1)
		{
			int u=R,v=R;
			g[u].pb(v),g[v].pb(u); 
		}
		dfs1(1,0);
		int l=1,r=n;
		while(l<r)
		{
//			cout<<l<<' '<<r<<endl; 
			int mid=l+r>>1;
			if(chk(mid)) r=mid;
			else l=mid+1;
		}
		write(l),puts("");
	}
	void main(){
		c=R,T=R;
		fo(_,1,T) solve(_);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	gza::main();
}
