#include <bits/stdc++.h>
#define int long long
#define S "crystal"
#define FI freopen(S".in","r",stdin);
#define FO freopen(S".out","w",stdout);
using namespace std;

const int N = 5e5+10;
int n,m,M,a[N],ans,l,r,cha[N],q[N];
bool check(int mid)
{
	M=1e12;
	int xx=0;
	for (int st = 1;st <= n-mid+1;st++)
	{
		xx = mid*(a[st+mid-1])-q[st+mid-1]+q[st-1];
//		if (mid == 3 && st == 2 ) cout << xx << " ";
		M = min(M,xx);
	}
	return M < m ? 1 : 0;
}
signed main()
{
	FI;FO;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		q[i]=q[i-1]+a[i];
	}
	sort(a+1,a+n+1);
		l = 1,r = n;
		while (l < r)
		{
			int mid = (l+r)/2;
			if (check(mid))
			{
//				cout << "l+: " << l << " " << r << " " << mid << " " << M<< endl;
				l=mid+1;
			}
			else
			{
//				cout << "r-: " << l << " " << r << " " << mid <<" " << M<< endl;
				r=mid;
			}	
		}
		cout << r;
	
	
	return 0;
}
