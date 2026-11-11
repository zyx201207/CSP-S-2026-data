#include <bits/stdc++.h>
using namespace std;
struct A
{
    int a;
    bool b;
};
int n, m;
A a[200001];
int s[200001];
int num = 0;
void dfs(int c)
{
    if (c > m)
    {
        int ans = s[1];
        for (int i = 2; i <= m; i++)
        {
            ans &= s[i];
        }
        num = max(ans, num);
        return ;
    }
    for (int i = c; i <= n; i++)
    {
        if (!a[i].b)
        {
            s[c] = a[i].a;
            a[i].b = 1;
            dfs(c+1);
            a[i].b = 0;
        }
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a;
        a[i].b = 0;
    }
    dfs(1);
    cout << num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
