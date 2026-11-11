#include <iostream>
#define int long long
#include <cstdio>
using namespace std;

int arr[200005];

const int inf = 4e18;

int dp[305][305];
int cnt[305][305];

int abss(int a)
{
    if(a < 0)
    {
        return -a;
    }
    else
    {
        return a;
    }
}

int d;

bool zjx(int l,int r)
{
    return abss(arr[r] - arr[l]) <= d;
}

const int mod = 999999937;

void solve1()
{
    int n;
    cin >> n >> d;
    for(int i = 1;i <= n;i++)
    {
        cin >> arr[i];
    }
    for(int i = 1;i <= n;i++)
    {
        dp[i][i] = 0;
        cnt[i][i] = 1;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            dp[i][j] = inf;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(zjx(i,j) && i != j)
            {
                dp[i][j] = dp[j][i] = 1;
                cnt[i][j] = cnt[j][i] = 1;
            }
            else if(i != j)
            {
                cnt[i][j] = 0;
            }
        }
    }
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(dp[i][j] > dp[i][k] + dp[k][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    cnt[i][j] = (cnt[i][k] * cnt[k][j]) % mod;
                }
                else if(dp[i][j] == dp[i][k] + dp[k][j])
                {
                    cnt[i][j] = (cnt[i][j] + cnt[i][k] * cnt[k][j]) % mod;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = i + 1;j <= n;j++)
        {
            if(cnt[i][j] == 2)
            {
                ans++;
            }
        }
    }
    /*
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    cout << ans << '\n';
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    if(c <= 6)
    {
        while(t--)
        {
            solve1();
        }
    }
    else
    {
        cout << "Hello,world";
    }
    return 0;
}
