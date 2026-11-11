#include<bits/stdc++.h>
using namespace std;
long long int c, t, n, d,x[2000005], cnt, ans;
map<long long, map<long long, long long> >dp;
int main()
{
    freopen("migrate2.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>x[i];
            int zz=lower_bound(x+1,x+1+i,x[i]-d)-x;
            if(zz!=i)
                for(int j=zz;j<=i-1;j++){
                    int qs=lower_bound(x+1,x+1+i,x[j]-d)-x;
                    for(int k=qs;k<=j-1;++k)
                        if(x[j]-x[k]<=d){
                        	//cout<<x[k]<<' '<<x[j]<<' '<<x[i]<<' '<<d<<endl;
                        	dp[k][i]=dp[k][i]+1;
						}
                }
        }

        for(int i=1;i<n;++i)
            for(int j=1+1;j<=n;++j)
            	{
				//cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
				if(dp[i][j]==2) ++ans;
				}
        cout<<ans<<endl;
    }
    return 0;
}
