#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int x[100005];

int as(int n,int a)
{
    int ans = 1;
    for(int i = a;i <= n;i++)
    {
        ans += as(n,ans + n);
    }
    return ans;
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        int n,d;
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
        {
            cin >> x[i];
        }
        cout << as(n,n);
    }
    return 0;
}
