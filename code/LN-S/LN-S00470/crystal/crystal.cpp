#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1,a[600000];
long long l,r;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    l=1;
    for(r=1;r<n;r++)
    {
        maxn=max(maxn,r-l+1);
        m-=(a[r]-a[r-1])*(r-l);
        while((m/(r-l+1))<a[r+1]-a[r]&&l<=r)
        {
            m+=a[r]-a[l];
            l++;
        }
    }
    maxn=max(maxn,n-l+1);
    cout<<maxn;
    return 0;
}
