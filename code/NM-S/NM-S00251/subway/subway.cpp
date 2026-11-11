#include<bits/stdc++.h>
#define int long long
#define N 500005
#define M 505
#define f first
#define s second
using namespace std;
constexpr int INF=0x3f3f3f3f3f3f3f3f;

int T;
int ans;
int x,y,z;
int n,m,k,q;
int num1,num2;
array<int,N> a;
array<int,M> t;
array<bool,N> val;
array<array<int,M>,M> gl;
array<vector<pair<int,int> >,N> g;
array<vector<pair<int,int> >,M> p;

void dfs(int rt)
{
	for(const auto &u:p.at(rt) )
	for(const auto &e:g.at(u.f) )
	if(rt!=e.f && !val.at(e.f) )
	{
		val.at(e.f)=true;
		if(u.s+e.s<gl.at(rt).at(e.f) )
		{
			gl.at(rt).at(e.f)=gl.at(e.f).at(rt)=u.s+e.s;
			t.at(rt)=t.at(e.f)=u.f;
		}
		
//		cout<<rt<<' '<<e.f<<' '<<u.s+e.s<<endl;
		dfs(e.f);
		val.at(e.f)=false;
	}
}

inline void floyd()
{
	for(int k=1;k<=m;k++)
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	gl.at(i).at(j)=gl.at(j).at(i)=min({
	gl.at(i).at(j),gl.at(j).at(i),
	gl.at(i).at(k)+gl.at(k).at(j) });
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>T>>m>>n>>k>>q;
	for(int i=1;i<=n;i++)
	scanf("%lld",&a.at(i) );
	
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&x);
		for(int j=1;j<=x;j++)
		{
			scanf("%lld%lld",&y,&z);
			p.at(i).push_back(make_pair(y,z) );
			g.at(y).push_back(make_pair(i,z) );
		}
	}
	
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	gl.at(i).at(j)=INF;
	for(const auto &e:g.at(1) )
	dfs(e.f);
	floyd();
	
	while(q--)
	{
		ans=INF;
		num1=num2=0;
		scanf("%lld%lld",&x,&y);
		
		for(const auto &e:g.at(x) )
		for(const auto &u:g.at(y) )
		if(e.f==u.f)
		ans=min(ans,e.s+u.s);
		
		for(const auto &e:g.at(x) )
		for(const auto &u:g.at(y) )
		{
			num1=num2=0;
//			if(t.at(e.f)!=x)
			num1=e.s;
//			if(t.at(u.f)!=x)
			num2=u.s;
			
//			if(t.at(e.f)!=x)
//			for(int i=0;i<g.at(x).size();i++)
//			if(g.at(x).at(i).f==e.f)
//			{
//				num1=g.at(x).at(i).s;
//				break;
//			}
//			
//			if(t.at(u.f)!=y)
//			for(int i=0;i<g.at(y).size();i++)
//			if(g.at(y).at(i).f==u.f)
//			{
//				num2=g.at(y).at(i).s;
//				break;
//			}
			
			ans=min({ans,gl.at(e.f).at(u.f)+num1+num2,gl.at(u.f).at(e.f)+num1+num2});
		}
		
		ans+=a.at(x)+a.at(y);
		printf("%lld\n",ans);
	}
	return 0;
}
