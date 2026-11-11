#include <bits/stdc++.h>
using namespace std;
bool f = true,ff = true,fff[2000005];
long long n,m,ans,a[2000005],t[100],cnt[10],e[2000005][40],sum,aa[2000005];
void dfs(int x,int last,int num)
{
    if(num > 1e7 * 9)
    {
        cout << ans;
        exit(0);
    }
    if(x == m)
    {
        sum = aa[1];
        for(int i = 2 ; i <= m ; i++) sum = aa[i];
        if(sum > ans) ans = sum;
        return ;
    }
    else
    {
        for(int i = last + 1 ; i <= n ; i++)
        {
            if(!fff[i])
            {
                aa[x] = a[i];
                fff[i] = true;
                dfs(x + 1,i,num + 1);
                fff[i] = false;
            }
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        if(a[i] != (1 << i) - 1) ff = false;
        if(a[i] > 4) f = false;
        if(a[i] <= 4) cnt[a[i]]++;
    }
    sort(a + 1,a + n + 1);
    if(n <= 20)
    {
        int cnt = 0,s = 0;
        for(int status = 1 ; status < (1 << n) ; status++)
        {
            for(int i = 1 ; i <= 50 ; i++) t[i] = 0;
            cnt = 0;
            for(int i = 1 ; i <= n ; i++)
            {
                if(status & (1 << (i - 1)))
                {
                    cnt++;
                    t[cnt] = a[i];
                }
            }
            if(cnt != m) continue;
            s = t[1];
            for(int i = 2 ; i <= m ; i++) s &= t[i];
            if(s > ans) ans = s;
        }
        cout << ans;
    }
    else if(n <= 2000)
    {
        if(m == 1) cout << a[n];
        if(m == 2)
        {
            for(int i = 1 ; i <= n ; i++)
            {
                for(int j = 1 ; j <= n ; j++)
                {
                    if(i == j) continue;
                    if(ans < (a[i] & a[j])) ans = (a[i] & a[j]);
                }
            }
            cout << ans;
        }
        if(m == n)
        {
            ans = a[1];
            for(int i = 2 ; i <= n ; i++) ans &= a[i];
            cout << ans;
        }
    }
    else if(f)
    {
        if(cnt[3] >= n) cout << 3;
        else if(cnt[2] + cnt[3] >= n) cout << 2;
        else if(cnt[1] + cnt[3] >= n) cout << 1;
        else if(cnt[1] + cnt[4] >= n) cout << 1;
        else cout << 0;
    }
    else if(ff)
    {
        cout << (1 << (m - n + 1));
    }
    else
    {
        dfs(1,0,0);
    }
    return 0;
}
