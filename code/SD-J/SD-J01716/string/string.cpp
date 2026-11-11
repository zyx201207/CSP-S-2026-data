#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+9;
ll a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	ll l=1,r=n;
	ll ans=0;
	while(l<=r)
	{
		if(a[l]>=a[r])
		{
			if(c[l]!=c[r])
			{
				ans+=a[r];
			}
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
		else
		{
			if(c[l]!=c[r])
			{
				ans+=a[l];
			}
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
	}
	cout<<ans;
	return 0;
}

