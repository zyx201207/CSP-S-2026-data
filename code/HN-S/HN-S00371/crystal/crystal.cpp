#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+10;
ll n,m,mn=1e24+5,pos;
ll a[N],b[N];
bool cmp(ll x,ll y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<m;i++)
	{
		b[i]=a[i+1]-a[i];
		if(mn>b[i])
		{
			mn=b[i];
			pos=i;
		}
	}
	ll ans=0;
	ll sum=0;
	for(ll i=pos;i>=1;i--)
	{
		sum+=a[pos+1]-a[i];
		ans++;
		if(sum>m) break;
	}
	cout<<ans-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
