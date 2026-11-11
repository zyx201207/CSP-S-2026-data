#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6+5;
int c, t, n, d, x[N], ans, dp[N];

namespace Tol{
	void slv1 ()
	{
		int pos, num;
		for (int i=1;i<=n;i++)
			dp[i] = 0;
		for (int i=1;i<=n;i++) {
			pos = i;
			num = 0;
			for (int j=i+1;j<=n;j++) {
				if (x[j]-x[pos]<=d) {
					dp[j] = dp[pos]+1;
					num++;
				}
				else if (x[j]-x[j-1]<=d){
					dp[j] = dp[pos]+2;
					pos = j;
					if (num==2) ans++;
				}
				if (num>2) break;
			}
		}
	}
}

signed main ()
{
	 freopen("migrate.in","r",stdin);
	 freopen("migrate.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while (t--) {
		ans = 0;
		
		cin>>n>>d;
		for (int i=1;i<=n;i++)
			cin>>x[i];
//		if (n<=5000) 
			Tol::slv1();
		cout<<ans<<'\n';
	}
	
	return 0;
}
