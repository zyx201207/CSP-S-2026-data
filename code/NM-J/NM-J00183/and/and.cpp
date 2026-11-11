#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
const int N = 200005;
int a[N], used[N];

void dfs(int u, int f)
{
    if(u > m)
    {
        int k = used[1];
        for(int i = 2;i <= m;i++)
        {
            k = k & used[i];
        }
        ans = max(ans,k);
        return;
    }
    for(int i = f;i <= n;i++)
    {
        used[u] = a[i];
        dfs(u + 1, i + 1);
    }
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
    dfs(1, 1);
    cout << ans;
    return 0;
}
