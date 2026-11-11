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
const int N=510,M=500010,D=20,inf=1e18;
int dis[N][N],w[M],len[N];
vector<int> a[N],t[N];
vector<pair<int,int> > val[M];
bool Ed;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cerr<<(&St-&Ed)/1024.0/1024.0<<"\n";
	int c,n,m,d,q;fin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) fin>>w[i];
	for(int i=1;i<=n;i++)
	{
		fin>>len[i];
		a[i].resize(len[i]+1);
		t[i].resize(len[i]+1);
		for(int j=1;j<=len[i];j++)
		{
			fin>>a[i][j]>>t[i][j];
			val[a[i][j]].push_back({t[i][j],i});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=len[i];j++)
		{
			for(auto k:val[a[i][j]])
			{
				int idx=k.second,www=k.first;
				if(i==idx) continue;
				dis[i][idx]=min(dis[i][idx],www+t[i][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			fout<<dis[i][j]<<" ";
//		}
//		fout<<"\n";
//	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j || j==k || k==i) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y,ans=inf;fin>>x>>y;
		for(auto i:val[x])
		{
			for(auto j:val[y])
			{
//				fout<<i.second<<" "<<j.second<<" "<<i.first<<" "<<j.first<<"\n";
				ans=min(ans,w[x]+w[y]+dis[i.second][j.second]+i.first+j.first);
			}
		}
		fout<<ans<<"\n";
	}
	return 0;
}
