#include <bits/stdc++.h>
using namespace std;
int w[500005];
int k[505];
vector<int> a[505];
vector<int> a1[500005];
int c,n,m,d,q;
bool v[500005];
struct S
{
    int x,di;
};
int ti;
int bfs(int s,int e)
{
    memset(v,0,sizeof(v));
    queue<S> q;
    q.push({S,0});
    v[s] = 1;
    while (!q.empty())
    {
        S b = q.front();
        q.pop();
        if (b.x==e)
        {
            return b.di*ti+w[s]+w[e];
        }
        for (int i = 0;i<a1[b.x].size();i++)
        {
            for (int j = 0;j<a[a1[b.x][i]].size();j++)
            {
                if (!v[a[a1[b.x][i]][j]])
                {
                    v[a[a1[b.x][i]][j]] = 1;
                    q.push(a[a1[b.x][i]][j]);
                }
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i<=m;i++)
    {
        cin >> w[i];
    }
    for (int i = 1;i<=n;i++)
    {
        cin >> k[i];
        a.push_back(0);
        for (int j = 1;j<=k[i];j++)
        {
            int ai;
            cin >> ai >> ti;
            a[j].push_back(ai);
            a1[ai].push_back(j);
        }
    }

    while (q--)
    {
        int s,e;
        cin >> s >> e;
        cout << bfs(s,e) << "\n";
    }
    return 0;
}
