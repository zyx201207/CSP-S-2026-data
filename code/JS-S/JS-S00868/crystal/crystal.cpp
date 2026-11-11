#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n;
long long m,a[N];
long long s[N],w[N],q[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int r=n,l=n;
    w[n]=m;
    long long maxn=0;
    while(l>=1&&l<=r)
    {
        if(w[r]-a[r]+a[l]>=0)
        {
            w[r]-=abs(a[r]-a[l]);
            l--;
            s[r]++;
        }
        else
        {
                r-=1;
               w[r]=w[r+1]+(s[r+1]-1)*abs(a[r+1]-a[r]);
               s[r]=s[r+1]-1;
        }
    }
    for(int i=1;i<=n;i++)
      maxn=max(maxn,s[i]);
    cout<<maxn<<endl;
    return 0;
}
