//草木逢春，慧如恒沙。神爱世人，妲门永存！
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=2e6+10.27;
ll c,t;
ll x[maxn];
ll dis[maxn];//次数cishu
queue<ll> q;//存下标cunxiabiao
ll cnt[maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	
	cin>>c>>t;
	
	while(t--)
	{
		ll n,d,ans=0;
		cin>>n>>d;
		//ll x[maxn];
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		//ll dis[maxn];//次数cishu
		//queue<ll> q;//存下标cunxiabiao
		//ll cnt[maxn];
		for(int i=1;i<=n;i++)
		{
			//cout<<"i:"<<i<<endl;
			for(int j=i;j<=n;j++)
			{
				dis[j]=maxn;
				cnt[j]=0;
			}
			//cout<<"i:"<<i<<endl;
			while(q.size())
			{
				q.pop();
			}
			//cout<<q.empty()<<"!!!";
			//cout<<"i:"<<i<<endl;
			q.push(i);dis[i]=0;cnt[i]=1;
			while(q.size())
			{
				ll u=q.front();
				ll v=u+1;
				q.pop();
				//cout<<"q.size()"<<q.size()<<endl;
				//int cnt_whi=0;
				while(v<=n&&x[v]-x[u]<=d)
				{
					//cout<<v;
					if(dis[v]>dis[u]+1ll)
					{
						dis[v]=dis[u]+1ll;
						cnt[v]=1ll;
						q.push(v);
					}
					else if(dis[v]==dis[u]+1ll)
					{
						cnt[v]++;
						q.push(v);
					}
					v++;
					//cnt_whi++;
				}
				//cout<<"cnt"<<cnt_whi<<endl;
			}
			//cout<<"i:"<<i<<endl;
			for(int j=i;j<=n;j++)
			{
				if(cnt[j]==2ll)
				{
					ans++;
					//cout<<j<<' ';
					//cout<<i<<' '<<j<<endl;
				}
				//cout<<j<<' ';
				//cout<<i<<' '<<j<<":"<<cnt[j]<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}