#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m,a[N],ans=-LONG_LONG_MAX;
set<ll>s;
ll andd(ll x,ll y)
{
	deque<ll>xx,yy;
	vector<ll>z;
	while(x>0) 
	{
		xx.push_back(x%2);
		x/=2;
	}
	while(y>0) 
	{
		yy.push_back(y%2);
		y/=2;
	}
	reverse(xx.begin(),xx.end());
	reverse(yy.begin(),yy.end());
	ll xl=xx.size(),yl=yy.size();
	if(xx.size()>yy.size())
	{
		
		for(int i=1;i<=xl-yl;i++) yy.push_front(0);
	}
	else if(xx.size()<yy.size())
	{
		for(int i=1;i<=yl-xl;i++) xx.push_front(0);
	}
	for(int i=0;i<max(xl,yl);i++)
	{
		z.push_back(xx.front() and yy.front());
		xx.pop_front(),yy.pop_front();
	}
	ll s=0;
	for(int i=0;i<z.size();i++)
	{
		s+=z[i]*pow(2,z.size()-i-1);
	}
	return s;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,andd(a[i],a[j]));
			}
			
		}
		cout<<ans;
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			ll d=-1;
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				if(d==-1) d=a[j];
				else d=andd(d,a[j]);
			}
			ans=max(ans,d);
		}
		cout<<ans;
	}
	else if(m==1)
	{
		
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++) ans=andd(ans,a[i]);
		cout<<ans;
	}
	
	return 0;
}
/*
8 2
0 1 2 3

*/
