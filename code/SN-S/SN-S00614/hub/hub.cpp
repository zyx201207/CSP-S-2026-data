#include<iostream>
#include<vector>
using namespace std;
constexpr int N=2e5+5,INF=1e9;
bool Beg;
int C,n,k;
struct Edge{ int u,v; }e[N];

namespace Solve1{
	vector<int> v[N];
	int tg[N],dep[N];
	int st[N],tp;
	int ST[15][N];
	void add(int x,int y){
		v[x].push_back(y);
		v[y].push_back(x);
	}
	void Dfs(int x){
		tg[x]=1;
		for(int u:v[x])
			if(!tg[u])Dfs(u);
	}
	void dfs1(int x,int f){
		for(int u:v[x])if(u!=f)
			dep[u]=dep[x]+1,dfs1(u,x);
	}
	bool dfs2(int x,int f,int y){
		bool flag=(x==y);
		for(int u:v[x])
			if(u!=f)flag|=dfs2(u,x,y);
		if(flag)st[++tp]=x;
		return flag;
	}
	void dfs3(int x,int f){
		ST[0][x]=f;
		for(int u:v[x])
			if(u!=f)dfs3(u,x);
	}
	int Get_rt(int x,bool b){
		dfs1(x,0);
		for(int i=1;i<=n;i++)
			if(tg[i]==b&&dep[i]>=dep[x])x=i;
		dfs1(x,0); int y=0;
		for(int i=1;i<=n;i++)
			if(tg[i]==b&&dep[i]>=dep[y])y=i;
		tp=0,dfs2(x,0,y);
		int rt=st[tp/2+1];
		dfs3(rt,0);
		return rt;
	}
	int Get_fa(int x,int k){
		for(int i=__lg(n);i>=0;i--)
			if((k>>i)&1)x=ST[i][x],k-=(1<<i);
		return x;
	}
	bool check(int x,int U,int V){
		for(int i=1;i<=n;i++)tg[i]=0;
		tg[U]=tg[V]=1;
		for(int i=1;i<=n;i++){
			int f=Get_fa(i,x);
			while(!tg[f])tg[f]=1,f=ST[0][f];
		}
		int C=0;
		for(int i=1;i<=n;i++)C+=tg[i];
		return (C<=k);
	}
	int Get_Ans(){
		Dfs(1); int rt=0;
		for(int i=1;i<=n;i++)
			if(!tg[i])rt=i;
		int U=Get_rt(1,1);
		int V=Get_rt(rt,0);
		for(int k=1;k<=__lg(n);k++)
			for(int i=1;i<=n;i++)
				ST[k][i]=ST[k-1][ST[k-1][i]];
		int L=0,R=n;
		while(L+1<R){
			int mid=(L+R)>>1;
			if(check(mid,U,V))R=mid;
			else L=mid;
		}
		return R;
	}
	void work(){
		int Ans=INF;
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++)
				v[j].clear(),tg[j]=0;
			for(int j=1;j<n;j++)
				if(i!=j)add(e[j].u,e[j].v);
			Ans=min(Ans,Get_Ans());
		}
		cout<<Ans<<'\n';
	}
}

namespace Solve2{
	vector<int> v[N];
	int tg[N],dep[N];
	int st[N],tp;
	int ST[20][N];
	void add(int x,int y){
		v[x].push_back(y);
		v[y].push_back(x);
	}
	void Dfs(int x){
		tg[x]=1;
		for(int u:v[x])
			if(!tg[u])Dfs(u);
	}
	void dfs1(int x,int f){
		for(int u:v[x])if(u!=f)
			dep[u]=dep[x]+1,dfs1(u,x);
	}
	bool dfs2(int x,int f,int y){
		bool flag=(x==y);
		for(int u:v[x])
			if(u!=f)flag|=dfs2(u,x,y);
		if(flag)st[++tp]=x;
		return flag;
	}
	void dfs3(int x,int f){
		ST[0][x]=f;
		for(int u:v[x])
			if(u!=f)dfs3(u,x);
	}
	int Get_rt(int x,bool b){
		dfs1(x,0);
		for(int i=1;i<=n;i++)
			if(tg[i]==b&&dep[i]>=dep[x])x=i;
		dfs1(x,0); int y=0;
		for(int i=1;i<=n;i++)
			if(tg[i]==b&&dep[i]>=dep[y])y=i;
		tp=0,dfs2(x,0,y);
		int rt=st[tp/2+1];
		dfs3(rt,0);
		return rt;
	}
	int Get_fa(int x,int k){
		for(int i=__lg(n);i>=0;i--)
			if((k>>i)&1)x=ST[i][x],k-=(1<<i);
		return x;
	}
	bool check(int x,int U,int V){
		for(int i=1;i<=n;i++)tg[i]=0;
		tg[U]=tg[V]=1;
		for(int i=1;i<=n;i++){
			int f=Get_fa(i,x);
			while(!tg[f])tg[f]=1,f=ST[0][f];
		}
		int C=0;
		for(int i=1;i<=n;i++)C+=tg[i];
		return (C<=k);
	}
	int Get_Ans(){
		Dfs(1); int rt=0;
		for(int i=1;i<=n;i++)
			if(!tg[i])rt=i;
		int U=Get_rt(1,1);
		int V=Get_rt(rt,0);
		for(int k=1;k<=__lg(n);k++)
			for(int i=1;i<=n;i++)
				ST[k][i]=ST[k-1][ST[k-1][i]];
		int L=0,R=n;
		while(L+1<R){
			int mid=(L+R)>>1;
			if(check(mid,U,V))R=mid;
			else L=mid;
		}
		return R;
	}
	void work(){
		int Ans=INF;
		for(int i=n/4-1;i<=n/4+1;i++){
			for(int j=1;j<=n;j++)
				v[j].clear(),tg[j]=0;
			for(int j=1;j<n;j++)
				if(i!=j)add(e[j].u,e[j].v);
			Ans=min(Ans,Get_Ans());
		}
		cout<<Ans<<'\n';
	}
}


void Solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++)
		cin>>e[i].u>>e[i].v;
	if(C<=10)Solve1::work();
	else if(12<C&&C<15)Solve2::work();
	else Solve1::work();
}
bool End;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T; cin>>C>>T;
	while(T--)Solve();
	cerr<<(&Beg-&End)/1024.0/1024.0<<" MB\n";
	return 0;
}
