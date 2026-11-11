#include<iostream>
#include<vector>
using namespace std;
bool q;
long long readint()
{
    q=0;
    int c,d;
    long long a=0;
    c=getchar();
    while(c<'0'||c>'9')
    {
        if(c==EOF)
        {
            q=1;
            return 0;
        }
        d=c;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        a=a*10+c-48;
        c=getchar();
    }
    if(d=='-')
    {
        a*=-1;
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    c=readint();
    t=readint();
    //long long
    for(int i=0;i<t;i++)
    {
        long long n,d,ans=0,yu=109868546547;
        n=readint();
        d=readint();
        vector<long long> a(n+1),b(n+1);
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
        for(int i=0;i<n;i++)
        {
            a[i]=readint();
            if(i!=0)
            {
                b[i-1]=a[i]-a[i-1];
            }
            if(b[i]<=d)
            {
                dp[i][i+1]=1;
            }
        }
        for(int l=1;l<=n;l++)
        {
            for(int j=n-1;j-l>=0;j--)
            {
                int i=j-l,z=1;
                if(b[i]>d)
                {
                    break;
                }
                else
                {
                    while(a[i+z]-a[i]<=d)
                    {
                        if(dp[i+1][j-1]==-1)
                        {
                            dp[i][j]=-1;
                            break;
                        }
                        dp[i][j]+=dp[i+1][j-1];
                        z++;
                    }
                    if(dp[i][j]>2)
                    {
                        dp[i][j]=-1;
                    }
                }
            }
        }
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(dp[i][j]==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }/*
    for(int i=0;i<t;i++)
    {
        cout<<0<<endl;
    }*/
    return 0;
}
