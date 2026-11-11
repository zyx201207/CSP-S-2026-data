#include<bits/stdc++.h>
using namespace std;
int n,m,b[500010],c[500010],a[500010],n1;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    n1=n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int l=1;l<=n1;l++){
        for(int i=1;i<=n;i++){
        c[i]=a[i];
        for(int j=1;j<i;j++)if(c[j]==a[i])for(int k=j;k<i;k++)c[k]=0;
    }
    for(int i=1;i<=n;i++)b[c[i]]++;
    n--;
    for(int i=1;i<=n;i++)a[i]=a[i+1];
    for(int i=1;i<=n+1;i++)c[n]=0;
    }
    for(int i=1;i<=m;i++)cout<<b[i]<<" ";
    return 0;
}
