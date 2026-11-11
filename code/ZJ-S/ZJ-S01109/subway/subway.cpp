#include<bits/stdc++.h>
#define ll long long
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=2010,M=5e5+10;
ll c,n,m,d,w[M],q;
ll f[N][N];
bool kf;
int main()
{
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  AC;
  cin>>c>>n>>m>>d>>q;
  for(ll i=1;i<=m;i++)
  {
  	cin>>w[i];
  }
  if(c<=6 || c>=20)
  {
	  for(ll i=1;i<=n+m;i++)
	  {
	  	for(ll j=1;j<=n+m;j++)
	  	{
	  	  f[i][j]=1e18;
		}
	  }
	  for(ll i=1;i<=n;i++)
	  {
	  	ll ks;
	  	cin>>ks;
	  	for(ll j=1;j<=ks;j++)
	  	{
	  	  ll as,ts;
	  	  cin>>as>>ts;
	  	  f[as][m+i]=ts;
	  	  f[m+i][as]=ts;
		}
	  }
	  for(ll k=1;k<=n+m;k++)
	  {
	  	for(ll i=1;i<=n+m;i++)
	    {
	  	  for(ll j=i+1;j<=n+m;j++)
	  	  {
	  		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	  		f[j][i]=f[i][j];
	  	  }
	    }
	  }
	  for(ll i=1;i<=q;i++)
	  {
	  	ll as,bs;
	  	cin>>as>>bs;
	  	cout<<f[as][bs]+w[as]+w[bs]<<"\n";
	  }
  }
  else if(c<=11)
  {
  	  ll ans[N];
  	  bool f[N];
	  struct kl{ll to,ws;};
	  vector<kl> v[1050];
	  for(ll i=1;i<=n;i++)
	  {
	  	ll ks,aa,at,ba,bt;
	  	cin>>ks>>aa>>at>>ba>>bt;
	  	kl ssk;
	  	ssk.ws=at+bt;
	  	ssk.to=aa;
	  	v[ba].push_back(ssk);
	  	ssk.to=ba;
	  	v[aa].push_back(ssk);
	  }
	  for(ll i=1;i<=q;i++)
	  {
  	    for(ll j=1;j<=m;j++) ans[j]=1e18,f[j]=0;
	  	ll as,bs;
	  	cin>>as>>bs;
	  	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
	  	pair<ll,ll> sp;
	  	sp.first=0,sp.second=as;
	  	ans[as]=0;
	  	f[as]=1;
	  	q.push(sp);
		while(!q.empty())
		{
		  sp=q.top();
		  q.pop();
		  for(ll j=0;j<v[sp.second].size();j++)
		  {
		  	ll nxt=v[sp.second][j].to;
		  	if(f[nxt]==1) continue;
		  	if(ans[sp.second]+v[sp.second][j].ws<ans[nxt])
		  	{
		  	  ans[nxt]=ans[sp.second]+v[sp.second][j].ws;
		  	  f[nxt]=1;
	  		  pair<ll,ll> rt;
	  		  rt.first=v[sp.second][j].ws;
	  		  rt.second=nxt;
		  	  q.push(rt);
			}
		  }
		}
	  	cout<<ans[bs]+w[as]+w[bs]<<"\n";
	  }
  }
  else
  {
	  vector<ll> v[N*10];
  	  bool fk[N*10];
  	  ll tk;
	  for(ll i=1;i<=n;i++)
	  {
	  	ll ks;
	  	cin>>ks;
	  	for(ll j=1;j<=ks;j++)
	  	{
	  	  ll ak;
	  	  cin>>ak>>tk;
	  	  v[i+m].push_back(ak);
	  	  v[ak].push_back(i+m);
		}
	  }
	  for(ll i=1;i<=q;i++)
	  {
	  	for(ll j=1;j<=n+m;j++) fk[j]=0;
	  	bool flag=0;
	  	struct km{ll kw,now;};
	  	queue<km> q;
	  	ll as,bs;
	  	cin>>as>>bs;
	  	km kmm;
	  	kmm.kw=0;
	  	kmm.now=as;
	  	q.push(kmm);
		while(!q.empty())
		{
		  kmm=q.front();
		  q.pop();
		  for(ll j=0;j<v[kmm.now].size();j++)
		  {
		  	ll nxt=v[kmm.now][j];
		  	if(fk[nxt]==0)
		  	{
		  	  if(nxt==bs)
		  	  {
		  	  	cout<<tk*(kmm.kw+1)+w[as]+w[bs]<<"\n";
		  	  	flag=1;
		  	  	continue;
			  }
		  	  km ksv;
		  	  fk[nxt]=1;
		  	  ksv.kw=kmm.kw+1;
		  	  ksv.now=nxt;
		  	  q.push(ksv);
			}
		  }
		  if(flag==1) continue;
		}
	  }
  }
  return 0;
}
