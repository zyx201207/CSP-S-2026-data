#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define ull unsigned long long
#define ll long long
#define endl '\n'
using namespace std;
ll ans=0;
ll cnt=0,n;
ll dis[30007];
ll tot[30007],a[3000007],d;
vector<ll>v[30007];
void bfs(ll st)
{
	for(ll i=1;i<=n;i++)
	{
		dis[i]=1e9;
		tot[i]=1;
	}
	cnt=0;
	queue<ll>q;
	q.push(st);
	dis[st]=0;
	while(!q.empty())
	{
		ll x=q.front();q.pop();
		for(ll i=0;i<v[x].size();i++)
		{
			ll y=v[x][i];
			if(dis[y]>dis[x]+1)
			{
				q.push(y);
				dis[y]=dis[x]+1;
				tot[y]=tot[x];
			}else 
			{
				if(dis[y]==dis[x]+1) tot[y]+=tot[y];
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if(tot[i]==2) cnt++;
	}
}
int	main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IO;
	ll ct,T;
	cin>>ct>>T;
	while(T--)
	{
		bool flag1=1;
		ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i!=1&&a[i]-a[i-1]!=a[2]-a[1]) flag1=0;
		}
		if(flag1==1)
		{
			if(d<=a[2]-a[1])
			{
				cout<<0<<endl;
				continue; 
			}
			cout<<max(0ll,n-(d/(a[2]-a[1]))*2+1)<<endl;
			continue; 
		}
		for(ll i=1;i<=n;i++)
		{
			v[i].clear();
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>d) break;
	//			cout<<j<<" ";
				v[i].push_back(j); 
			}
//			cout<<endl; 
		}
		for(ll i=1;i<=n;i++)
		{
			bfs(i);
			ans+=cnt;
//			cout<<i<<" "<<cnt<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 1
7 9
1 3 8 14 17 23 24 
*/
