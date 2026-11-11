#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define gc() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
char ibuf[1<<20],*p1,*p2;
inline void read(int &x)
{
	x=0;bool f=0;char ch=getchar();
	for(;!isdigit(ch);ch=gc())if(ch=='-')f=1;
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	x=f?-x:x; 
}
template<typename ...Args>
void read(int &x,Args&...args)
{
	read(x);read(args...);
}
#define pii pair<int,int>
#define fi first
#define se second
//
const int N=512,M=5e5+12,inf=1e18;
int C,n,m,D,Q,W[M],K[N],d[N][N];
vector<int>a[N],t[N]; 
vector<pii>b[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>C>>n>>m>>D>>Q;
	rep(i,1,m)cin>>W[i];
	rep(i,1,n)
	{
		cin>>K[i];
		a[i].reserve(K[i]+2);
		t[i].reserve(K[i]+2);
		a[i].push_back(0);
		t[i].push_back(0); 
		rep(j,1,K[i])
		{
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			b[x].push_back(make_pair(i,y));
		}
	}
	
	
	rep(i,1,n)
	rep(j,1,n)
	d[i][j]=(i==j?0:inf);
	rep(i,1,m)
	{
		for(auto p:b[i])
		for(auto q:b[i])
		d[p.fi][q.fi]=min(d[p.fi][q.fi],p.se+q.se),
		d[q.fi][p.fi]=min(d[q.fi][p.fi],p.se+q.se);
	}
	
	
	rep(k,1,n)
	rep(i,1,n)
	rep(j,1,n)
	d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	
	while(Q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(auto p:b[x])
		for(auto q:b[y])
		ans=min(ans,p.se+q.se+d[p.fi][q.fi]);
		cout<<ans+W[x]+W[y]<<'\n';
	}
	
	return 0;
}