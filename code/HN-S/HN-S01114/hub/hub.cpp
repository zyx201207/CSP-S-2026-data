#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e6 + 5;
int T,id;
int n,k,a[N],b[N],in[N],f[N],U[N],V[N],maxx,vis[N],dep[N];
int gt1[N],gt2[N],hu[N];
vector<int>ve[N];
bool check(int mi)
{
    return 4 * (mi - 1) + k >= n;
}
int find(int x)
{
    if(f[x] == x)return x;
    return f[x] = find(f[x]);
}
int dfs_(int x)
{
    vis[x] = 1;
    if(in[x])return 0;
    int mn = 1e9;
    for(int i = 0;i < ve[x].size();i ++)
        if(!vis[ve[x][i]])mn = min(mn,dfs_(ve[x][i]) + 1);
    return mn;
}
void dfs(int x,int su)
{
    if(x > n)
    {
        if(su < k)return ;
        for(int i = 1;i <= n;i ++)f[i] = i;
        int tot = su;
        for(int i = 1;i < n;i ++)
        {
            if(!in[U[i]] || !in[V[i]])continue ;
            int w1 = find(U[i]),w2 = find(V[i]);
            if(w1 != w2)tot --,f[w1] = w2;
        }
        if(tot > 2)return ;
        int dw = 0;
        for(int i = 1;i <= n;i ++)
        {
            for(int j = 1;j <= n;j ++)vis[j] = 0;
            dw = max(dw,dfs_(i));
        }
        maxx = min(maxx,dw);
        return ;
    }
    if(su < k)
    {
        in[x] = 1;
        dfs(x + 1,su + 1);
    }
    in[x] = 0;
    dfs(x + 1,su);
}
int dfs2(int x,int fa,int mi,int ban1)
{
    dep[x] = 0;
    int ds = gt1[x] > mi;
    for(int i = 0;i < ve[x].size();i ++)
    {
        if(ve[x][i] == fa || ve[x][i] == ban1)continue ;
        int tt = dfs2(ve[x][i],x,mi,ban1);
        if(tt)return tt;
        dep[x] = max(dep[x],dep[ve[x][i]] + 1);
        if(ban1)ds |= hu[ve[x][i]];
    }
    hu[x] = ds;
    if(dep[x] >= mi && (!ban1 || hu[x]))return x;
    return 0;
}
void dfs3(int x,int fa,int ju,int opt)
{
    if(!opt)gt1[x] = ju;
    else gt2[x] = ju;
    for(int i = 0;i < ve[x].size();i ++)
    {
        if(ve[x][i] == fa)continue ;
        dfs3(ve[x][i],x,ju + 1,opt);
    }
}
bool checks(int mi)
{   //return true;
    int jie = dfs2(1,0,mi,0);
    if(jie == 0 || jie == 1)return true;
    dfs3(jie,0,0,0);
    for(int i = 1;i <= n;i ++)hu[i] = 0;
    int jie2 = dfs2(1,0,mi,jie);
    if(jie2 == 0)return true;
    dfs3(jie2,0,0,1);
    for(int i = 1;i <= n;i ++)
        if(min(gt1[i],gt2[i]) > mi)
        {
            //cout << gt1[i] << " " << gt2[i] << " ohno.\n";
            return false;
        }
    return true;
}
void solve()
{
    maxx = 1e9;
    cin >> n >> k;
    for(int i = 1;i <= n;i ++)ve[i].clear();
    for(int i = 1,u,v;i < n;i ++)
    {
        cin >> u >> v;U[i] = u,V[i] = v;
        ve[u].push_back(v),ve[v].push_back(u);
    }
    if(id >= 13 && id <= 14)
    {
        if(n == k)
        {
            cout << "0\n";
            return ;
        }
        n /= 2;
        if(k >= n)
        {
            cout << "1\n";
            return ;
        }
        int L = 1,R = n;
        while(L < R)
        {
            int mid = (L + R) >> 1;
            if(check(mid))R = mid;
            else L = mid + 1;
        }
        cout << L << '\n';
        return ;
    }
    if(id == 7 || (11 <= id && id <= 12))
    {
        int L = 0,R = n;
        while(L < R)
        {
            int mid = (L + R) >> 1;
            //cout << mid << '\n';
            if(checks(mid))R = mid;
            else L = mid + 1;
        }
        cout << L << '\n';
        return ;
    }
    if(id <= 3)
    {
        dfs(1,0);
        cout << maxx << '\n';
        return ;
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> id >> T;
    while(T --)solve();
}
/*
17:08 case13~14 10pts
17:39 case1~3 15pts
expected:25pts
*/
