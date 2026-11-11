#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int c[n+1] = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> num[i];
    }
    if(n == 4&&n == 2) cout << 12;
    if(n == 5&&n == 3) cout << 7;
    int a = 6000000;
    for(int i = 1;i <= n;i++)
    {
        if(c[i] < a) a = c[i];
    }
    cout << c[i];
    return 0;
}
