#include <bits/stdc++.h>
#define AK return
#define csp 0
using namespace std;
long long n,m;
long long ans=0;
long long a[500010];
long long p[500010];
bool fa=1,fb=1;
long long fbs=-1;
long long fm=m;
long long l=1,r=1;
signed main()
{
    //bu kai long long jian zu zong!
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(long long i=1;i<=n;i++)
    {
        if(i==2) fbs=a[i]-a[i-1];
        else if(i>2)
        {
            if(fbs!=a[i]-a[i-1])
            {
                //cerr<<"[error] try to get fbs="<<fbs<<",but find "<<a[i]-a[i-1]<<" in i="<<i<<endl;
                fb=0;
            }
        }
        p[i]=p[i-1]+a[i];
        if(a[i]!=i) fa=0;
    }
    //cerr<<"[info] match privol A="<<fa<<",B="<<fb<<endl;
    if(fa)//15 poins
    {
        for(long long i=1;m>0;i++)
        {
            m-=i;
            if(m>=0) ans++;
        }
        ans++;
        cout<<ans<<endl;
        AK csp;
    }
    if(fb)//15 points
    {
        for(long long i=1;m>0;i++)
        {
            m-=i*fbs;
            if(m>=0) ans++;
        }
        ans++;
        cout<<ans<<endl;
        AK csp;
    }
    {
        //cerr<<"[info] in deque"<<endl;
        while(((l<r)||(l==r==1))&&r<n)
        {
            fm=m;
            r++;
            long long pl=0;
            pl=(a[r])*(r-l+1)-(p[r]-p[l-1]);
            fm-=pl;
            //cerr<<"[info] [l="<<l<<" r="<<r<<"] fm="<<fm<<endl;
            if(fm<0)
            {
                while(fm<0)
                {
                    fm+=pl;
                    l++;
                    pl=max(0ll,(a[r])*(r-l+1)-(p[r]-p[l-1]));
                    fm-=pl;
                }
            }
            ans=max(ans,(r-l+1));
        }
        cout<<ans<<endl;
        AK csp;
    }//about 85 in 85 points
    //fa+fb=30 polong longs
    //let another 50 points!

    AK csp;
}
