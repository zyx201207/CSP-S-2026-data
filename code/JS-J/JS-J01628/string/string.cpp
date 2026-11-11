#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,char> >a,b,c;
int d[400005];
char f[400005],g[400005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int q,w,r=0,t=0,y=2,u=0,o=0,p=0,s=0;
    char e;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>w>>e;
        a.push_back(make_pair(w,e));
        r+=w;
    }
    r/=2;
    for(int i=0;i<q;i++)
    {
        if(t>=r)break;
        if(t+a[i].first>=r)
        {
            b.push_back(make_pair(r-t,a[i].second));
            break;
        }
        b.push_back(a[i]);
        t+=a[i].first;
    }
    t=0;
    for(int i=q-1;i>=0;i--)
    {
        if(t>=r)break;
        if(t+a[i].first>=r)
        {
            c.push_back(make_pair(r-t,a[i].second));
            break;
        }
        c.push_back(a[i]);
        t+=a[i].first;
    }
    for(int i=0;i<b.size();i++)
    {
        u+=b[i].first;
        d[y]=u;
        b[i].first=u;
        y++;
    }
    u=0;
    for(int i=0;i<c.size();i++)
    {
        u+=c[i].first;
        d[y]=u;
        c[i].first=u;
        y++;
    }
    d[y]=r;
    sort(d+1,d+y+1);
    for(int i=2;i<=y;i++)
    {
        if(b[o].first>=d[i])f[i-1]=b[o].second;
        else
        {
            o++;
            f[i-1]=b[o].second;
        }
        if(c[p].first>=d[i])g[i-1]=c[p].second;
        else
        {
            p++;
            g[i-1]=c[p].second;
        }
    }
    for(int i=1;i<=y-1;i++)if(f[i]!=g[i])s+=d[i+1]-d[i];
    cout<<s;
}
