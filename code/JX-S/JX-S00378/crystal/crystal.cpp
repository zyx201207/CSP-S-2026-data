#include<bits/stdc++.h>
using namespace std;
const long long MAXN=5e5+88;
const unsigned long long MAXM=1e18+88;
const long long MAXA=1e12+88;
long long a[MAXN],t[MAXN],qz[MAXN];
int f(long long l,long long r)
{
    int s=0;
    for(int i=l;i<=r;i++) s+=t[i]*(i-l+1);
    return s;
}
int main()
{
    freopen("crystal3.in","r",stdin);
    freopen("crystal88.out","w",stdout);
    long long n,m,ans=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    t[1]=0;
    for(int i=2;i<=n;i++) t[i]=a[i]-a[i-1];
    for(long long l=1;l<n;l++)
    {
        for(long long r=l+1;r<=n;r++)
        {
            if(f(l,r)>m) break;
            ans=max(ans,r-l+2);
        }
    }
    cout<<ans;
    return 0;
}
