#include<iostream>
#include<vector>
#define AK return
#define CSP 0;
using namespace std;
int a[500005],p[300005],s[300005],fa[500005],sz[500005];
vector<int> t[500005];
void dfs(int u)
{
    sz[u] = 1;
    for(auto &i : t[u])
    {
        dfs(i);
        sz[u] += sz[i];
    }
    s[a[u]] += sz[u];
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
    //freopen//freopen//freopen//freopen//fuckccf//freopen//freopen//freopen//freopen
    //freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = n;i >= 1;i--)
    {
        if(p[a[i]] == 0)
        {
            p[a[i]] = i;
            fa[i] = i+1;
        }
        else
        {
            fa[i] = p[a[i]]+1;
        }
        t[fa[i]].push_back(i);
    }
    dfs(n+1);
    for(int i = 1;i <= m;i++)
    {
        cout << s[i] << ' ';
    }
    AK CSP
}
