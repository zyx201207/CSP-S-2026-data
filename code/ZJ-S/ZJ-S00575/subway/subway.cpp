#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define fir first
#define sec second
#define pii pair<int,int>
#define all(x) (x.begin(),x.end())
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DEP(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define pb push_back
void Ios(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int maxn=5e5+10;
int w[maxn];
vector<pii> g[maxn];
vector<pii> nd[maxn];
int f[510][510];
signed main()
{
	Ios();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	REP(i,1,m) cin>>w[i];
	REP(i,1,n)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int a,t;
			cin>>a>>t;
			nd[a].pb({i,t});
		}
	}
	REP(i,1,n)
	REP(j,1,n)
	if(i==j) f[i][j]=0;
	else f[i][j]=1e18;
	REP(i,1,m)
	{
		for(auto it1:nd[i])
		for(auto it2:nd[i])
		if(it1!=it2)
		{
			f[it1.fir][it2.fir]=min(f[it1.fir][it2.fir],it1.sec+it2.sec);
		}
	}
	REP(k,1,n)
	REP(i,1,n)
	REP(j,1,n)
	f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int mn=1e18;
		for(auto it1:nd[x])
		for(auto it2:nd[y])
		mn=min(mn,f[it1.fir][it2.fir]+w[x]+w[y]+it1.sec+it2.sec);
		cout<<mn<<"\n";
	}
	return 0;
}
//30min pretest passed(7)