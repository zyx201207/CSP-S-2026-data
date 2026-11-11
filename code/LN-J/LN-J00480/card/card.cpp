#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],las[maxn],l[maxn],t[maxn],ans[maxn];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        t[i]=1;
        cin>>a[i];
        l[i]=las[a[i]];
        las[a[i]]=i;
        for(int j=l[i]+1;j<i;j++)
        {
            t[j]=max(t[j],l[i]+1);
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans[a[i]]=max(ans[a[i]],i-t[i]+1);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
