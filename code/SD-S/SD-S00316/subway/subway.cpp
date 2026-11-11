#include<bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
using namespace std;

constexpr int N = 505;
constexpr int M = 5e5+5;
constexpr ll INF = 1e18;

int c,n,m,d,q;
ll w[M];
int k;
int a;
ll t;
vector<PII> stop[M]; 
int x,y;
ll val[N][N];

inline void init()
{
	memset(val,0x3f,sizeof(val));
	for(int i=1;i<=500;++i)
	{
		val[i][i]=0;
	}
	return ;
}

inline void input_do()
{
	init();
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;++i)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;++i)
	{
		cin >> k;
		for(int j=1;j<=k;++j)
		{
			cin >> a >> t;
			stop[a].push_back({i,t});
		}
	}
	int from,to;
	ll val_;
	for(int i=1;i<=500000;++i)
	{
		for(PII j:stop[i])
		{
			for(PII k:stop[i])
			{
				from=j.first;
				to=k.first;
				val_=j.second+k.second;
				val[from][to]=val[to][from]=min(val[from][to],val_);
			}
		}
	}
	return ;
}

inline void floyd()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			for(int k=1;k<=n;++k)
			{
				val[i][j]=min(val[i][j],val[i][k]+val[k][j]);
			}
		}
	}
	return ;
}

inline void solve()
{
	input_do();
	floyd();
	int to1,to2;
	ll mn;
	while(q--)
	{
		cin >> x >> y;
		mn=INF;
		for(PII i:stop[x])
		{
			for(PII j:stop[y])
			{
				to1=i.first,to2=j.first;
				mn=min(mn,val[to1][to2]+i.second+j.second);
			}
		}
		mn+=w[x]+w[y];
		cout << mn << "\n";
	}
	return ;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	solve();

	return 0;
}

