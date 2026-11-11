#include<bits/stdc++.h>
using namespace std;
struct node
{
    int p;
    int v;
}a[200005];
int cnt[35];
int lowbit(int x)
{
    return x&(-x);
}
bool cmp(node x,node y)
{
    return x.p>y.p;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1)
    {
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].v;
            mx=max(mx,a[i].v);
        }
        cout<<mx;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].v;
        a[i].p=lowbit(a[i].v);
    }
    sort(a+1,a+n+1,cmp);
    long long ans=a[1].v;
    for(int i=2;i<=m;i++)
    {
        ans&=a[i].v;
    }
    cout<<ans;
    return 0;
}
