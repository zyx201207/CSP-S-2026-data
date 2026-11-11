#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,ans = -1e9;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1,cmp);
    ans = a[1];
    if(m == 1)
    {
        cout << m;
        return 0;
    }
    else if(m == 2)
    {
        ans = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                ans = max(ans,a[i] & a[j]);
            }
        }
    }
    else{
        for(int i = 1;i <= m;i++)
        {
            ans = ans & a[i];
        }
        if(ans == 0)
        {
            for(int i = 2;i <= m + 1;i++)
            {
                ans = ans & a[i];
            }
        }
    }
    cout << ans;
}
