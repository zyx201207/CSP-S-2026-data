#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=0x3f3f3f;
ll n,m,ans=1;
ll a[N],f[N];
int sj(int i,int m)
{
	ll ansnow=1;
	for(int j=i-1;j>=0;j--)
	{
		if(a[i]-a[j]<=m)
		{
			m-=a[i]-a[j];
			ansnow++; 
		}
		else
		{
			break;
		}
	}
	return ansnow;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>0;i--)
	{
		f[i]=sj(i,m);
		ans=max(ans,f[i]);
	}	
	cout<<ans<<'\n';
	return 0;
}