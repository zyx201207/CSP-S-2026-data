#include <bits/stdc++.h>
using namespace std;
int n, m;
bool used[300005];
int a[500005];
int remain[300005];
void clearstk(stack<int>& stk)
{
    while (!stk.empty())
    {
        used[stk.top()] = false;
        stk.pop();
    }
}
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        stack<int> desk;
        for (int j = i; j <= n; j++)
        {
            if (used[a[j]] = true)
                clearstk(desk);
            used[a[j]] = true;
            desk.push(a[j]);
        }
        while (!desk.empty())
        {
            remain[desk.top()]++;
            used[desk.top()] = false;
            desk.pop();
        }
    }
    for (int i = 1; i <= m; i++)
        cout << remain[i] << " ";
    return 0;
}
