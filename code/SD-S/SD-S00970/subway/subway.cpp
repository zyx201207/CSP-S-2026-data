#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int C,n,m,d,q,c[510],a[510][323733],s[323733];
ll w[323733],ans[510][510],t[510][323733];
vector <int> v[323733];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		cin>>c[i];
		for(ll j=1;j<=c[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			v[a[i][j]].push_back(i);
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(i==j) continue;
			ans[i][j]=ans[j][i]=1e18;
		}
	}
	for(ll i=1;i<n;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{
			memset(s,0,sizeof(s));
			ll minn=2e9;
			for(ll k=1;k<=c[i];k++) s[a[i][k]]=k;
			for(ll k=1;k<=c[j];k++)
				if(s[a[j][k]]>0)
					minn=min(minn,t[i][s[a[j][k]]]+t[j][k]);
			if(minn==2e9) continue;
			ans[i][j]=ans[j][i]=minn;
		}
	}
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				ans[i][j]=ans[j][i]=min(ans[i][j],ans[i][k]+ans[k][j]);
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		ll minn=1e18;
		for(ll i=0;i<v[x].size();i++)
		{
			for(ll j=0;j<v[y].size();j++)
			{
				minn=min(minn,ans[v[x][i]][v[y][j]]+w[x]+w[y]+t[v[x][i]][lower_bound(a[v[x][i]]+1,a[v[x][i]]+c[v[x][i]]+1,x)-a[v[x][i]]]+t[v[y][j]][lower_bound(a[v[y][j]]+1,a[v[y][j]]+c[v[y][j]]+1,y)-a[v[y][j]]]);
			}
		}
		cout<<minn<<endl;
	}
	return 0;
}
