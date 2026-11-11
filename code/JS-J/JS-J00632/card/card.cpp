#include <bits/stdc++.h>
using namespace std;
int a[10000008],ans[10000008],b[10000008];
vector<int> u;
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
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++)
        {
            if(b[a[j]]!=0) memset(b,0,sizeof(b));
            else b[a[j]]=1;
        }
        for(int j=1;j<=m;j++)
        {
            if(b[j]!=0) ans[j]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
