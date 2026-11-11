#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5+10;
int n,m,a[maxn],ans=1,pre,num,c;
bool fa,fb;
void solve1()
{
    for(int j = 1;j < n;j++)
    {
        pre = 0;
        num = 1;
        for(int i = j+1;i <= n;i++)
        {
            int x = a[i]-a[i-1];
            int y = i-j;
            int idx=x*y;
            if(idx+pre<=m)
            {
                num++;
                pre += idx;
            }
            else break;
        }
        ans = max(ans,num);
    }
}
void solve2()
{
    num = 1;
    for(int i = 2;i <= n;i++)
    {
        int x = a[i]-a[i-1];
        int y = i-1;
        int idx=x*y;
        if(idx+pre<=m)
        {
            num++;
            pre += idx;
        }
        else break;
    }
    ans = num;
}
void solve3()
{
    ans = n;
}
signed main()
{
    //rp++ orz
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] != i) fa = 1;
        if(i == 2) c = a[i]-a[i-1];
        else if(i > 2 && a[i]-a[i-1] != c) fb = 1;
    }
    sort(a+1,a+n+1);
    if(n <= 5000) solve1();
    else if(!fa || !fb) solve2();
    else solve3();
    cout << ans;
    return 0;
}
