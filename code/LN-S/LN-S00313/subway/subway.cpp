
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
ll c,n,m,d,q;
const int op=5e5+5;
ll w[op],a[op],t[op],k[op];
struct node
{

    ll next;
    ll b;
    ll p;
};
ll x,y;
 vector<node>tree[2*op];
void build(int shen)
{
    if(shen==m+1)
        return;
    for(int u=1;u<=n+m;u++)
    for(auto v:tree[u])
    {
        auto [a,b,c]=v;
        for(int lk=0;lk<tree[a].size();lk++)
        {
            if(a!=u&&c==shen)
        {
            node ol;ol.next=tree[a][tree[a][lk].next].next,ol.b=tree[a][tree[a][lk].next].b+b,ol.p=++c;
            tree[u].push_back(ol);
        }
        }


    }
    build(shen+1);
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int p=1;p<=n;p++)
    {

        cin>>k[p];
        for(int i=1;i<=2*k[p];i++)
        {
        for(int i=1;i<=2*k[p];i++)
            if(i/2)
            {
                cin>>a[i];

            }

            else
            {
                cin>>t[i];
                tree[p+m].push_back({a[i],t[i],1});
                tree[a[i]].push_back({p+m,t[i],1});
            }

        }
    }
    build(1);
    for(int i=1;i<=q;i++)
    {

        cin>>x>>y;
        ll cnt=-3e9;
        for(auto v:tree[x])
        {
            if(v.next==y)
                cnt=min(cnt,v.b);
            cout<<v.next<<' '<<v.p;

        }
        cout<<cnt+w[x]+w[y]<<endl;
    }

    return 0;
}
