#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main()
{
    freopen("card.in", "r",stdin);
    freopen("card.out", "w",stdout);
    int n, m;
    string a = "";
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        a += a[i];
    }
    if(m == 1)
    {
        cout << n;
    }
    if(n == m)
    {
        for(int i = 0;i < m;i++)
        {
            cout << n << " ";
        }
    }
    return 0;
}
