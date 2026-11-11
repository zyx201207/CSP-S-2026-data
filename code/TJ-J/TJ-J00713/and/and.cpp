#include <bits/stdc++.h>
using namespace std;
int a[100010];
int n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    int maxn = -1e9;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j == i) continue;
            maxn = max(maxn,a[i]&a[j]);
        }
    }
    cout<<maxn;
    return 0;
}
