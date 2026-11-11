#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],sum,b[500005];
int maxn;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        b[i-1]=a[i]-a[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        sum=0;
        for (int j=i;j<=n;j++)
        {
            sum+=(b[j]*j);
            if (sum<=m)
            {
                maxn=max(maxn,j-i+1);
            }else{
                continue;
            }
        }
    }
    cout << maxn+1;
    return 0;
}
