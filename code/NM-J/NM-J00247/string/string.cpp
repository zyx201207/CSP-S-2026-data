#include <bits/stdc++.h>

using namespace std;

namespace Solve
{

    void main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        freopen("string.in", "r", stdin);
        freopen("string.out", "w", stdout);
        int n = 0;
        cin >> n;
        string s;
        for (int i = 0; i < n; i++)
        {
            int part;
            char cha;
            cin >> part >> cha;
            for (int i = 0; i < part; i++)
            {
                s.push_back(cha);
            }
        }
        int mid = s.size() / 2;
        int p = 0;
        char head, back;
        int ans = 0;
        while (p < mid)
        {
            head = s[p];
            back = s[s.size() - 1 - p];
            if(head!=back){
                ans++;
            }
            p++;
        }
        cout << ans;
    }
}

int main()
{
    Solve::main();
    return 0;
}