#include<bits/stdc++.h>
using namespace std;
int a[100005],cnt[100005],b[100005];
bool f[100005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(b,0,sizeof(b));
        for(int j=i-1;j<=n;j++)
        {
            if(f[a[j]]) for(int k=f[a[j]];k<=j;k++) b[k]=0;
            else b[j]=a[j];
        }
        for(int k=1;k<=n;k++) cnt[b[k]]++;
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
}
