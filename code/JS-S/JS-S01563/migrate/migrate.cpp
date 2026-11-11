#include<bits/stdc++.h>
using namespace std;
int dp[5010][5010];
int flag[5010][5010];
int a[2000010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        //if(c==11||c==12)
        //
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
            }
            int len=0;
            for(int i=2;i<=n;i++)
            {
                if(abs(a[i]-a[1])<=d)
                {
                    len=i;
                }
            }
            //cout<<len<<" ";
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(i-1+2*len-2<=n)
                {
                    ans++;
                }
            }
            cout<<ans<<"\n";
        //
    }
    return 0;
}
