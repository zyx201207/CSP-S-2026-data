#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+7;
ll n,m,a[N],mx=-1,s,e,y,l,ans=-1;
bool mi()
{
	for(int i=1;i<=n;i++)
	{
		ll nx=a[i]+1;
		while(nx!=1)
		{
			if(nx%2==0)nx/=2;
			else
			{
				return 0;
			}
		}
	}
	return 1;
}
bool cmp(ll a,ll b)
{
	return a>b;
}
void dfs(ll x,ll sum,ll i)
{
	if(i>n)return ;
	if(x>=m)
	{
		ans=max(ans,sum);
		return ;
	}
	dfs(x,sum,i+1);
	if(x==0)
	{
		dfs(x+1,a[i],i+1);
	}
	else dfs(x+1,(sum&a[i]),i+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool ok=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>3)ok=0;
		if(m==1)mx=max(mx,a[i]);
	}
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	else if(ok==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==3)s++;
			if(a[i]==2)e++;
			if(a[i]==1)y++;
			else l++;
		}
		if(s>=m)cout<<3;
		else if(s+e>=m)cout<<2;
		else if(s+y>=m)cout<<1;
		else cout<<0;
		return 0;
	}
	else if(mi()==1)
	{
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
		return 0;
	}
	else if(m==n)
	{
		ll nmans=a[1];
		for(int i=2;i<=n;i++)
		{
			nmans=(nmans&a[i]);
		}
		cout<<nmans;
		return 0;
	}
	dfs(0,0,1);
	cout<<ans;
}
