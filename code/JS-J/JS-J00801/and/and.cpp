#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m;
long long ans,maxn,a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i= 1;i<= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i= 1;i<= n;i++)
    {
        ans = a[i];
        for(int j = i;j <= i+m-1;j++)
        {
            ans = (ans&a[j]);
        }
        maxn = max(maxn,ans);
    }
    cout << maxn;
    return 0;
}
