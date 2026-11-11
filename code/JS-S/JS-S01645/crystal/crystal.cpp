#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    long long cost=0;
    int ans=1;
    for(int l=1,r=1;r<=n;r++)
    {
        cost+=(a[r]-a[r-1])*(r-l);
        // cout<<cost<<endl;
        while(cost>m)
        {
            cost-=a[r]-a[l];
            l++;
            // cout<<cost<<endl;
        }
        ans=max(ans,r-l+1);
    }
    // puts("");
    printf("%d",ans);
    return 0;
}