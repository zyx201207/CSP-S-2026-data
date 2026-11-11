#include<bits/stdc++.h>
using namespace std;
int const N=5000+10;
int NUM,T,n,num,jia1;
long long d,a[N],dp[N],s[N],stp[N],ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    scanf("%d%d",&NUM,&T);
    while(T>0)
    {
        ans=0;
        T--;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        //cout<<T;
        for(int i=1;i<=n;i++)
        {
            num=i;jia1=i+1;
            memset(dp,0,sizeof(dp));dp[i]=1;
            memset(s,0,sizeof(s));s[i]=1;
            memset(stp,0,sizeof(stp));
            for(int j=i+1;j<=n;j++)
            {
                while(a[j]-a[num]>d)num++;
                if(num==j)break;
                stp[j]=stp[num]+1;
                if(num>=jia1)
                    jia1=j;
                //printf("%lld %lld ",num,jia1);
                dp[j]=s[jia1-1]-s[num-1];
                s[j]=s[j-1]+dp[j];
                if(dp[j]==2)
                {
                    //cout<<i<<j<<" ";
                    ans++;
                }
            }
            //for(int i=1;i<=n;i++)printf("%lld ",dp[i]);
            //for(int i=1;i<=n;i++)printf("%lld ",s[i]);
            //printf("\n");
        }
        printf("%lld\n",ans);
    }
    //cout<<"migrate";
    return 0;
}
