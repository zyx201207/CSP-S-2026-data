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
const int maxn=2e6+10;
int x[maxn];
int nxt[maxn];
int cf[maxn];
int c;
struct stt
{
	int l,r,c;
};
void solve()
{
	int n,d;
	cin>>n>>d;
	REP(i,1,n) cin>>x[i];
	REP(i,1,n)
	{
		int l=min(i+1,n),r=n;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(x[mid]-x[i]<=d) l=mid;
			else r=mid-1;
		}
		nxt[i]=l;
		if(x[l]-x[i]>d||l==i) nxt[i]=-1;
	}
//	REP(i,1,n) cerr<<nxt[i]<<" ";cerr<<"\n";
	int ans=0;
	REP(i,1,n)
	{
		int u=nxt[i],nt=i;
		int lst=n;
		vector<int> upd;
		while(u!=-1)
		{
			if(nxt[u]==-1) break;
			vector<stt> itv;
			REP(o,0,2)
			if(u-o>nt)
			{
				int l=u+1,r=nxt[u-o];
				if(l>r) continue;
				int add=(u-o<=nxt[i]?1:cf[u-o]);
				if(add)
				itv.pb({l,r,add});
				REP(i,nxt[u]-2,nxt[u])
				if(l<=i&&i<=r) cf[i]+=add,upd.pb(i);
				//REP(k,l,r) cf[k]+=cf[u-o];
			}
			int V=0,L=u+1,R=0;
			for(int o=0;o<itv.size();o++)
			{
				if(o+1==itv.size()) L=u+1;
				else L=itv[o+1].r+1;
				stt it=itv[o];
				R=it.r;V+=it.c;
				if(V==2) ans+=R-L+1;
			}
			nt=u;
			u=nxt[u];
		}
		for(auto it:upd) cf[it]=0;
	}
	cout<<ans<<"\n";
}
signed main()
{
	Ios();
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
1h30min:40pts
*/