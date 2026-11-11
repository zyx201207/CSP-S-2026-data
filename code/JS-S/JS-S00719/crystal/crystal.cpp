#include <bits/stdc++.h>//specialAB + test1~9
using namespace std;

long long a[500005],m,n;

void sb()
{
    long long mx=m,ok=1,cha=a[n]-a[n-1];
    while (mx-ok*cha>=0)
    {
        mx-=ok*cha;
        ok++;
    }
    cout << ok;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    bool spb=1;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) spb=0;
    }
    if (spb==1)
    {
        sb();
        return 0;
    }
    if (n==1)
    {
        cout << 1;
        return 0;
    }
    long long mx=m,ok=1,cost;
    sort(a+1,a+n+1);
    cost=a[2]-a[1];
    while (mx-cost>=0)
    {
        mx-=cost;
        ok++;
        cost=ok*(a[ok+1]-a[ok]);
    }
    cout << ok;
    return 0;
}
