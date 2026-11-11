#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=5e5+5;

int n;
ll m;
ll a[N];
int ans;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ans=1;
    int j=1;
    ll lst=a[1];
    ll S=0;
    for(int i=2;i<=n;i++)
    {
        S+=(a[i]-lst)*(i-j);
        lst=a[i];
        while(S>m && j<i)
        {
            S-=(a[i]-a[j]);
            j++;
        }
        ans=max(ans,i-j+1);
    }
    printf("%d\n",ans);
    return 0;
}
