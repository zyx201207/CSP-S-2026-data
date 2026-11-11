#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long LL;
LL a[N];
char c[N];
LL b[N];
LL n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    LL sum=0;
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c[i];
        sum+=a[i];
        b[i]=sum;
        //cout<<b[i]<<'\n';
    }
    //cout<<sum<<endl;
    LL mid=0;
    LL l=0,r=0;
    if(sum%2==1)
    {
        LL t=lower_bound(b+1,b+n+1,sum/2+1)-b;
        //cout<<t<<endl;
        a[t]--;
        if(a[t]==0)l=t-1,r=t+1;
        else
        {
            if(sum/2+1==b[t])l=t,r=t+1;
            else if(sum/2+1==b[t-1]+1)l=t-1,r=t;
            else
            {
                if(sum/2+1-b[t-1]==b[t]-sum/2)l=t-1,r=t+1;
                else
                {
                if(sum/2+1-b[t-1]>b[t]-sum/2)a[t]-=(b[t]-sum/2),r=t+1,l=t;
                else a[t]-=(sum/2+1-b[t-1]),l=t-1,r=t;
                }
            }
        }
        /*
        if(sum/2+1==b[t]&&a[t]!=0)l=t,r=t+1;
        else if(sum/2+1==b[t-1]+1&&a[t]!=0)l=t-1,r=t;
        else
        {
        l=t+1;
        if(a[t]!=0)r=t;
        else r=t+1;
        }*/
        while(l>=1&&r<=n)
        {
            if(c[l]==c[r])
            {
                if(a[l]==a[r])l--,r++;
                else
                {
                    if(a[l]>a[r])r++,a[l]-=a[r];
                    else if(a[l]<a[r])l--,a[r]-=a[l];
                }
            }
            else
            {
                if(a[l]==a[r])ans+=a[l],l--,r++;
                else
                {
                    if(a[l]>a[r])ans+=a[r],r++,a[l]-=a[r];
                    else ans+=a[l],l--,a[r]-=a[l];
                }
            }
            //cout<<l<<" "<<r<<endl;
        }
        cout<<ans<<'\n';
    }
    else
    {
        LL t1=lower_bound(b+1,b+n+1,sum/2)-b;
        //cout<<t<<endl;
        LL t2=lower_bound(b+1,b+n+1,sum/2+1)-b;
        if(t1!=t2)
        {
            l=t1,r=t2;
            while(l>=1&&r<=n)
            {
                 if(c[l]==c[r])
            {
                if(a[l]==a[r])l--,r++;
                else
                {
                    if(a[l]>a[r])r++,a[l]-=a[r];
                    else if(a[l]<a[r])l--,a[r]-=a[l];
                }
            }
            else
            {
                if(a[l]==a[r])ans+=a[l],l--,r++;
                else
                {
                    if(a[l]>a[r])ans+=a[r],r++,a[l]-=a[r];
                    else ans+=a[l],l--,a[r]-=a[l];
                }
            }
            }
            cout<<ans<<'\n';
        }
        else
        {
            if(sum/2-b[t1-1]==b[t1]-sum)l=t1-1,r=t2+1;
            else
            {
                if(sum/2-b[t1-1]>b[t1]-sum/2)a[t1]-=(b[t1]-sum/2),r=t1+1,l=t1;
                else a[t1]-=(sum/2-b[t1-1]),l=t1-1,r=t1;
            }
            while(l>=1&&r<=n)
            {
                if(c[l]==c[r])
            {
                if(a[l]==a[r])l--,r++;
                else
                {
                    if(a[l]>a[r])r++,a[l]-=a[r];
                    else if(a[l]<a[r])l--,a[r]-=a[l];
                }
            }
            else
            {
                if(a[l]==a[r])ans+=a[l],l--,r++;
                else
                {
                    if(a[l]>a[r])ans+=a[r],r++,a[l]-=a[r];
                    else ans+=a[l],l--,a[r]-=a[l];
                }
            }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
