#include<bits/stdc++.h>
using namespace std;
#define inf 0x37373737
const int N=2e5+5;
int n;
long long s[N],t,an;
int a[N];
char c[N];
struct node{
    int l;char c;
};
stack<node> q,k;

int ini()
{
    int l=0,r=n;
    int mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(s[mid-1]<=t&&s[mid]>=t)
        {
            return mid;
        }
        else
        {
            if(s[mid]<=t)
            {
                l=mid+1;
            }
            if(s[mid-1]>=t)
            {
                r=mid-1;
            }
        }
    }
    return mid;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        s[i]=s[i-1]+a[i];
    }
    t=s[n]/2;
    if(t*2<s[n])
    {
        t++;
    }
    int u=ini();
    q.push({(int)(a[u]-(s[u]-t)),c[u]});
    k.push({(int)(s[u]-t),c[u]});
    if(t%2)
    {
        q.pop();
        if((a[u]-(s[u]-t))-1>0) q.push({(int)(a[u]-(s[u]-t))-1,c[u]});
    }
    for(int i=u-1;i>=1;i--)
    {
        q.push({a[i],c[i]});
    }
    for(int i=u+1;i<=n;i++)
    {
        k.push({a[i],c[i]});
    }
    while (!q.empty())
    {
        auto o=q.top();
        auto p=k.top();
        q.pop();
        k.pop();
        if((o.c!=p.c))
        {
                an+=min(o.l,p.l);
        }
        if(o.l>p.l)
        {
            q.push({o.l-p.l,o.c});
        }
        else
        {
            if(o.l<p.l)
            {
                k.push({p.l-o.l,p.c});
            }
        }
    }
    cout<<an<<'\n';
    return 0;
}