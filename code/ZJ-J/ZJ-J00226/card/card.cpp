#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e5+10;
int n,m;

struct ttt
{
    int tree[maxn];

    ttt()
    {
        for(int i=1;i<=n;++i) tree[i]=0;
    }

    int lb(int x)
    {
        return x&-x;
    }

    void upd(int x,int k)
    {
        while(x<=n)
        {
            tree[x]+=k;
            x+=lb(x);
        }
    }

    int qry(int x)
    {
        int res=0;
        while(x)
        {
            res+=tree[x];
            x^=lb(x);
        }
        return res;
    }
};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    vector<int> a(n+1);
    vector<vector<int>> pos(m+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        pos[a[i]].emplace_back(i);
    }

    vector<int> res(n+1),head(n+2);
    ttt cnt;
    int be=n;
    for(int i=1;i<=n;++i)
    {
        int l=pos[a[i]].back();
        cnt.upd(l,1);
        ++head[l];
        ++res[l];
        be=min(be,l);
    }

    for(int i=be+1;i<=n;++i)
    {
        int p=pos[a[i]].back();
        int ci=cnt.qry(i);
        res[i]-=ci-head[i];
        res[p]+=ci-head[i];
        cnt.upd(i,-(ci-head[i]));
        cnt.upd(p,ci-head[i]);
    }
    for(int i=1;i<=n;++i) res[i]+=res[i-1];

    vector<int> ans(m+1,-1);
    for(int i=n;i>=1;--i)
    {
        if(ans[a[i]]==-1) ans[a[i]]=res[i];
    }
    for(int i=1;i<=m;++i) cout<<ans[i]<<' ';

    return 0;
}