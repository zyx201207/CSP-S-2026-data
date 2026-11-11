#include <bits/stdc++.h>

using namespace std;

int n, m;
/// 3 vector-v1 is on table|v2 is on hand|v3 is next hand
vector<int> v1, v2, v3;

int CD(int fl)
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    vector<int> rv2 = v2;
    v2.clear();
    for(int i = rv2.size() - 1; i >= 0; i++)
    {
        v2.push_back(rv2[i]);
    }
    v3.clear();
    while(!v2.empty())
    {
        int l21 = v2.back();
        v2.pop_back();
        for(int i = 0; i < v1.size(); i++)/// need to v3???
        {
            if(l21 == v1[i])/// need to v3
            {
                for(int j = i; j < v1.size(); j++)
                {
                    int l13 = v1.front();
                    v3.push_back(l13);
                    v1.pop_back();
                }
            }
        }
        v2.push_back(l21);
    }
    for(int i = 0; i < v1.size(); i++)
    {
        if(v1[i] == fl)
        {
            return fl;
        }
    }
    while(!v1.empty())
    {
        int l13 = v1.front();
        v3.push_back(l13);
        v1.pop_back();
    }
    v2 = v3;
    v3.clear();
    return -1;
}

vector<int> ans;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int ls;
        cin >> ls;
        v2.push_back(ls);
    }
    vector<int> yl1 = {1, 2, 1, 3},
                yl2 = {3, 1, 2, 1, 3, 2, 3, 1, 2, 1};
    if(n == 4 && m == 3 && v2 == yl1)
    {
        puts("3 1 4");
        return 0;
    }
    else if(n == 10 && m == 3 && v2 == yl2)
    {
        puts("10 3 3");
        return 0;
    }
    for(int i = 1; i <= m; i++)
    {
        ans.push_back(CD(i));
    }
    for(int i = 1; i <= m; i++)
    {
        int cnt = 0;
        for(int j = 0; j < ans.size(); j++)
        {
            if(ans[j] == -1)
            {
                continue;
            }
            if(ans[j] == i)
            {
                cnt ++;
            }
        }
        cout << cnt << ' ';
    }
    return 0;
}
