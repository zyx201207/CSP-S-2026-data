#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005][32],c[200005][32],d[32];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=30;i>=0;i--)
        for(int j=1;j<=n;j++)
            if((a[j]&(1LL<<i))!=0)
                b[j][i]=1;
    for(int j=1;j<=n;j++)
        c[j][31]=1;
    for(int i=30;i>=0;i--)
    {
        for(int j=1;j<=n;j++)
            if(b[j][i]==1 and c[j][i+1]==1)
                c[j][i]=1;
        int f=0;
        for(int j=1;j<=n;j++)
            if(c[j][i]==1)
                f++;
        if(f>=m)
            d[i]=1;
        else
            for(int j=1;j<=n;j++)
                if(c[j][i+1]==1)
                    c[j][i]=1;
    }
    for(int i=30;i>=0;i--)
        ans+=d[i]*(1LL<<i);
    cout<<ans;
    return 0;
}
