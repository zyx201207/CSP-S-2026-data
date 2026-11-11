#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005],b[500005],ans[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]==a[j])
            {
                b[i]=j;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(b[j]!=0)
            {
                c[j]--;
                c[b[j]]++;
                j=b[j];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        c[i]=c[i-1]+c[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans[a[i]]+=i;
        ans[a[i]]+=c[i];
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}