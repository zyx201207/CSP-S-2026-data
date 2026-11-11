#include <bits/stdc++.h>
#define ll long long
const int mxn=333333;
using namespace std;
ll a[mxn];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll mxb=-1;
	for(int i=1;i<=n;i++)
	{
		for(ll b=33;b>=0;b--)
		{
			if( ( (a[i]>>b) &1 ) ==1 )
			{
				mxb=max(mxb,b);
				break;
			}
			
		}
	}
	queue<ll> q,_q;
	for(int i=1;i<=n;i++)
	{
		_q.push(a[i]);
	}
	ll ans=0;
	for(int b=mxb;b>=0;b--)
	{
		int N=_q.size();
		for(int i=1;i<=N;i++)
		{
			ll cur=_q.front();
			_q.pop();
			_q.push(cur);
			if( ( ( cur>>b ) &1 ) ==1 )
			{
				q.push(cur);
			}
		}
		if(q.size()>=m)
		{
			ans+=(1ll<<b);
			while(!_q.empty()) _q.pop();
			while(!q.empty())
			{
				ll cur=q.front();
				q.pop();
				_q.push(cur); 
			}
		}
		else
		{
			while(!q.empty()) q.pop();
		}
	}
	cout<<ans;
	return 0;
}
