#include<bits/stdc++.h>
using namespace std;
int a[500005];
int nxt[500005];
int id[300005];
int vis[500005];
set<int> add[200005];
int ans[300005];

void dfs(int u,int n,int m)
{
    stack<int>st;
    int v = u;
    st.push(u);
    while(v<=n)
    {
        if(nxt[v])
        {
            v = nxt[v];
        }
        else v++;
        if(vis[v]||v>n)break;
        else st.push(v);
    }
    int las = v;
    while(!st.empty())
    {

        int now = st.top();
        vis[now] = 1;
        //cout  << "->"<< now << endl;
        st.pop();
        add[now] = add[las];
        add[now].insert(a[now]);
        las = now;
    }

    return;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
        nxt[id[a[i]]] = i;
        id[a[i]] = i;
    }
    for(int i = n;i>=1;i--)
    {
        dfs(i,n,m);
        for(auto u:add[i])ans[u]++;
       // cout << endl;
    }

    for(int i = 1;i<=m;i++)cout << ans[i] << " ";
    return 0;
}
