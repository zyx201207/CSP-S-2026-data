#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,ans;
LL m,cnt,k,a[500005],sum[500005];
bool A=1,B=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]!=i)
            A=0;
        if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])
            B=0;
    }
    sort(a+1,a+n+1);
    if(A||B)
    {
        for(int i=1;i<=n;i++)
        {
            cnt+=(a[i]-a[i-1])*(i-1);
            if(cnt<=m)
                ans=i;
            else
                break;
        }
        cout << ans;
    }
    else
    {
        int ans1,ans2;
        for(int i=1;i<=n;i++)
        {
            cnt+=(a[i]-a[i-1])*(i-1);
            sum[i]=cnt;
            if(cnt<=m)
                ans1=i;
            else
                break;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                if(sum[j]-sum[i]<=m)
                    ans2=i-j+1;
                else
                    j=n+1,i=n+1;
        cout << max(ans1,ans2);
    }
    return 0;
}
