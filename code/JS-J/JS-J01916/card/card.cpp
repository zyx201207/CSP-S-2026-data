#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],nex[300005],s[300005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>=1;i--)
    {
        nex[i]=max(s[a[i]],i+1);
        s[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        memset(s,0,sizeof(s));
        for(int j=i;j<=n;j=nex[j])
        {
            ans[a[j]]+=1-s[a[j]];
            s[a[j]]=1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
