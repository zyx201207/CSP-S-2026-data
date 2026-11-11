#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5e5+10;
ll n,m;
ll a[N];
int dis = 0,num = 0;
ll ans = 0;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l = 1,r = 1;
	while(l<=n&&r<=n)
	{
		dis = r-l+1;
		while(ans<=m&&r<=n)
		{
			r++;
			ans = ans+(a[r]-a[r-1])*dis;
			dis++;
		}
		r--;
		dis--;
		ans = ans-(a[r+1]-a[r])*dis;
		num = max(num,dis);
		l++;
		ans = ans-(a[r]-a[l-1]);
	}
	cout<<num;
	return 0;
}
