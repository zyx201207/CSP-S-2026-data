#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
int d[N];
int w[N];
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
    sort(a + 1,a + n + 1);
    for(int i = 1;i < n;i++)
    {
        d[i] = a[i + 1] - a[i];
        w[i] = d[i] * i;
    }
    __int128 cnt = 0;
    //3845
    int id = -1;
    for(int i = 1;i < n;i++)
    {
        cnt += w[i];
        if(cnt > m)
        {
            id = i;
            break;
        }
    }
    if(cnt <= m)
    {
        id = n;
    }
    cout << id;
    return 0;
}
