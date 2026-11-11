#include <bits/stdc++.h>
using namespace std;
long long a[500005],s[500005],cha[500005];
long long n,m,zhizhen=1,l=1,r,ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int k=1;k<=n;k++) cin>>a[k];
    sort(a+1,a+n+1);
    for(int k=1;k<=n;k++)
    {
        long long cnt=0;
        long long b=a[k];
        long long c=m;
        long long temp=k;
        while(b-a[temp]<=c&&temp>=1)
        {
            c=c-(b-a[temp]);
            temp--;
            cnt++;

        }
        ans=max(ans,cnt);

    }
    cout<<ans;
    return 0;
}
