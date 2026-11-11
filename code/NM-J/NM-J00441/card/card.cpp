#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int c[300005];
int n,m;
void init(int p)
{
    b[p]++;
    if (c[p]==n) return ;
    init(a[c[p]+1]);

}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=n;i>=1;i--)
    {
        if (c[a[i]]==0)
        {
            c[a[i]]=i;
        }
    }
    for (int i=1;i<=n;i++)
    {
        init(a[i]);
    }
    for (int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
