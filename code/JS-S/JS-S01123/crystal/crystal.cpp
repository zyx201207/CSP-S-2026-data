#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005],c1[500005];
long long sum[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
    {
        c[i]=a[i+1]-a[i];
    }
    for(int i=1;i<=n;i++)
    {
        sum[i+1]=sum[i]+c[i]*i;
       // cout<<sum[i]<<" ";
    }
    for(int i=n-1;i>=1;i--)
    {
        c1[i]=c1[i+1]+c[i];
    }
    long long head=0;
    long long lost=0,maxx=-1;
    for(long long i=2;i<=n;i++)
    {
        lost+=c[i-1]*head;
        if(sum[i]-lost>m)
        {
            head++;
            lost+=c1[head]-c1[i];
        }
        else{
            maxx=max(maxx,i-head);
        }
    }
    cout<<maxx;
    return 0;
}
