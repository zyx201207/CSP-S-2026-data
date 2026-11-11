#include <bits/stdc++.h>
using namespace std;
int n,maxj=0;
long long m,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        long long m1=m;
        int jj;
        for(int j=i;j>=1;j--)
        {
            if(a[i]-a[j]>m1) break;
            m1-=a[i]-a[j];
            jj=j;
        }
        maxj=max(maxj,i-jj+1);
    }
    cout<<maxj;
    return 0;
}

