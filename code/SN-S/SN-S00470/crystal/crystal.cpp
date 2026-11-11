// wuxintong xianaizhizhongxue SN-S00470
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100000],n,b[1000000],c[1000000],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
		c[i]=c[i-1]+a[i];
	}
	ll maxn=0;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;j<i;j++)
		{
			if(m>=b[i]-a[i]*j+c[j])
			{
				maxn=max(maxn,i-j);
			}
		}
	}
	cout << maxn;
	return 0;
}


