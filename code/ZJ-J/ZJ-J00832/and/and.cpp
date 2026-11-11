#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,ans=0;
ll a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,greater<ll>());
	ans=a[1];
	int p=0;
	if(pow(2,ceil(log2(a[1])))==a[1] and a[1]!=1)
	{
		while((a[p+1]==a[1] or (pow(2,ceil(log2(a[p+1])))==a[p+1] and a[p+1]!=1)) and p+1<=n)
		{
			p++;
		}
	}
	ans=a[p+1];
	ll cnt=1;
	for(int i=2+p;i<=m+p;i++)
	{
		if(ans&a[i]==0)
		{
			while(1)
			{
				if(ans&a[m+(cnt++)]!=0 or m+cnt==n)
				{
					ans=ans&a[m+(cnt++)];
					break;
				}
			}
		}
		else
			ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}