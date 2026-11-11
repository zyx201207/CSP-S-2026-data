#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int n, m;
int a[MAXN];
vector <int> v;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    for(int q = 1 ; q <= n ; q++)
    {
        for(int i = q ; i <= n ; i++)
        {
            for(int j = 0 ; j <= v.size() - 1; j++)
            {
                if(a[i] == v[j])
                {
                    v.erase(v.begin() + j, v.end());
                    break;
                }
            }
            v.push_back(a[i]);
            cout << "1 \n";
        }
        cout << "1 \n";
    }
    for(auto x : v)
        cout << x;
}

