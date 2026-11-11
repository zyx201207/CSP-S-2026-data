#include<bits/stdc++.h>
using ll=long long;
using namespace std;

const ll maxn=5e3+10;

ll n,d,a[maxn],dis[maxn][maxn],diss[maxn][maxn],tot[maxn][maxn];

vector<ll> g[maxn]; 

void spfa(ll x)
{
	queue<ll> q;
	q.push(x);
	dis[x][x]=0;
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		for(auto v:g[u])
		{
			if(dis[x][v]>dis[x][u]+1)
			{
//				cout<<"zzx"<<endl;
				dis[x][v]=dis[x][u]+1;
//				cout<<x<<" "<<v<<" "<<dis[x][v]<<endl;
				q.push(v);
			}
		}
	}
	return ;
}

void getans(ll x)
{
	queue<ll> q;
	q.push(x);
	diss[x][x]=0;
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		tot[x][u]++;
		for(auto v:g[u])
		{
			if(diss[x][v]>=diss[x][u]+1)
			{
				diss[x][v]=diss[x][u]+1;
				q.push(v);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,T;
	cin>>c>>T;
	while(T--)
	{
		memset(tot,0,sizeof(tot));
		memset(dis,0x7f,sizeof(dis));
		memset(diss,0x7f,sizeof(diss));
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>a[i];
		for(ll i=1;i<=n;i++)
		{
			g[i].clear();
			for(ll j=i+1;j<=n;j++)
			{
				if(i==j)continue;
				if(abs(a[i]-a[j])<=d)g[i].push_back(j),g[j].push_back(i);
			}
		}
		for(ll i=1;i<=n;i++)spfa(i);
		for(ll i=1;i<=n;i++)getans(i);
		ll anss=0;
//		for(ll i=1;i<=n;i++)
//		{
//			for(ll j=1;j<=n;j++)
//				cout<<dis[i][j]<<" ";
//			cout<<endl;
//		}
		for(ll i=1;i<=n;i++)
			for(ll j=i;j<=n;j++)
				if(tot[i][j]==2||tot[j][i]==2)anss++;
		cout<<anss<<endl;
	}
	return 0;
}
