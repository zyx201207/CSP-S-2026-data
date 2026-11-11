#include<bit/stdc++.h>
#define int long long
using namespace std;

const int N =2e6+5;
int c, t, n, d, x[N],ans;

namespace Tol{
    void slv1()
    {
    	int dp[N],pos;
    for(int i = 1;i<=n;i++)	{
    	dp[i] = 0;
    	for(int j = 1;j<=n;j++){
    		pos = i;
    		num = 0;
    		for(int j = 1;j<=n;j++)
			{
    			dp(x[j])
			}
		}
    	if(x[j]-x[pos]<=k)
    	}
	}
}
signed main()
{
	freopne("migrate.in","r"stdin);
	freopne("migrate.out","w"stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	whild (t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++)
		cin>>x[i];
		if(n<=5000)Tol::slv1();
	}
	return 0;
}
