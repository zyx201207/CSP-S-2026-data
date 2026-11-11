#include <bits/stdc++.h>
using namespace std;
int n,m,t;
int a[10000],c[4000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        c[a[i]]++;
    }
    if(m==1) cout<<n;
    c[a[n-1]]=n;
    for(int i=1;i<=m;i++)
    {
        cout<<c[i]<<" ";
    }


    return 0;
}
