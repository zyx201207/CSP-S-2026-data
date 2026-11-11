#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
    cin>>n>>m;
    int a[n],c[n],d[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int b=a[n/2+1];
    int e=a[n/2];
    for(int i=0;i<n;i++)
    {
        c[i]=a[i]-b;
    }
    sort(c,c+n);
    for(int i=0;i<n;i++)
    {
        if(c[i]<0 and cnt1+(0-c[i])<=m)
        {
            cnt1=cnt1+(0-c[i]);
            cnt2+=1;
        }
        else if(c[i]==0)
        {
            cnt2=cnt2+1;
        }
    }
    for(int i=0;i<n;i++)
    {
        d[i]=a[i]-e;
    }
    sort(d,d+n);
    for(int i=0;i<n;i++)
    {
        if(d[i]<0 and cnt3+(0-d[i])<=m)
        {
            cnt3=cnt3+(0-d[i]);
            cnt4+=1;
        }
        else if(d[i]==0)
        {
            cnt4=cnt4+1;
        }
    }
    cout<<max(cnt2,cnt4);
}
