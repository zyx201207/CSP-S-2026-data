#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[5005],f[3005],s[3005],ans[3005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]]++;
        if(f[a[i]]>1)
        {
            for(int j=s[a[i]];j<=i;j++)
            {
                f[a[j]]--;
            }
        }
        if(f[a[i]]<=1)
        {
            s[a[i]]=i;
        }
        ans[a[i]]+=s[a[i]];
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
