#include<bits/stdc++.h>
using namespace std;
#define int __int128
#define itn __int128
#define pii pair<int,int>
int fread()
{
    int fh = 1,res = 0;
    char c = getchar();
    while(c == '\n' || c == ' ' || c == '\r' || c == '\t') c = getchar();
    while(c == '-') fh = -fh,c = getchar();
    while(c >= '0' && c <= '9') res = res * 10 + (c - '0'),c = getchar();
    return fh * res;
}
void fwrite(int _a)
{
    char _c[64];
    int cnt = 0;
    if(_a == 0)
    {
        putchar('0');
        return;
    }
    if(_a < 0)
    {
        putchar('-');
        _a = -_a;
    }
    while(_a)
    {
        _c[cnt] = _a % 10 + '0';
        _a /= 10;
        cnt++;
    }
    for(int i = cnt - 1;i >= 0;i--)
    {
        putchar(_c[i]);
    }
}
const int M = 5e5+1,N=501;
int c,d,q,n,m;
vector<pii>line[M];
int dis[N][N];
int czk[M];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c = fread(),n = fread(),m = fread(),d = fread(),q = fread();
    for(int i = 1;i <= m;i++) czk[i] = fread();
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            dis[i][j] = LONG_LONG_MAX;
        }
    }
    for(int i =1 ;i <= n;i++) dis[i][i] = 0;
    for(int i = 1;i <= n;i++)
    {
        int k = fread();
        for(int j = 1;j <= k;j++)
        {
            int k1 = fread(),k2 = fread();
            line[k1].push_back({i,k2});
        }
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = 0;j < line[i].size();j++)
        {
            for(int k = 0;k < j;k++)
            {
                dis[line[i][j].first][line[i][k].first] = dis[line[i][k].first][line[i][j].first] = min(dis[line[i][j].first][line[i][k].first],line[i][j].second+line[i][k].second);
            }
        }
    }
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            if(i == k) continue;
            for(int j = 1;j <= n;j++)
            {
                if(j == i || j == k) continue;
                dis[i][j] = dis[j][i] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        int l=fread(),r=fread();
        int ans = LONG_LONG_MAX;
        for(auto i : line[l])
        {
            for(int j = 0;j < line[r].size();j++)
            {
                pii k = line[r][j];
                ans = min(ans,k.second+i.second+dis[k.first][i.first]);
            }
        }
        fwrite(ans+czk[l]+czk[r]);
        putchar('\n');
    }
}