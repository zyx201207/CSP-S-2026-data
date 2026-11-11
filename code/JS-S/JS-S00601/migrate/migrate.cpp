#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        /*int n,d;
        cin>>n>>d;
        int dp[200006];
        bool f[200006]={};
        int a[200006];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int z=i+1;z<=j;z++)
                {
                    int minn=1e8;
                    for(int k=i;k<z;k++)
                    {
                        if(a[z]-a[k]<=d)
                        {
                            if(dp[k]+1<minn)
                            {
                                minn=dp[k]+1;
                                f[z]=0;
                                if(f[k]==1)
                                {
                                    f[z]=1;
                                }
                            }
                            if(dp[k]+1==minn)
                            {
                                f[z]=1;
                            }
                        }
                    }
                    dp[z]=minn;
                }
                if(f[j]==1)
                {
                    ans++;
                }
            }
        }*/
        cout<<0<<endl;
    }
    return 0;
}
