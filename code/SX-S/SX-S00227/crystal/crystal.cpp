#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
const int N=5e5+5;
ll m,a[N],ans=1;
int n;
bool t1,t2;
priority_queue<ll,vector<ll>,greater<ll> > pq;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	rep(i,1,n)
	{
		cin>>a[i];
		if(a[i]!=i)
		{
			t1=1;
		}
	}
	rep(i,1,n)
	{
		if(i!=1&&i!=n&&a[i]-a[i-1]!=a[i+1]-a[i])
		{
			t2=1;
		}
	}
	if(t1==0)
	{
		ll t=1;
		rep(i,1,n)
		{
			t=t*2+1;
			ans++;
			if(m<t)
			{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	if(t2==0)
	{
		ll t=a[2]-a[1],p=t;
		rep(i,1,n)
		{
			t=t*2+p;
			ans++;
			if(m<t)
			{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	rep(i,1,n)
	{
		rep(j,i+1,n)
		{
			pq.push(abs(a[j]-a[i]));
		}
	}
	while(m>0&&!pq.empty())
	{
		ll x=pq.top();
		pq.pop();
		if(m>=x)
		{
			ans++;
			m-=x;
		}
		else
		{
			break;
		}
	}
	cout<<ans-1;
	return 0;
}
