#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int b,f,id;
}b[200005];
int cmp(node a,node b)
{
    if(a.f>b.f)
    {
        return a.f>b.f;
    }
    else if(a.f==b.f)
    {
        return a.b<b.b;
    }
    else
    {
        return a.f<b.f;
    }
}
unsigned long long s=0,zd=LLONG_MIN,l=1073741824,t;
int a[200005];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        l=1073741824;
        b[i].b=a[i];
        b[i].id=i;
        for(int j=1;j<=30;j++)
        {
            if(b[i].b>=l)
            {
                b[i].f++;
                b[i].b-=l;
            }
            l/=2;
        }
    }
    sort(b+1,b+n+1,cmp);
    reverse(b+1,b+n+1);
    s=a[b[1].id];
    for(int i=2;i<=m;i++)
    {
        s&=a[b[i].id];
    }
    cout<<s;
    return 0;
}
/*
1 2 4 8 16 32 64

11111 31           5
   11 3            2
    1 1            1
 1111 15           4
  111 7            3

-----------------

  11 3             2
1111 15            4
1100 12            2
1100 12            2

-----------------

10101 21           3
11111 31           5
  110 6            2
  111 7            3
   11 3            2
*/
