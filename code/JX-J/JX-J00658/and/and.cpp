#include <bits/stdc++.h>
using namespace std;
int n,m,a[200001],maxx=-1;
int main()
{
    freopen("and.in","r",stdin);
    freoren("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    cout<<maxx;
    return 0;
}
