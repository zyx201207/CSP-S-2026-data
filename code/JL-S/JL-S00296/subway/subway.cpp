#include<bits/stdc++.h>
using namespace std ;

struct str{
    int num ;
    int ty ;
}v[1000][1000];

int w[1000000] ;
int a[1000][1000] ;
int t[1000][1000] ;
int flag[1000000] ;
int c, n, m, d, q, k, minn = 1e6, sum = 0 ;

void dfs(int x, int y, int typ)
{
    if(x == y)
    {
        minn = min(minn, sum) ;
    }
    for(int i=0; i<v[x][0].num; i++)
    {
        if(flag[i] == 0)
        {
            int l = sum ;
            if(v[x][i].ty != typ)
            {
                sum += w[i] + t[typ][i] ;
                typ = v[x][i].ty ;
            }
            flag[i] = 1 ;
            dfs(i, y, typ) ;
            sum = l ;
            flag[i] = 0 ;
        }
    }
    return ;
}

int main()
{
    freopen("subway.in", "r", stdin) ;
    freopen("subway.out", "w", stdout) ;
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q) ;
    for(int i=0; i<m; i++)
    {
        scanf("%d", &w[i]) ;
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d", &k) ;
        for(int j=0; j<k; j++)
        {
            scanf("%d%d", &a[i][j], &t[i][j]) ;
            v[a[i][j-1]][a[i][j]].ty = i ;
            v[a[i][j]][a[i][j-1]].ty = i ;
            v[a[i][j-1]][0].num++ ;
            v[a[i][j]][0].num++ ;
        }
    }
    for(int i=1; i<=q; i++)
    {
        int x, y ;
        scanf("%d%d", &x, &y) ;
        int typ = v[x][1].ty ;
        sum += w[x] ;
        flag[x] = 0 ;
        dfs(x, y, typ) ;
        cout << minn << endl ;
    }
    return 0 ;
}
