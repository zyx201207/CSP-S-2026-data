#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 5e3 + 10;

int cnt[MAXN][MAXN];
int maxmin[MAXN][MAXN];
int nums[MAXN];

int n = 0,m = 0;

priority_queue < pair<int,int> > qlist;

void dfs(int start,int en,int dep,int idx)
{
    if(idx == en)
    {
        if(maxmin[start][en] > dep)
        {
            maxmin[start][en] = dep;
            cnt[start][en] = 0;
        }
        cnt[start][en]++;
        return;
    }
    for(int i = idx + 1;i <= en;i++)
    {
        if(nums[i] - nums[idx] > m)
        {
            break;
        }
        dfs(start,en,dep +1,i);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c = 0,t = 0;
    LL ans = 0;
    cin >> c >> t;
    for(int tt = 1;tt <= t;tt++)
    {
        cin >> n >> m;
        for(int i = 1;i <= n;i++)
        {
            cin >> nums[i];
        }
        ans = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                memset(maxmin,0x3f,sizeof(maxmin));
                dfs(i,j,0,i);
                if(cnt[i][j] == 2)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
