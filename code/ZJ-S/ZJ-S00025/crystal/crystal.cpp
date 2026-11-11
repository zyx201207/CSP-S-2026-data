#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,m;
long long a[500005];
long long s[500005];
bool check(int mid)
{
	for(int i=mid;i<=n;i++)
	{
		if(a[i]*mid<=s[i]-s[i-mid-1]+m)
		{
			return true;
		}
	}
	return false;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=a[i]+s[i-1];
	}
	int l=1,r=n;
	while(l<r)
	{
//		cout << "*********" << endl;
//		cout << l << " " << r << endl;
		int mid=l+r+1>>1;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout << l;
}