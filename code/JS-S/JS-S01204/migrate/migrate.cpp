#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 310;
const int MAXN = 2e6 + 10;

int c,t;
int n;
ll d;
ll a[MAXN];
ll dis[N][N];
ll way[N][N];
ll f[N];
ll ans;


void dfs(int st,int x,int res)
{
    if(x > n)
    {
        return;
    }

    if(dis[x][st] == res)
    {
        way[st][x]++;
    }
    else if(st != 1)
    {
        return;
    }

    for(int i = x + 1;i <= n;i++)
    {
        if(a[i] - a[x] > d)
        {
            break;
        }
        dfs(st,i,res + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin >> c >> t;
    while(t--)
    {
        int flag = 0;
        ans = 0;
        memset(f,0,sizeof(f));
        memset(dis,0x3f3f3f,sizeof(dis));
        memset(way,0,sizeof(way));
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
            if(i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2])
            {
                flag = 1;
            }
        }

        if(flag == 1)
        {
           for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                if(a[j] - a[i] <= d)
                {
                    dis[j][i] = 1;
                }
            }
        }
        for(int k = 1;k <= n;k++)
        {
            for(int i = 1;i <= n;i++)
            {
                for(int j = 1;j <= n;j++)
                {
                    if(dis[i][j] > dis[i][k] + dis[k][j] && i > k && k > j)
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }

        dfs(1,1,0);
        for(int i = 2;i <= n;i++)
        {
            dfs(i,i,dis[i][1]);
        }

        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                if(way[i][j] == 2)
                {
                    ans++;
                }
            }
        }

        }
        else
        {
            f[1] = 0;
            if(d > a[2] - a[1])f[2] = 1;
            int nd = d / (a[2] - a[1]);
            for(int i = 1;i <= n;i++)
            {
                for(int j = i - 1;j >= i - d;j--)
                {
                    f[i] += f[j];
                }

                if(f[i] == 2)
                {
                    ans++;
                }
            }
        }

        cout << ans <<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

