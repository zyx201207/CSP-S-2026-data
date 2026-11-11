#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int ans[300005];
bool x[300005];
stack <int> q;
void solve(int i)
{
    if(x[a[i]])
    {
        while(!q.empty())
        {
            if(q.top() == a[i]) break;
            x[q.top()] = 0;
            q.pop();

        }
    }
    else
    {
        q.push(a[i]);
        x[a[i]] = 1;
    }
}
void add()
{
    while(!q.empty())
    {
        ans[q.top()]++;
        x[q.top()] = 0;
        q.pop();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    if(m == 1)
    {
        cout << n << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if(m == 2)
    {
        for(int i = 1;i < n;i++)
        {
            ans[a[i]]++;
        }
        if(a[n] == 1) cout << n << ' ' << n - ans[1];
        else cout << n - ans[2] << ' ' << n;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = i;j <= n;j++)
        {
            solve(j);
        }
        add();
    }
    for(int i = 1;i <= m;i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}
