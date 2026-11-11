#include<bits/stdc++.h>
using namespace std;

int main()
{
    auto f_in = ifstream("./and.in", ios::in);
    auto f_out = ofstream("./and.out", ios::out);

    int n, m;
    f_in >> n >> m;

    vector<int> num(n);
    for (size_t i = 0; i < n; i++)
    {
        int a;
        f_in >> a;
        bool is_have = find(num.begin(), num.end(), a) != num.end();
        if (is_have)
        {
            continue;
        }
        f_in >> num[i];
    }

    int ans = INT_MIN;
    for (size_t i = 0; i < n; i++)
    {
        int t = num[i];
        for (size_t j = i + 1; j < m; j++)
        {
            t &= num[j];
        }

        ans = max(ans, t);   
    }

    f_out << ans;
    



    

    return 0;
}