#include <bits/stdc++.h>
#define int long long
#define N 500010
//韩心尧 SN-S00467 西安市铁一中学 

using namespace std;


int n,m;
int a[N];
int l = 1,r;
int req;
int ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	

	cin >>n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	a[0] = a[1];
	sort(a + 1,a + n + 1);
	for (r = 1;r <= n;r++)
	{
		req += (a[r] - a[r - 1]) * (r - l);
		while (req > m && l <= r)
		{
			req -= a[r] - a[l];
			l++;
		}
		//printf("l = %d r = %d req = %d\n",l,r,req);
		ans = max(ans,r - l + 1) ;
	}
	cout << ans;
	return 0;
}
