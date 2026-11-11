#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fst ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10, M=2e6+10;

int n, ans;
int a[N];
char c[N];

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	fst
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i] >> c[i];
	}
	int l=1, r=n;
	while(l<=r)
	{
		if(c[l]==c[r])
		{
			if(a[l]>=a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else
			{
				a[r]-=a[l];
				l++;
			}
		}
		else 
		{
			if(a[l]>=a[r])
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else
			{
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
		}
	}
	cout << ans;
	return 0;
}

