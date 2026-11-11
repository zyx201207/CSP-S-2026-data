#include <bits/stdc++.h>
using namespace std;
int n, m, a[500010], ans[300010];
stack <int> s, s2, s3;
queue <int> q;
void(stack b, stack c)
{
    cout << "a";
}
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            int x = a[j];
            for(auto y : s)
            {
                if(y == x)
                while()
                {
                    if(s.top() == x) break;
                    s.pop();
                }
                break;
            }
            s.push_back(x);
        }
        while(!s.empty())
        {
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}
