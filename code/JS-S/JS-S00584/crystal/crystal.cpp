#include<bits/stdc++.h>
using namespace std;
long long a[500010],m,cnt;
int n;
int ans=1;
long long pre_fix[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        pre_fix[i]=pre_fix[i-1]+a[i];
    }
    int l=1,r=2;
    while(r<=n)
    {
        if(l==r) r++;
        cnt=(a[r]*(r-l))-(pre_fix[r-1]-pre_fix[l-1]);
        if(cnt<=m)
        {
            ans=max(ans,r-l+1);
            r++;
        }
        else l++;
    }
    cout<<ans;
    return 0;
}
