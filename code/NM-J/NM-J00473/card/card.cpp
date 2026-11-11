#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
stack<int>st;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)  cin>>a[i];
    int anss=1,cnt=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==a[i-1])  anss++;
        if (a[i]!=a[i+1])
        {
            ans[++cnt]=anss;
            anss++;
        }
    }
    for (int i=1;i<=m;i++)  cout<<ans[i]<<" ";
    return 0;
}
