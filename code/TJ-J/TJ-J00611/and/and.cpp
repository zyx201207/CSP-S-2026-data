#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn=0,sum,cnt=1;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (int i=1;i<=n-m+1;i++)
    {
        int sum=a[i];
        for (int j=1;j<=m-1;j++)
        {
            sum=(sum&(a[i]+cnt));
            cnt++;
        }
        maxn=max(maxn,sum);
    }
    cout << maxn;
    return 0;
}
