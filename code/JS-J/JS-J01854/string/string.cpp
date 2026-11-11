#include <bits/stdc++.h>
using namespace std;
struct q{
    int x;
    char y;
};
q a[100010];
long long cnt[100010];
long long sum=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        cnt[i]=cnt[i-1]+a[i].x;

        ans+=a[i].x;
    }

    int k,k1,k2;
    if(ans%2==1)
    {
        long long s=ans/2+1;
        for(int i=1;i<=n;i++)
        {
        if(cnt[i]>=s)
        {
            k=i;

           k1=cnt[i]-s;

           k2=s-cnt[i-1]-1;

           break;
        }
        }
        int p=k,q=k;
        while(p>0)
        {
            if(k1<=0)
            {
                q++;

                k1+=cnt[q]-cnt[q-1];
                if(q>n)
                    break;
            }

            if(k2<=0)
            {
                p--;
                k2+=cnt[p]-cnt[p-1];
                if(p<0)
                    break;

            }

            if(k1>k2)
            {
                if(a[q].y==a[p].y)
                {k1-=k2;
                k2=0;}
                else
                {k1-=k2;
                sum+=k2;
                k2=0;
                }
            }
            if(k1<k2)
            {

                if(a[q].y==a[p].y)
                {k2-=k1;

                k1=0;}
                else
                {k2-=k1;
                sum+=k1;

                k1=0;
                }
            }
            if(k1==k2)
            {

                if(a[q].y!=a[p].y)
                {sum+=k1;}
                k1=0;
                k2=0;
            }
        }

    }

    else{
            int kp,kq;
        long long s1=ans/2;
        long long s2=ans/2+1;


        for(int i=1;i<=n;i++)
        {
        if(cnt[i]>=s1)
        {

                kq=i;
                k1=s1-cnt[i-1]-1;

            break;

        }}
        for(int i=1;i<=n;i++){
        if(cnt[i]>=s2)
        {


                kp=i;
                k2=cnt[i]-s2;
            break;

        }}
        if(kp!=kq&&(a[kp].y!=a[kp-1].y&&kp>=1))sum++;
        int p=kp,q=kq;
        while(p>0)
        {

            cout<<kp<<kq;
            if(k1>k2)
            {
                if(a[q].y==a[p].y)
                {k1-=k2;
                k2=0;}
                else
                {k1-=k2;
                sum+=k2;
                k2=0;
                }
            }
            if(k1<k2)
            {

                if(a[q].y==a[p].y)
                {k2-=k1;

                k1=0;}
                else
                {k2-=k1;
                sum+=k1;

                k1=0;
                }
            }
            if(k1==k2)
            {

                if(a[q].y!=a[p].y)
                sum+=k1;


                k1=0;
                k2=0;
            }
        }}

    cout<<sum;
    return 0;
}
