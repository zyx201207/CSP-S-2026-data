#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans = 0,sum = 0;
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++)cin>>a[i];
	sort(a + 1,a + n + 1);
	int l = 1;
	for(int i = 1 ; i <= n ; i++)
	{
		sum += (i - l) * (a[i] - a[i - 1]);
		while(sum > m)sum -= a[i] - a[l],l++;
		ans = max(ans,i - l + 1);
	}
	cout<<ans;
	return 0;
 } 
