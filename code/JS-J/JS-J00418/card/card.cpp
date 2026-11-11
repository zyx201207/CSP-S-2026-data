#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],t[300005];
deque <int> v;
deque <int> s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            while (!v.empty())
            {
                if (v.front() == a[j])
                    break;
                else s.push_back(v.front());
                v.pop_front();
            }
            while (!v.empty())
                v.pop_front();
            while (!s.empty())
            {
                v.push_back(s.front());
                s.pop_front();
            }
            v.push_back(a[j]);
        }
        while (!v.empty())
        {
            t[v.front()]++;
            v.pop_front();
        }
    }
    for (int i = 1; i <= m; i++) cout << t[i] << " ";
    return 0;
}
