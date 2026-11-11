#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
ll c;
ll n, d;
ll x[N];
bool vis[15];
vector<int> g[15];
vector<int> answ;
void read(ll &x)
{
    x = 0;
    int flag = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
        {
            flag = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch - 48);
        ch = getchar();
    }
    x *= flag;
}
void write(ll x)
{
    int top = 0;
    static int sta[40] = {0};
    if(x < 0)
    {
        putchar('-');
        x = -x;
    }
    do
    {
        sta[++top] = x % 10;
        x /= 10;
    }
    while(x);
    while(top)
    {
        putchar(sta[top--] + 48);
    }
    putchar('\n');
}
void dfs(int u, int v)
{
    for(int i = 0; i <= 13;++i)
    {
        vis[i] = 0;
    }
    stack<pair<int, int> > sta;
    sta.push({u, 0});
    vis[u] = 1;
    while(sta.size())
    {
        pair<int, int> fr = sta.top();
        sta.pop();
        //vis[fr.first] = 0;
        for(int to : g[fr.first])
        {
            if(to == v)
            {
                continue;
            }
            if(!vis[to])
            {
                sta.push({to, fr.second + 1});
                vis[to] = 1;
            }
        }
        for(int to : g[fr.first])
        {
            if(to == v)
            {
                answ.push_back(fr.second + 1);
                break;
            }
        }
    }
}
bool check(int u, int v)
{
    int flag = 0;
    vector<int>().swap(answ);
    for(int i = 0;i <= 13;++i)
    {
        vector<int>().swap(g[i]);
    }
    for(int i = u; i <= v;++i)
    {
        for(int j = u + 1;j <= v;++j)
        {
            if(x[i] + d >= x[j])
            {
                g[i].push_back(j);
            }
        }
    }
    dfs(u, v);
    sort(answ.begin(), answ.end());
    if(answ.size() >= 2)
    {
        int countaa = 1;
        int len = answ.size();
        for(int i = 1;i < len;++i)
        {
            if(answ[i] == answ[0])
            {
                ++countaa;
            }
        }
        return (countaa == 2);
    }
    return 0;
}
void solveBL()
{
    read(n);read(d);
    for(int i = 1;i <= n;++i)
    {
        read(x[i]);
    }
    ll ans = 0;
    for(int u = 1;u <= n;++u)
    {
        for(int v = u + 2; v <= n;++v)
        {
            if(check(u, v))
            {
                ++ans;
            }
        }
    }
    write(ans);
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ll t = 0;
    read(c);
    read(t);
    while(t--)
    {
        solveBL();
    }
    return 0;
}
