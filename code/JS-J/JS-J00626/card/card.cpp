#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[300005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1]) flag=1;
    }
    if(flag==0)
    {
        for(int i=1;i<=n;i++)
        {
            b[a[i]]++;
        }
        for(int i=1;i<=m;i++)
        {
            b[i]=b[i-1]+b[i];
        }
        for(int i=1;i<=m;i++)
        {
            cout<<b[i]<<" ";
        }
        return 0;
    }
}
