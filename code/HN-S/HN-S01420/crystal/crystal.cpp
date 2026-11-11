#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ll a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    sort(a,a+n);
    for(int i=n-1;i>0;i--)a[i]-=a[i-1];
    a[0]=0;
    for(int i=1;i<n;i++)a[i]=a[i]*i+a[i-1];
    int i=0,j=0;
    int ans=0;
    while(j<n)
    {
        if(a[j]-a[i]<=m)
        {
            ans=max(ans,j-i+1);
            j++;
        }
        else
        {
            i++;
        }
    }
    printf("%d",ans);

    return 0;
}
