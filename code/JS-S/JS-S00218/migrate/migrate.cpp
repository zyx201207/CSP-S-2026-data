#include <bits/stdc++.h>
using namespace std;

int n,d,a[2000010],dx[3010][3010],dd[3010][3010];

void dfs1(int now,int x,int y,int a,int sum)
{
    if(now == y + 1)
    {
        dd[x][y] = min(dd[x][y],a);
        return ;
    }
    if(sum < d)
    {
        dfs1(now + 1,x,y,a,sum + a[now + 1] - a[now]);
    }
    dfs1(now + 1,x,y,a + 1,0);
}

void dfs2(int now,int x,int y,int a,int sum)
{
    if(now == y + 1 && a == dd[x][y])
    {
        dx[x][y]++;
        return ;
    }
    if(sum < d)
    {
        dfs2(now + 1,x,y,a,sum + a[now + 1] - a[now]);
    }
    dfs2(now + 1,x,y,a + 1,0);
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout)
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        dx[1] = a[2] - a[1];
        for(int i = 2;i < n;i++)
        {
            dx[i] = a[i + 1] - a[i];
        }
        if(n <= 9)
        {
            cnt = 0;
            for(int i = 1;i <= n;i++)
            {
                for(int j = 1;j <= n;j++)
                {
                    memset(dx,0,sizeof(dx));
                    memset(dd,0,sizeof(dd));
                    flag = 0;
                    dfs1(i,j);
                    dfs2(i,j);
                    if(dx[x][y] == 2)
                    {
                        cnt++;
                    }
                }
            }
            cout << cnt << "\n";
        }
        /*int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                int g = 0,sum = 0,h = 0;
                bool flag = 0;
                for(int k = i + 1;k <= j;k++)
                {
                    h++;
                    sum += abs(a[k] - a[k - 1]);
                    if(sum > d)
                    {
                        if(h == 1)
                        {
                            flag = 1;
                            break;
                        }
                        sum = 0;
                        h = 0;
                        g++;
                    }
                }
                if(flag)
                {
                    continue;
                }
                deque<int> q;
                int l = 0;
                flag = 0;
                for(int k = i + 1;k <= j;k++)
                {
                    q.push_back(a[k] - a[k - 1]);
                    l += (a[k] - a[k - 1]);
                    while(!q.empty() && l - q.front() > d)
                    {
                        l -= q.front();
                        q.pop_front();
                    }
                    if(l == d)
                    {
                        if((dx[(k - q.size() + 1)] - dx[i]) % d == 0 && (dx[j + 1] - dx[k]) % d == 0)
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
                if(!flag)
                {
                    ans++;
                }
            }
        }
        cout << ans << "\n";*/

    }
    return 0;
}
