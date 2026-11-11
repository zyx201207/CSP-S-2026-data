#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N=1e3+300;

ll T;
ll n,d;
ll id[N];
vector<ll>a[N];
ll dis[N][N];
ll cnt[N][N];

void bfs(ll st)
{
	queue<ll>q;
	q.push(st);
	dis[st][st]=0;
	while(q.size())
	{
		ll x=q.front();
		q.pop();
		for(auto i:a[x])
		{
			if(dis[st][x]+1==dis[st][i])
			{
				cnt[st][i]++;
//				cout<<st<<" "<<i<<" "<<x<<"\n";
				continue;
			}
			if(dis[st][x]+1>dis[st][i])
			{
				continue;
			}
			dis[st][i]=dis[st][x]+1;
			cnt[st][i]=1;
			q.push(i);
		}
	}
	return ;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll TEST;
	cin>>TEST;
	cin>>T;
	while(T--)
	{
		memset(dis,0x3f,sizeof dis);
		memset(cnt,0,sizeof cnt);
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			cin>>id[i];
			a[i].clear();
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				if(id[i]+d<id[j])
				{
					break;
				}
				a[i].push_back(j);
				a[j].push_back(i);
			}
		}
		ll sum=0;
		for(ll i=1;i<=n;i++)
		{
			bfs(i);
			for(ll j=1;j<=n;j++)
			{
				if(cnt[i][j]==2)
				{
		//			cout<<i<<" "<<j<<"\n";
					sum++;
				}
			}
		}
		cout<<sum/2<<"\n";
	}
	return 0;
}
