#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,T;
int n;
long long d;
long long a[N];
// long long len[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--)
    {
        long long ans=0;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%lld",a+i);
        // if(c==11||c==12)
        // {

        // }
        // for(int i=n;i>=1;i--)
        // {
        //     len[i]=1;
        //     int l=i,r=n,mid,ans1;
        //     long long x=a[i]+d;
        //     while(l<=r)
        //     {
        //         mid=(l+r)>>1;
        //         if(a[mid]<=x)
        //         {
        //             ans1=mid;
        //             l=mid+1;
        //         }else
        //             r=mid-1;
        //     }
        //     if(ans1==i+1)
        //         len[i]+=len[i+1];
        // }
        // for(int i=1;i<=n;i++)
        //     cout<<len[i]<<" ";
        // puts("");
        long long si=1;
        for(int i=1;i<n;i++)
        {
            long long x=a[i]+d;
            int l=i,r=n,mid,ans1;
            while (l<=r)
            {
                mid=(l+r)>>1;
                if(a[mid]<=x)
                {
                    ans1=mid;
                    l=mid+1;
                }else 
                    r=mid-1;
            }
            if(ans1==i+1)
                si++;
            else{
                l=i,r=n;
                x=a[ans1-1]+d;
                int ans2;//the last can arrive by x1
                while (l<=r)
                {
                    mid=(l+r)>>1;
                    if(a[mid]<=x)
                    {
                        ans2=mid;
                        l=mid+1;
                    }else  
                        r=mid-1;
                }
                l=i,r=n;
                x=a[ans1-2]+d;
                int ans3;//the last can arrive by x1
                while (l<=r)
                {
                    mid=(l+r)>>1;
                    if(a[mid]<=x)
                    {
                        ans3=mid;
                        l=mid+1;
                    }else  
                        r=mid-1;
                }
                // cout<<ans<<" "<<si<<" "<<i<<" "<<ans2<<" "<<ans3<<endl;
                // if(ans2>ans3)
                // {
                //     if()
                //     ans+=si*(ans2-ans3-1)+len[ans2]*si;
                // }
                
                ans+=si*(ans2-ans3);
                si=1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}