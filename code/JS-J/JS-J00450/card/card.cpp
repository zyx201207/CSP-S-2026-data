#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], ans[N], t[N];
stack <int> stk;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n, m;
    bool f = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < a[i - 1]) f = 0;
        t[a[i]]++;
    }
    if (f)
    {
        for (int i = 1; i <= m; i++)
        {
            if (i != 1) cout << " ";
            if (t[i] != 0) cout << n;
            else cout << 0;
        }
        cout << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++) t[j] = 0;
        if (i != 1)
        {
            for (int j = 1; j <= i - 1; j++)
            {
                stk.push(a[j]);
                t[a[j]]++;
            }
        }
        for (int j = i; j <= n; j++)
        {
            if (t[a[j]] == 0)
            {
                stk.push(a[j]);
                t[a[j]]++;
            }
            else
            {
                while (!stk.empty())
                {
                    if (stk.top() != a[j])
                    {
                        t[stk.top()]--;
                        stk.pop();
                    }
                    else
                    {
                        t[a[j]]--;
                        if (t[a[j]] == 0)
                        {
                            t[a[j]]++;
                            break;
                        }
                        else
                        {
                            t[stk.top()]--;
                            stk.pop();
                        }
                    }
                }
            }
        }
        while (!stk.empty())
        {
            ans[stk.top()]++;
            stk.pop();
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (i != 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
