#include<bits/stdc++.h>
using namespace std;

int a[20000005], b[2000005], c[200000005];
vector<int> v;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[i] = a[i];
    }

    sort(c + 1, c + n + 1);
    int s = 1;
    for(int i = 2;i <= n; i++)
    {
        if(c[i] != c[i - 1]) s++;
    }

    for(int i = 1; i <= n; i++)
    {
        v = vector<int>();
        int t = 0;
        v.push_back(-1);
        for(int j = i; j <= n; j++)
        {
            auto it = find(v.begin() + 1, v.end(), a[j]);
            int h = 0;
            if(it != v.end())
            {
                h = *it;
                while(h <= t)
                {
                    v.pop_back();
                    h++;
                }
                t -= h - 1;
            }

            v.push_back(a[j]);
            t++;
        }
        for(int i = 1; i <= s;i++)
        {
            auto it = find(v.begin() + 1, v.end(), i);
            if(it != v.end()) b[i]++;
        }
    }

    for(int i = 1; i <= s;i++) cout << b[i] << " ";

    return 0;
}
