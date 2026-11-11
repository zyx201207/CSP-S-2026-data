#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll x[1000005];
ll y[1000005];
bool flag=false,flag2=true;
int main()
{
	freopen("crystop.in","r",stdin);
	freopen("crystop.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,ans=0;
	double sum=0;
	cin>>n>>m;
	for(ll i=0;i<n;i++)
	{
		cin>>x[i];
		sum+=x[i];
	}
	double a=sum/n;
	int b=ceil(a);
	for(int i=0;i<n;i++)
	{
		if(x[i]==b)
		{
			ans++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(x[i]>0)
		{
			flag=true;
		}
		else
		{
			flag2=false;
		}
	}
	if(flag&&flag2)
	{
		cout<<ans+3<<endl;
	}
	else
	{
		cout<<ans+2<<endl;
	}
	return 0;
}
