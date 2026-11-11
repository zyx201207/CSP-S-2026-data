#include <bits/stdc++.h>
using namespace std;
long long n , m , ans;
long long a[200005];
void dfs(long long step , long long num , long long z)
{
    if(step > m)
    {
        ans = max(ans , num);
        return;
    }
    if(z > n)
    {
        return;
    }
    dfs(step + 1 , num & a[z] , z + 1);
    dfs(step , num , z + 1);
}
int main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++)
    {
        dfs(2 , a[i] , i + 1);
    }
    cout << ans;
    return 0;
}
