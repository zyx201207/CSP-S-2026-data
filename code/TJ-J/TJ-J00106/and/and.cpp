#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn=-1;
void f(int x,int y,int num)
{
    if(x==0)
    {
        maxn=max(maxn,num);
        return ;
    }
    if(y>n)return ;
    for(int i=y+1;i<=n-x+1;i++)
    {
        if(a[i]!=-1)
            f(x-1,i,num & a[i]);
        //cout << (num & a[i]) << '\n';
    }
    return ;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int k=1;
    for(int i=1;i<=31;i++) k*=2;
    k-=1;
    f(m,0,k);
    cout << maxn;
    return 0;
}
