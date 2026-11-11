#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=5e5+5;

ll n,m;
ll a[N];
ll sum[N];
ll ans;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
		if(sum[i]>m)
		{
			ans=i-1;
			break;
		}
	}
	cout<<ans;
	return 0;
}
