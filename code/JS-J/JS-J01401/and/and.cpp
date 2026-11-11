#include<bits/stdc++.h>
using namespace std;

int n , m , a[210000] , an , vis[210000];
int fx = 1, fy = 1 , fz = 1;

bool fun(int x , int y)
{
    long long sum = 1;
    while(sum <= 2147483648)
    {
        if(x == sum - y) return true;
        sum *= 2;
    }
    return false;
}

void dfs(int step , int num)
{
    if(step == m)
    {
        an = max(an , num);
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            vis[i] = 1;
            dfs(step + 1 , num & a[i]);
            vis[i] = 0;
        }
    }
}

int main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    cin >> n >> m;
    if(!fun(n , 0)) fy = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] != i - 1) fy = 0;
        if(!fun(a[i] , 1)) fx = 0;
        if(a[i] >= 4) fz = 0;
    }
    if(fy == 1)
    {
        cout << n - m;
        return 0;
    }
    if(fx == 1 || fz == 1)
    {
        int ans = 0;
        sort(a + 1 , a + n + 1);
        ans = a[n];
        for(int i = n - 1; i >= n - m + 1; i--)
        {
            ans = ans & a[i];
        }
        cout << ans;
        return 0;
    }
    dfs(0 , 2147483647);
    cout << an;
}
