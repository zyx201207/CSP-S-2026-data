#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll=long long;
const ll inf=1e18;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	vector<ll> w(m+1);
	for(int i=1;i<=m;i++) cin>>w[i];
	vector<gp_hash_table<int,ll>> t(m+1);
	vector<vector<int>> r(m+1);
	for(int i=1;i<=n;i++)
	{
		int len;
		cin>>len;
		for(int j=1,P,T;j<=len;j++) cin>>P>>T,t[i][P]=T,r[P].push_back(i);
	}
	vector<vector<ll>> s(n+1,vector<ll>(n+1,inf));
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) s[i][i]=0;
	for(int i=1;i<=m;i++)
		for(auto R1:r[i])
		{
			ll T1=t[R1][i];
			for(auto R2:r[i])
			{
				if(R1==R2) continue;
				ll T2=t[R2][i];
				s[R1][R2]=min(s[R1][R2],T1+T2);
			}
		}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		ll ans=inf;
		for(auto Ru:r[u]) for(auto Rv:r[v]) ans=min(ans,t[Ru][u]+t[Rv][v]+s[Ru][Rv]);
		cout<<w[u]+w[v]+ans<<'\n';
	}
	return 0;
}

// bx BreakPlus