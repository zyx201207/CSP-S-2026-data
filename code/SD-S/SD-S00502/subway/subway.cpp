#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
struct node{ll v,w;};
ll c,n,m,d,q,s,tp,w[N],a[N],t[N],f[N],v[N];
vector<node>g[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1,o;i<=n;i++)
	{
		cin>>o;
		for(ll j=1;j<=o;j++)cin>>a[j]>>t[j];
		for(ll j=1;j<=o;j++)
			for(ll k=j+1;k<=o;k++)
			{
				g[a[j]].push_back({a[k],t[j]+t[k]});
				g[a[k]].push_back({a[j],t[j]+t[k]});
			}
	}
	while(q--)
	{
		cin>>s>>tp;
		memset(f,0x3f,sizeof f);
		memset(v,0,sizeof v);f[s]=0;
		for(ll i=1;i<=m;i++)
		{
			ll l=0x3f3f3f3f,o=0;
			for(ll j=1;j<=m;j++)
				if(!v[j]&&l>f[j])o=j,l=f[j];
			v[o]=1;for(ll j=0;j<g[o].size();j++)
				f[g[o][j].v]=min(f[g[o][j].v],f[o]+g[o][j].w);
		}
		cout<<f[tp]+w[tp]+w[s]<<endl;
	}
	return 0;
}
