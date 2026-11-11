#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m;
int a[100001];
int b[100001];
int c[100001];
int e[100001];
struct abc{
    int x;
    bool vis;
}d[100001];
void mn(int x){
    for(int i=x;i<=n;i++)
    {
        if(e[i]==a[i])
        {
            int xx=-a[i];
            while(e[i]!=xx)
                i++;
        }
        b[a[i]]++;
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(d[a[i]].vis)
        {
            e[d[a[i]].x]=a[i];
            e[i]=-a[i];
            c[i]=d[a[i]].x;
        }
        d[a[i]].x=i;
        d[a[i]].vis=1;
    }
    for(int i=1;i<=n;i++)
        mn(i);
    for(int i=1;i<=m;i++)
        cout<<b[i]<<' ';
    return 0;
}
