
#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, ans = 0;

struct node
{
    int outtime;
    int line[25];
    int linetime[25];
    int linecnt = 1;
    int time;
    bool hg = 1;
}sub[125255];
int line[505][25];

int x[500005], y[500005];

void dfs(int bi, int en)
{
    if(bi == en)
    {
        exit(0);
    }
    for(int i = 1;i <= sub[bi].linecnt;i++)
    {
        if(sub[bi].hg)
        {
            for(int j = 1;j <= 25;j++)
            {
                for(int k = 1;k <=25;k++)
                {
                    sub[line[sub[bi].line[j]][k]].time = sub[bi].time;
                    dfs(line[sub[bi].line[j]][k], en);
                }
            }
        }
        sub[bi].hg = 0;
    }
    return ;
}
int ci[30];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin >> c >> n >> m >> d >> q;

    for(int i = 1;i <= c;i++)
        cin >> ci[i];

    for(int i = 1;i <= m;i++)
    {
        cin >> sub[i].outtime;
    }
    for(int i = 1;i <= n;i++)
    {
        int tt, ta, tk;
        cin >> tk;
        for(int j = 1;j <= tk;j++)
        {
            cin >> ta;
            sub[j].line[sub[j].linecnt] = i;
            sub[j].linecnt++;
            line[i][j] = ta;
            cin >> tt;
            sub[j].linetime[i] = tt;
        }
    }
    for(int i = 1;i <= q;i++)
    {
        cin >> x[i] >> y[i];
    }
    for(int i = 1;i <= q;i++)
    {
        dfs(x[i], y[i]);
        cout  << sub[y[i]].time << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

