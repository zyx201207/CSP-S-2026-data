#include <bits/stdc++.h>
#define ls(x) (x * 2)
#define rs(x) (x * 2 + 1)
#define ll long long

using namespace std;

const int N = 5e5 + 5;
ll a[N];
int ans[N],prv[N];

map<ll,int> mp;

struct {
    ll sum,tag;
} tree[4 * N];

ll tmp[N];

inline void push_up(int p)
{
    tree[p].sum = tree[ls(p)].sum + tree[rs(p)].sum;
}

void build(int p,int pl,int pr)
{
    if(pl == pr)
    {
        tree[p].sum = tmp[pl];
        tree[p].tag = 0;
        return ;
    }
    int mid = (pl + pr) / 2;
    build(ls(p),pl,mid);
    build(rs(p),mid + 1,pr);
    push_up(p);
}

inline void add_tag(int p,int pl,int pr,ll d)
{
    tree[p].tag += d;
    tree[p].sum += d * (1ll * (pr - pl + 1));
}

inline void push_down(int p,int pl,int pr)
{
    if(tree[p].tag)
    {
        int mid = (pl + pr) / 2;
        add_tag(ls(p),pl,mid,tree[p].tag);
        add_tag(rs(p),mid + 1,pr,tree[p].tag);
        tree[p].tag = 0;
    }
}

void update_dot(int p,int pl,int pr,int pos,ll d)
{
    if(pl == pr)
    {
        tree[p].sum = d;
        return ;
    }
    push_down(p,pl,pr);
    int mid = (pl + pr) / 2;
    if(pos <= mid) update_dot(ls(p),pl,mid,pos,d);
    else update_dot(rs(p),mid + 1,pr,pos,d);
    push_up(p);
}

void update(int p,int pl,int pr,int L,int R,ll d)
{
    if(L <= pl && pr <= R)
    {
        add_tag(p,pl,pr,d);
        return ;
    }
    push_down(p,pl,pr);
    int mid = (pl + pr) / 2;
    if(L <= mid) update(ls(p),pl,mid,L,R,d);
    if(R > mid) update(rs(p),mid + 1,pr,L,R,d);
    push_up(p);
}

ll query_sum(int p,int pl,int pr,int L,int R)
{
    if(L <= pl && pr <= R) return tree[p].sum;
    push_down(p,pl,pr);
    int mid = (pl + pr) / 2;
    ll res = 0;
    if(L <= mid) res += query_sum(ls(p),pl,mid,L,R);
    if(R > mid) res += query_sum(rs(p),mid + 1,pr,L,R);
    return res;
}

int query(int p,int pl,int pr,ll s)
{
    if(pl == pr) return pl;
    push_down(p,pl,pr);
    ll lsum = tree[ls(p)].sum;
    int mid = (pl + pr) / 2;
    if(lsum > s) return query(ls(p),pl,mid,s);
    else return query(rs(p),mid + 1,pr,s - lsum);
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]] ++;
    }
    sort(a + 1,a + n + 1);
    int p = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == a[i - 1]) prv[i] = prv[i - 1];
        else prv[i] = i - 1;
    }
    n ++;
    for(int i = n - 1; i >= 1; i--)
        tmp[i] = a[n - 1] - a[i];
    tmp[n] = 1e18 + 1;
    sort(tmp + 1,tmp + n + 1);
    build(1,1,n);
    ll cnt = 0,lst = 1e18 + 1,lst_cnt = 0;
    for(int i = n - 1; i >= 1; i--)
    {
        if(a[i] == lst) continue;
        /*for(int j = 1; j < n; j++) cerr << query_sum(1,1,n,j,j) << " ";
        cerr << endl;
        cerr << "lst_cnt: " << lst_cnt << endl;*/
        ans[i] = query(1,1,n,m) -1 - lst_cnt;
        for(int j = 1; j <= mp[a[i]]; j++)
        {
            cnt ++;
            if(cnt <= n) update_dot(1,1,n,cnt,0);
        }
        lst_cnt = cnt;
        //cerr << cnt << endl;
        if(cnt + 1 <= n - 1) update(1,1,n,cnt + 1,n - 1,a[prv[i]] - a[i]);
        lst = a[i];
    }
    cout << *max_element(ans + 1,ans + n) << endl;
    return 0;
}
/*
13 5
-2 -2 -2 -2 -1 -1 -1 -1 -1 0 0 0 0
*/