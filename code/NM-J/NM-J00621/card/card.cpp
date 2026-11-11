#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, ans[50005] = {}, cnt = 0;
    stack<int> s;
    long long a[500005] = {}, b[50005] = {};
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(b[a[j]] == 0)
            {
                s.push(a[j]);
                b[a[j]] = 1;
            }
            else
            {
                while(s.top() != a[j])
                {
                    b[s.top()] = 0;
                    s.pop();
                }
                s.pop();
                s.push(a[j]);
                b[a[j]] = 1;
            }
        }
        while(!s.empty())
        {
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }



    return 0;
}
