#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,m;
ll p;
long long a[1000005];
ll diff[1000005];
ll ans=0;
ll len=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	diff[1]=0;
	for(int i=2;i<=n;i++)
	{
		diff[i]=diff[i-1]+(1LL*(abs(a[i]-a[i-1])*len));
		if(m>=diff[i])
		{
			len++;
			ans=max(len,ans);	
		} 
		else break;
	}

	cout<<ans;
	return 0;
}
