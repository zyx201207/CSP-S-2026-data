#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M=500005;
ll c,n,m,d,k,qjj,qjjnb,w[M],dis[1005][1005];
ll x[M],y[M];
struct no{
	ll num,d;
};
vector<no>q[M];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>qjjnb>>n>>m>>d>>qjj;
	for(ll i=1;i<=m;i++) cin>>w[i];
	memset(dis,0x3f3f3f,sizeof(dis));
	for(ll i=1;i<=m;i++) dis[i][i]=0;
	for(ll i=1;i<=n;i++)
	{
		ll o;
		cin>>o;
		for(ll j=1;j<=o;j++) cin>>x[j]>>y[j];
		for(ll j=1;j<=o;j++)
		{
			for(ll k=1;k<=o;k++)
			{
				if(j!=k) dis[x[j]][x[k]]=dis[x[j]][x[k]]=min(dis[x[j]][x[k]],y[j]+y[k]);
			}
		}
	}
	for(ll k=1;k<=m;k++)
		for(ll i=1;i<=m;i++)
			for(ll j=1;j<=m;j++)	
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(qjj--)
	{
		ll x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
}
