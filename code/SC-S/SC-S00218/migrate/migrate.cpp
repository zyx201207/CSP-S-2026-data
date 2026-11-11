#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const ll N=2e6+5;
int c,T,n,l[N];
ll d,x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		int t=1;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			while(x[i]-x[t]>d)t++;
			l[i]=t;
		}
		ll cnt=0;
		for(int i=1;i<=n;i++)
		{
			vector<pll>a(N);
			a[i]={0,1};
			for(int j=i+1;j<=n;j++)
			{
				t=l[j];
				ll u,r=0;
				u=a[t].first;
				while(u==a[t].first&&t<j)
				{
					r+=a[t].second;
					t++;
				}
				u++;
				if(t==l[j])
				{
					break;
				}
				a[j]={u,r};
				if(r==2)cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}