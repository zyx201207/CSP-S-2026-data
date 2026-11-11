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
bool vis[maxn][510];
vector<int> bel[maxn];
signed main()
{
	Ios();
	freopen("subway.in","w",stdout);
	int c=0,n=500,m=5e5/20,d=20,q=1e5;
	cout<<c<<" "<<n<<" "<<m<<" "<<d<<" "<<q<<"\n";
	REP(i,1,m) cout<<rand()<<" ";cout<<"\n";
	REP(i,1,m)
	{
		REP(j,1,20)
		{
			int u=rand()%n+1;
			while(vis[i][u]) u=rand()%n+1;
			vis[i][u]=1;
			bel[u].pb(i);
		}
	}
	int sum=0;
	REP(i,1,n)
	{
		cout<<bel[i].size()<<" ";sum+=bel[i].size();
		for(auto it:bel[i]) cout<<it<<" "<<rand()<<" ";
		cout<<"\n";
	}
	cerr<<sum<<"\n";
	REP(i,1,q)
	{
		int x=rand()%m+1,y=rand()%m+1;
		if(x==y) y=1;
		cout<<x<<" "<<y<<"\n";
	}
	return 0;
}