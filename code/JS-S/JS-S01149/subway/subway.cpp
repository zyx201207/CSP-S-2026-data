#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f[50005],p,q=0,i,j;
struct node{
    long long h,l;
}g[505];
struct nnode{
    long long n,o;
}m[100005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>a>>b>>c>>d>>e;
    for(i=1;i<=c;i++)
    {
        cin>>f[i];
        q=q+f[i];
    }
    for(i=1;i<=b;i++)
    {
        cin>>p;
        for(j=1;j<=p;j++)
        {
            cin>>g[i].h>>g[i].l;
        }
    }
    for(i=1;i<=e;i++)
    {
        cin>>m[i].n>>m[i].o;
    }
    for(i=1;i<=e;i++)
    {
        cout<<q<<endl;
    }
    return 0;
}
