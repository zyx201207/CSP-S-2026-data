#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int a[500005], b[300005], c[300005];
bool ck(vector<int> c, int n)
{
    for (int i = 0; i < c.size(); ++i)
    {
        if (c[i] == n)
        {
            return 1;
        }
    }
    return 0;
}
int fd(vector<int> c, int n)
{
    for (int i = 0; i < c.size(); ++i)
    {
        if (c[i] == n)
        {
            return i;
        }
    }
    return 0;
}
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    bool f = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        c[a[i]]++;
        if (a[i] < a[i - 1])
        {
            f = 0;
        }
    }
    for (int i = 1; i < n; ++i)
    {
        c[i] = c[i - 1] + c[i];
    }
    if (f == 1)
    {
        for (int i = 1; i <= m; ++i)
        {
            cout << c[i] << " ";
        }
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        vector<int> c;
        for (int j = i; j < n; ++j)
        {
            if (!ck(c, a[j]))
            {
                c.reserve(c.size() + 1);
                c.push_back(a[j]);
            }
            else
            {
                for (int k = c.size() - 1; k > fd(c, a[j]); --k)
                {
                   c.pop_back();
                }
                c.push_back(a[j]);
            }
        }
        for (int j = 1; j <= m; ++j)
        {
            if (ck(c, j))
            {
                b[j]++;
            }
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        cout << b[i] << " ";
    }
    return 0;
}

