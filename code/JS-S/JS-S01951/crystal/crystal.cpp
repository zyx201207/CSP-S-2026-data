#include<iostream>
#include<algorithm>
#define int long long
#define AK return
#define CSP 0;
using namespace std;
int a[500001];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int s = 0,l = 1,x = 0;
    for(int r = 1;r <= n;r++)
    {
        s += (a[r]-a[r-1])*(r-l);
        while(s > m)
        {
            s -= a[r]-a[l];
            l++;
        }
        x = max(x,r-l+1);
    }
    cout << x;
    AK CSP
}//luogu donani
