#include <bits/stdc++.h>
using namespace std;
int n,m,maxn;
int a[200005];
int b[200006];
int erjing(int n)
{
    int m;
    int wq=1;
    while(n!=0)
    {
        int gg=n%2;
        n=n/2;
        m=m*wq+gg;
        wq=wq*10;
    }
    return m;
}
int yhh(int x,int y)
{
    int m;
    int wq=1;
    while(x!=0||y!=0)
    {
        int ys1=x%10;
        int ys2=y%10;
        if(ys1==ys2)
        {
            m=m*wq+1;
        }
        else
        {
            m=m*wq+0;
        }
        wq=wq*10;
    }
    return m;
}
int sjz(int z)
{
    int wq=1;
    int guo=0;
    while(z!=0)
    {
        guo=guo+z%10*wq;
        z=z/10;
        wq*=2;
    }
    return guo;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    for(int i=1;i<n;i++)
    {
        int cnt1=erjing(a[i]);
        int cnt2=erjing(a[i+1]);
        int ss=yhh(cnt1,cnt2);
        maxn=max(maxn,ss);
    }
    cout<<sjz(maxn);
    return 0;
}
