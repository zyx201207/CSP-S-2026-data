#include<bits/stdc++.h>
using namespace std;

long long a[200005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long ans=0,maxn=0;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        ans&=a[i];
        maxn=max(maxn,ans);
    }
    if (m==n) cout << ans;
    else if (m==1) cout << maxn;
    else if (m==2)
    {
        for (int i=1;i<n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout << maxn;
    }
    else if (m==n-1)
    {
        for (int i=1;i<=n;i++)
        {
            long long s=a[1];
            if (i==1) s=a[2];
            for (int j=1;j<=n;j++)
            {
                if (j!=i) s&=a[j];
            }
            maxn=max(maxn,s);
        }
        cout << maxn;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
