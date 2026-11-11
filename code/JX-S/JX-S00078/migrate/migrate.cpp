#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,a[N],dp[N],dis[N];
long long read()
{
    long long sum=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
            sum=(sum<<3)+(sum<<1)+(c^48),c=getchar();
    return sum*f;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while(t--)
    {
        long long ans=0;
        n=read(),d=read();
        for(int i=1;i<=n;i++)
            a[i]=read();
        //cout<<n<<" "<<d<<" "<<a[2]-a[1]<<endl;
        if(c==11||c==12)
        {
            if(a[2]-a[1]>=d) printf("0\n");
            else printf("%lld\n",max(0ll,n-d/(a[2]-a[1])-1-(d/(a[2]-a[1])-2)));
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            memset(dp,0,sizeof(dp));
            memset(dis,0x7f,sizeof(dis));
            dis[i]=0;
            dp[i]=1;
            for(int j=i+1;j<=n;j++)
            {
                int pos=lower_bound(a+1,a+n+1,a[j]-d)-a;
                //cout<<j<<" "<<pos<<endl;
                for(int k=max(pos,i);k<=j-1;k++)
                {
                    if(dis[k]+1<dis[j])
                        dis[j]=dis[k]+1,dp[j]=dp[k];
                    else if(dis[k]+1==dis[j])
                        dp[j]+=dp[k];
                }
                if(dp[j]==2) ans++;//,cout<<i<<" "<<j<<" "<<endl;
                if(dp[j]==0) break;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
