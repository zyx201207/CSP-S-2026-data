#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;

template<typename T1,typename T2>
inline void MIN(T1 &a,T2 b) {a=a<b?a:b;}
template<typename T1,typename T2>
inline void MAX(T1 &a,T2 b) {a=a<b?b:a;}

const int N=5e5+10;

int n,m,d,q,w[N];
vector<PII> p[N];

ll dis[510][510];

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q; 
	for (int i=1;i<=m;i++) cin>>w[i];
	
	for (int i=1;i<=n;i++)
	{
		int k,a,t; cin>>k;
		while (k--) cin>>a>>t,p[a].push_back({i,t});
	}
	
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (int i=1;i<=m;i++)
	{
		for (auto x:p[i]) for (auto y:p[i])
			MIN(dis[x.first][y.first],x.second+y.second);
	}
	
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++)
	for (int k=1;k<=n;k++) MIN(dis[j][k],dis[j][i]+dis[i][k]);
	
	while (q--)
	{
		int a,b; cin>>a>>b;
		ll ans=1e18;
		for (auto x:p[a]) for (auto y:p[b])
			MIN(ans,dis[x.first][y.first]+x.second+y.second);
		cout<<ans+w[a]+w[b]<<"\n"; 
	}

	return 0;
}


