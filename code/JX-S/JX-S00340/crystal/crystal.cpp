#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long qzh[n];
    qzh[0]=0;
    for(int i=1;i<n;i++)
    {
        qzh[i]=qzh[i-1]+a[i];
    }
    int l=0,r=1;
    int maxn=0;
    while(r<n)
    {
        int cnt=(r-l)*a[r]-qzh[r]+qzh[l];
        if(cnt<=m)
        {
            maxn++;
            r++;
        }
        else
        {
            l++;
            r=l+maxn+1;
        }
    }
    cout<<maxn;
    return 0;
}
