#include <bits/stdc++.h>
using namespace std;
long long m,n,a[500005],d[500005];
bool cmp(long long a,long long b)
{
    return a<b;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);


    long long sum=0,now=a[1],ans=0,l=1,r=1,cnt=1;

    while(l<=n&&r<=n)
    {
        while((sum<=m&&r<=n))
        {
            r++;
            ans=max(ans,cnt);
            if(a[r]!=now)
            {
                sum+=(a[r]-now)*cnt;
                now=a[r];
            }
            cnt++;
        }
        while(sum>m&&l<=n)
        {
            sum-=(now-a[l]);
            l++;
            cnt--;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
