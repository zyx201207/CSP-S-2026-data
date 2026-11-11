#include<bits/stdc++.h>
using namespace std;
struck aas;
{
    int x;
    bool vis;
}a[1000001];
int n.m;
int a[300001];
int b[300001];
int d[300001];
void an(int b)
{
    for(int i=b;i<=n;i++)
    {
        if(c[i]>=b)
        {
            f=i;
        }
    for(int i=1;i<=n;i++)
    {
        d[b[i]]++;
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(a[b[i]].vis)
        {
            c[i]=a[b[i]].x;
            a[b[i]].x=1;
        }
        a[b[i]].vis=1;
        a[b[i]].x=i;
    }
    for(int i=1;i<=n;i++)
    {
        an[i];
    }
    for(int i=1;i<=n;i++)
    {
        cout<<c[i]<<" ";
    }

    return 0;
}
