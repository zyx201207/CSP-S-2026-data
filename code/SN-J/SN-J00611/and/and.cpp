#include <bits/stdc++.h>
#define int long long
#define S "and"
#define FI freopen(S".in","r",stdin);
#define FO freopen(S".out","w",stdout);
using namespace std;

const int N = 2e5+10;
int n,m,a[N],len[N],maxl=-1,maxa=-1,cntb[N],ansm,pdA=1;
bitset<32> b[N];
signed main()
{
	FI;FO;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[i]=a[i];
		len[i]=ceil(log2(a[i]));
		maxl=max(maxl,len[i]);
		maxa=max(maxa,a[i]);
		ansm = i == 1 ? a[i] : ansm&a[i];
		if(log2(a[i]+1)==(int)log2(a[i]+1)) pdA=0; 
	}
	if (n <= 2000)
	{
		if (m == 1) cout << maxa;
		else if (m == n) cout << ansm;
		if (m == 2)
		{
			int ans = -1;
			for (int i = 1;i <= n;i++)
			{
				for (int j = 1;j <= n;j++)
				{
					if (i != j) ans = max(ans,a[i]&a[j]);
				}
			}
			cout << ans;
		} 
	}
	else
	{
		if (pdA) 
		{
			cout << (1<<m)-1;
		}
		else
		{
			
		}
	}
	return 0;
}

