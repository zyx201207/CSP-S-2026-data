#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
    long long a;
    int l;
}p[200001];
long long mi[32];
bool cmp(node an,node bn)
{
    return an.a>bn.a;
}
int main()
{
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
    mi[1]=1;
    for(int i=2;i<=31;i++)
    {
        mi[i]=mi[i-1]*2+1;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].a;
        p[i].l=log2(p[i].a)+1;
    }
     sort(p+1,p+n+1,cmp);
    while(p[1].l!=p[m].l)
    {
        int num=p[m].l;
        for(int i=1;i<=m;i++)
        {
            int x=p[i].l-num;
            p[i].a-=(mi[p[i].l]-mi[num]);
            p[i].l=log2(p[i].a)+1;
        }
        sort(p+1,p+n+1,cmp);
    }
    long long ans=p[1].a;
    for(int i=2;i<=m;i++)
    {
        ans&=p[i].a;
    }
    cout<<ans;
    return 0;
}
