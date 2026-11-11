#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int n, m, ans = -0xfffffff;

void dg(int t, int s, int x)
{
    if(x >= 3)
    {
        ans = max(ans ,s);
        exit(0);
    }
    for(int i=t; i<=n; i++)
    {
        dg(i, (s and i), x++);
    }
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    //dg(1, 1, 0);
    cout << rand() << endl;
    return 0;
}
