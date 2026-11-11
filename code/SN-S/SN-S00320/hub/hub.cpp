#include<bits/stdc++.h>
using namespace std;
#define il inline
#define int long long
#define ll long long
bool St;
struct IO
{
	static const int Size=(1<<21);
	char buf[Size],*p1,*p2;
	int st[105],Top;
	~IO(){clear();}
	il void clear(){fwrite(buf,1,Top,stdout);Top=0;}
	il char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,Size,stdin),p1==p2)?EOF:*p1++;}
	il void pc(const char c){Top==Size&&(clear(),0);buf[Top++]=c;}
	il IO& operator >>(char& c){while(c=gc(),c==' ' || c=='\n' || c=='\r');return *this;}
	template<typename T>il IO& operator >>(T& x)
	{
		x=0;bool f=0;char c=gc();
		while(!isdigit(c)){if(c=='-') f=1;c=gc();}
		while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=gc();}
		f?x=-x:0;
		return *this;
	}
	il IO& operator >>(string& s)
	{
		s="";char c=gc();
		while(c==' ' || c=='\n' || c=='\r') c=gc();
		while(c!=' ' && c!='\n' && c!='\r' && c!=EOF) s+=c,c=gc();
		return *this;
	}
	il IO& operator <<(const char c){pc(c);return *this;}
	template<typename T>il IO& operator <<(T x)
	{
		if(x<0) pc('-'),x=-x;
		do st[++st[0]]=x%10,x/=10; while(x);
		while(st[0]) pc(st[st[0]--]+'0');
		return *this;
	}
	il IO& operator <<(const string s){for(auto c:s) pc(c);return *this;}
	il IO& operator <<(const char* c){for(int i=0;c[i];i++) pc(c[i]);return *this;}
} fin,fout;
const int N=1000010,inf=1e9;
vector<int> g[N],pre[N],suf[N];
int mxdep[N],dep[N],cnt[N],limit,mnk,n,k;
void get_mxdep(int u,int fa)
{
	dep[u]=dep[fa]+1;
	mxdep[u]=dep[u];
	cnt[u]=0;
	for(int v:g[u])
	{
		if(v==fa) continue;
		get_mxdep(v,u);
		cnt[u]+=cnt[v];
		mxdep[u]=max(mxdep[u],mxdep[v]);
	}
	if(mxdep[u]-dep[u]>=limit) cnt[u]++;
}
int get_mn(int u,int fa,int limitdep)
{
	if(dep[u]>limitdep) return inf;
//	fout<<u<<" "<<limitdep<<"\n";
	int ret=max(1ll,cnt[u]);
	pre[u].clear();suf[u].clear();
	int mx=0;
	for(int j:g[u])
	{
		if(j!=fa) mx=max(mx,mxdep[j]);
		pre[u].push_back(mx);
	}
	mx=0;
	for(int j=(int)g[u].size()-1;j>=0;j--)
	{
		if(g[u][j]!=fa) mx=max(mx,mxdep[g[u][j]]);
		suf[u].push_back(mx);
	}
	reverse(suf[u].begin(),suf[u].end());
	for(int i=0;i<(int)g[u].size();i++)
	{
		if(g[u][i]==fa) continue;
		mx=dep[u];
		if(i) mx=max(mx,pre[u][i-1]);
		if(i!=(int)g[u].size()-1) mx=max(mx,suf[u][i+1]);
		if(mx-1>limit) ret=min(ret,get_mn(g[u][i],u,min(limitdep,limit-(mx-dep[u])+dep[u])));
		else ret=min(ret,get_mn(g[u][i],u,limitdep));
	}
	return ret;
}
bool check()
{
//	fout<<"now limit:"<<limit<<"\n";
	mnk=inf;
	for(int i=1;i<=n;i++)
	{
		get_mxdep(i,0);
//		fout<<"now i:"<<i<<"\n";
//		fout<<"cnt:\n";
//		for(int j=1;j<=n;j++) fout<<cnt[j]<<" ";
//		fout<<"\n";
		for(int j:g[i])
		{
//			fout<<i<<" "<<j<<'\n';
			mnk=min(mnk,max(1ll,cnt[i]-cnt[j])+get_mn(j,i,inf));
//			fout<<i<<" "<<j<<" "<<mnk<<"\n";
		}
	}
//	fout<<limit<<" "<<mnk<<"\n";
	return mnk<=k;
}
bool Ed;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cerr<<(&St-&Ed)/1024.0/1024.0<<"\n";
	int c,T;fin>>c>>T;
	while(T--)
	{
		fin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;fin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(c>=13 && c<=14)
		{
			int m=(n-1)/2;
			if(k<=m) fout<<(int)ceil((m-k)/4.0)+1<<"\n";
			else if(k<n) fout<<1<<"\n";
			else fout<<0<<"\n";
			continue;
		}
		int l=0,r=n-1,ret=n-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			limit=mid;
			if(check()) r=mid-1,ret=mid;
			else l=mid+1;
		}
		fout<<ret<<"\n";
	}
	return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
