#include <bits/stdc++.h>
using namespace std;
vector<pair<int , int> > a[500010];
int k[510];
int ti[500010];
vector<pair<int , int> > g[510];
vector<int> t[510];
vector<int> j[510];
set<int> s;
struct node{
    int dis , n;
};
bool vis[510];
int bfs(int s , int f)
{
    memset(vis , 0 , sizeof vis);
    queue<node> q;
    for(auto &&c : a[s])
    {
        q.push({0 , c.first});
        vis[c.first] = true;
    }
    unordered_set<int> st;
    for (auto &&c : a[f])
    {
        st.insert(c.first);
    }
    int minn = 0x3f3f3f3f;
    while (!q.empty())
    {
        node t1 = q.front();
        q.pop();
        vis[t1.n] = 1;
        if (st.count(t1.n)) minn = min(minn , t1.dis);
        int pos = 0;
        for (auto &&c : g[t1.n])
            if (c.first == t1.n)
            {
                pos = t[t1.n][c.second - 1];
                break;
            }
        for (auto &&c : g[t1.n])
        {
            if (c.first != t1.n && !vis[c.first])
            {
                q.push({t1.dis + pos + t[c.first][c.second - 1] , c.first});
            }
        }
    }
    return minn;
}
int main()
{
//    freopen("subway.in" , "r" , stdin);
//    freopen("subway.out" , "w" , stdout);
    int c , n , m , d , q;
    scanf("%d%d%d%d%d" , &c , &n , &m , &d , &q);
    for (int i = 1 ;i <= m ; i++)
    {
        scanf("%d" , &ti[i]);
    }
    for (int i = 1 ; i <= n ; i++)
    {
        scanf("%d" , &k[i]);
        for (int z = 1 ; z <= k[i] ; z++)
        {
            int x , y;
            scanf("%d%d" , &x , &y);
            j[i].push_back(x);
            t[i].push_back(y);
            a[x].push_back({i , z});
            s.insert(x);
        }
    }
    for(auto &&c : s)
    {
        for (auto &&p : a[c])
        {
            g[p.first] = a[c];
        }
    }
    while(q--)
    {
        int x , y;
        scanf("%d%d" , &x , &y);
        printf("%d\n" , ti[x] + ti[y] + bfs(x , y));
    }
    return 0;
}
