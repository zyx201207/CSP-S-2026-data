#include<bits/stdc++.h>
using namespace std;
long long n,m1,m2,a[1000010],c[1000010],p1,p2,flag1=0,flag2=0,mi1,mi2,cnt1=0,cnt2=0,b1,b2,j;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m1;
    m2=m1;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        c[i]=a[i];
        p1+=a[i];
        p2+=c[i];
    }
    p1/=n;
    p2/=n;
    j=n;
    while(j>0)
    {
        for(long long i=0;i<n;i++)
        {
            if(a[i]==p1)
            {
                flag1=1;
            }
            if(a[i]==p2)
            {
                flag2=1;
            }
        }
        if(flag1==1||flag2==1)
        {
            break;
        }
        else
        {
            p1--;
            p2++;
        }
        j--;
    }

    while(m1>0)
    {
        mi1=INT_MAX;
        for(long long i=0;i<n;i++)
        {
            if(p1-a[i]<mi1&&p1-a[i]>0)
            {
                mi1=p1-a[i];
                b1=i;
            }
        }
        if(mi1>m1)
        {
            break;
        }
        a[b1]=p1;
        m1-=mi1;
    }
    while(m2>0)
    {
        mi2=INT_MAX;
        for(long long i=0;i<n;i++)
        {
            if(p2-c[i]<mi2&&p2-c[i]>0)
            {
                mi2=p2-c[i];
                b2=i;
            }
        }
        if(mi2>m2)
        {
            break;
        }
        c[b2]=p2;
        m2-=mi2;
    }
    for(long long i=0;i<n;i++)
    {
        if(a[i]==p1)
        {
            cnt1++;
        }
    }
    for(long long i=0;i<n;i++)
    {
        if(c[i]==p2)
        {
            cnt2++;
        }
    }
    cout<<max(cnt1,cnt2)<<endl;
    return 0;
}
